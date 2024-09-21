#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} NODE;
NODE *createnode(int data)
{
    NODE *nn = (NODE *)malloc(sizeof(NODE));
    nn->data = data;
    nn->left = NULL;
    nn->right = NULL;
    return nn;
}
int isempty(NODE *t)
{
    return (t == NULL);
}
NODE *insertData(NODE *root, int data)
{
    if (isempty(root))
    {
        root = createnode(data);
    }
    else if (data <= root->data)
    {
        root->left = insertData(root->left, data);
    }
    else
    {
        root->right = insertData(root->right, data);
    }
    return root;
}
void searchElement(NODE **t, int data, NODE **parent)
{
    while (!isempty(*t) && data != (*t)->data)
    {
        *parent = *t;
        if (data <= (*t)->data)
            *t = (*t)->left;
        else
        {
            *t = (*t)->right;
        }
    }
}
NODE *inordersuccessor(NODE *t)
{
    NODE *s;
    if (t->right != NULL)
        s = t->right;
    while (s->left != NULL)
        s = s->left;
    return s;
}
NODE *deletenode(NODE *root, int data)
{
    NODE *parent = NULL, *t = root;
    if (t->data == data) // Root element
        parent = NULL;
    else
        searchElement(&t, data, &parent);
    if (t == NULL)
    {
        printf("Element not found");
        return root;
    }
    // case 1: Leaf Node
    if (t->left == NULL && t->right == NULL)
    {
        if (parent == NULL)
            root = NULL;
        else
        {
            if (parent->left == t)
            { // left child
                parent->left = NULL;
            }
            else if (parent->right == t)
            { // right child
                parent->right = NULL;
            }
        }
        free(t);
    }
    // Case 2: One child
    else if (t->left == NULL || t->right == NULL)
    {
        if (parent == NULL)
        { // root node with one child
            if (t->left == NULL)
            { // t is right child
                root = root->right;
                t->right = NULL;
                free(t);
            }
            else
            { // t is left child
                root = root->left;
                t->left = NULL;
                free(t);
            }
        }
        else
        {
            if (parent->left == t)
            { // left child
                if (t->left == NULL)
                {
                    parent->left = t->right;
                }
                else
                {
                    parent->left = t->left;
                }
            }
            else if (parent->right == t)
            { // right child
                if (t->left == NULL)
                {
                    parent->right = t->right;
                }
                else
                {
                    parent->right = t->left;
                }
            }
            free(t);
        }
    }
    // case 3: two children
    else
    {
        int val;
        NODE *s;
        s = inordersuccessor(t);
        val = s->data;
        root = deletenode(root, s->data);
        t->data = val;
    }
    return root;
}
void preorder(NODE *t1)
{
    if (isempty(t1))
        printf("\nEmpty tree");
    else
    {
        printf("%d ", t1->data);
        if (t1->left != NULL)
            preorder(t1->left);
        if (t1->right != NULL)
            preorder(t1->right);
    }
}
void inorder(NODE *t1)
{
    if (isempty(t1))
        printf("\nEmpty tree");
    else
    {
        if (t1->left != NULL)
            inorder(t1->left);
        printf("%d ", t1->data);
        if (t1->right != NULL)
            inorder(t1->right);
    }
}
void postorder(NODE *t1)
{
    if (isempty(t1))
        printf("\nEmpty tree");
    else
    {
        if (t1->left != NULL)
            postorder(t1->left);
        if (t1->right != NULL)
            postorder(t1->right);
        printf("%d ", t1->data);
    }
}
int main()
{
    int data, n;
    NODE *root = NULL;
    printf("Enter the no of nodes in the tree");
    scanf("%d", &n);
    printf("Enter the data ");
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &data);
        root = insertData(root, data);
    }
    inorder(root);
    printf("\n");
    preorder(root);
    printf("\n");
    postorder(root);
    printf("\n");
    root = deletenode(root, 5);
    inorder(root);
    return 0;
}
