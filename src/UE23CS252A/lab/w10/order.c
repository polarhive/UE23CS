#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define MAX 20

typedef struct node
{
    int info;
    struct node* left;
    struct node* right;
}NODE;

typedef struct tree
{
	NODE* root;
}TREE;

//Initializes the Binary Search Tree to be empty
void initTree(TREE* pt);
//Creates Binary Search Tree
void constructTree(TREE* pt, int ele);
//Prints the Binary Search tree in level order (implement this function below)
void levelOrder(TREE* pt);
// Destroys all nodes in a Binary search tree and sets root = NULL
void destroyTree(TREE* pt);

int main()
{
    TREE tobj;
	initTree(&tobj);
	
    int n;
    int ele;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &ele);
        constructTree(&tobj, ele);
    }
	
    levelOrder(&tobj);
	
    destroyTree(&tobj);
    
    return 0;
}

void initTree(TREE* pt)
{
	pt->root = NULL;
}

void enqueue(NODE** queue, NODE* ele, int* f, int* r)
{
    if(*r == (MAX-1))
    {
        printf("Queue is full");
        exit(0);
    }
    if(*f == -1 && *r == -1)
    {
        *f = *f + 1;
        *r = *r + 1;
        queue[*f] = ele;
    }
    else
    {
        *r = *r + 1;
        queue[*r] = ele;
    }
}

NODE* dequeue(NODE** queue, int* f, int* r)
{
	NODE* ele;
    
	if(*f == -1 && *r == -1)
    {
        printf("Queue is empty");
        exit(0);
    }
    if(*f == *r)
    {
        ele = queue[*f];
        *f = -1;
        *r = -1;
    }
    else
    {
        ele = queue[*f];
        *f = *f + 1;
    }
    return ele;
}

int isEmpty(NODE** queue, int* f, int* r)
{
    if(*f == -1 && *r == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void levelOrder(TREE* pt)
{
    if (pt->root == NULL) {
        return;
    }

    NODE* queue[MAX];
    int f = -1, r = -1;

    enqueue(queue, pt->root, &f, &r);

    while (!isEmpty(queue, &f, &r)) {
        NODE* current = dequeue(queue, &f, &r);
        
        printf("%d ", current->info);
        
        if (current->left != NULL) {
            enqueue(queue, current->left, &f, &r);
        }
        
        if (current->right != NULL) {
            enqueue(queue, current->right, &f, &r);
        }
    }
}


void constructTree(TREE* pt, int ele)
{
    NODE* node = (NODE*)malloc(sizeof(NODE));
    node->info = ele;
    node->left = NULL;
    node->right = NULL;
	
    if(pt->root == NULL)
    {
        pt->root = node;
    }
    else
    {
        NODE* p = pt->root;
        NODE* q = NULL;
        while(p != NULL)
        {
            if(node->info < p->info)
            {
                q = p;
                p = p->left;
            }
            else
            {
                q = p;
                p = p->right;
            }
        }
        if(node->info < q->info)
        {
            q->left = node;
        }
        else
        {
            q->right = node;
        }
    }
}

NODE* destroyNode(NODE* root) 
{
    if (root != NULL) 
    {
        root->left = destroyNode(root->left);
        root->right = destroyNode(root->right);
        free(root);
    }
	return NULL;
}

void destroyTree(TREE* pt)
{
	if(pt->root != NULL)
		pt->root = destroyNode(pt->root);
}
