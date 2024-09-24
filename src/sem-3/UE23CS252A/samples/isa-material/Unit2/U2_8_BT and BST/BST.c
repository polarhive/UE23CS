//program to implement a binary search tree
#include<stdio.h>
#include<stdlib.h>
struct tnode
{
  int data;
  struct tnode *left;
  struct tnode *right;
};
typedef struct tnode tnode_t;

struct tree
{
	tnode_t *root;
};
typedef struct tree tree_t;

void init(tree_t*);
void inorder_t(tree_t*);
void inorder(tnode_t*);
void preorder(tnode_t*);
void preorder_t(tree_t *);
void postorder(tnode_t*);
void postorder_t(tree_t*);
void insert( tree_t *,int);
int count_t(tree_t *);
int count(tnode_t*);
int leafcount_t(tree_t *);
int leafcount(tnode_t*);
int height(tnode_t*);
int height_t(tree_t*);
void rinsert_t(tree_t*, int);
tnode_t *rinsert(tnode_t *, int);
void tdelete_t(tree_t*,int );

int search(tree_t *, int );
int rsearch_t(tree_t*, int );
int rsearch(tnode_t *, int);
int minimum(tree_t*);
int maximum(tree_t*);

void main()
{
	tree_t t;
	int ch,num,k,n;
	init(&t);
 
	while(1)
	{
		printf("\n1.Insert");
		printf("\n2.Preorder");   
		printf("\n3.Postorder");
		printf("\n4.Inorder");
		printf("\n5.No. of nodes");
		printf("\n6.No. of Leaf nodes");
		printf("\n7.Height of a tree");
		printf("\n8.delete a node");
		printf("\n9..recursively insert..");
		printf("\n10..search..");
		printf("\n11..search using recursion..");
		printf("\n13.find smallest");
		printf("\n14.find largest");
		printf("\n15..exit");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:	printf("Enter the element");
					scanf("%d",&num);
					insert(&t,num);
					break;
			case 2:	preorder_t(&t);
		            break; 
			case 3: postorder_t(&t);
					break;
			case 4:	inorder_t(&t);
					break;
			case 5: k=count_t(&t);
					printf("\nthe number of nodes=%d",k);
					break; 
			case 6: k=leafcount_t(&t);
					printf("\nthe number of nodes=%d",k);
					break;
			case 7: k=height_t(&t);
					printf("\nthe height of tree=%d",k);
					break;
			case 8:	printf("Enter the node to be deleted\n");
					scanf("%d",&num);
					tdelete_t(&t,num);
					break; 
			case 9:	printf("Enter the element");
					scanf("%d",&num);
					rinsert_t(&t,num);
					break;
			case 10:printf("Enter the element");
					scanf("%d",&num);
					int k=search(&t,num);
					if(k)
						printf("Key found\n");
					else
						printf("Not found..\n");
					break;
			case 11:printf("Enter the element");
					scanf("%d",&num);
					int m=rsearch_t(&t,num);
					if(m)
						printf("Key found\n");
					else
						printf("Not found..\n");
					break; 
			case 13:n=minimum(&t);
					printf("\nThe smallest element = %d\n",n);
					break;
			case 14:n=maximum(&t);
					printf("\nthe largest element = %d\n",n);
					break; 
			case 15:exit(0);
       }
    }
}    
  
  
void init(tree_t *t)
{
	t->root=NULL;
}
  
void insert(tree_t *t, int x)
{
	tnode_t *curr, *prev,*temp;
	curr =t->root;
	prev=NULL;
	   
	//create a node
	temp=(tnode_t*)malloc(sizeof(tnode_t));
	temp->data=x;
	temp->left=temp->right=NULL;
	   
	if(curr==NULL) // first element
	    t->root=temp;
	else
	{
		while(curr!=NULL) // find the leaf node
		{
			prev=curr;
			if(x > curr->data)
				curr=curr->right;
			else
				curr=curr->left;
	    }
		if(x>prev->data) // insert to left or right of leaf node
			prev->right=temp;
		else
			prev->left=temp;
	}
}
   
void preorder_t(tree_t *t)
{
    preorder(t->root);
}
		
void preorder(tnode_t *root)
{
    if(root!=NULL)
	{
		printf("%d ",root->data);
		preorder(root->left);
		preorder(root->right);
	}
}
	   
void inorder_t(tree_t *t)
{
	inorder(t->root);
}
	   
void inorder(tnode_t *root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		printf("%d ",root->data);
		inorder(root->right);
	}
}
			   
void postorder_t(tree_t *t)
{
    postorder(t->root);
}			  
			   
void postorder(tnode_t *root)
{
	if(root!=NULL)
	{
		postorder(root->left);
		postorder(root->right);
		printf("%d  ",root->data);
	}
}	   
		      
int minimum(tree_t *t)
{
    tnode_t *root;
    root=t->root;
    if(root==NULL)
        printf("Empty tree");
    else
	{
	 //keep moving left until the left pointer of root is NOT NULL
        while(root->left!=NULL)
            root=root->left;
        return root->data;
    }
}		   
		   
int maximum(tree_t *t)
{
    tnode_t *root;
    root=t->root;
    if(root==NULL)
        printf("Empty tree");
    else
	{
		//keep moving right until the right pointer of root is NOT NULL
        while(root->right!=NULL)
            root=root->right;
        return root->data;
    }
}	
		
int height_t(tree_t *t)
{
	int count;
	count=height(t->root);
	return count;
}
			
int height(tnode_t *root)
{
	int l,r;
	if(root == NULL)
		return -1;
	if((root->left==NULL)&&(root->right==NULL))
		return 0;
	l=height(root->left);
	r=height(root->right);
	if(l>r)
		return (l+1);
	return (r+1);
}
			
int leafcount_t(tree_t *t)
{
	int count=0;
	count=leafcount(t->root);
	return count;
}	
			
int leafcount(tnode_t *root)
{
	int l,r;
	if(root == NULL)
		return 0;
	if((root->left==NULL)&&(root->right==NULL))
		return 1;
	l=leafcount(root->left);
	r=leafcount(root->right);
	return(l+r);
}	
			
int count_t(tree_t* t)
{
	int n=0;
	n=count(t->root);
	return n;
}
			
int count(tnode_t* root)
{
	int l,r;
	if(root==NULL)
		return 0;
	if((root->left==NULL)&&(root->right==NULL))
		return 1;
	l=count(root->left);
	r=count(root->right);
	return (l+r+1);
}
				
void rinsert_t(tree_t *t,int key)
{
	t->root=rinsert(t->root,key);
}
		
tnode_t* rinsert ( tnode_t *root,int key) 
{
	tnode_t *temp;
	if(root==NULL) // empty ree
	{
        temp=(tnode_t*)malloc(sizeof(tnode_t));		
		temp->data=key;
		temp->left=temp->right=NULL;
		return temp;
	}
	if(key<root->data)
		root->left=rinsert(root->left,key);
	else
		root->right= rinsert(root->right,key);
		return root;
}
			
int search(tree_t *t, int key)
{
	tnode_t *curr;
	curr=t->root;
	if(curr==NULL)
		printf("Empty tree..");
	else
	{
		while((curr!=NULL)&&(curr->data!=key))
		{
			if(key < curr->data)
				curr=curr->left;
			else
				curr=curr->right;
		}
		if(curr->data==key)
			return 1;
		return 0;
	}
}		
					
int rsearch_t(tree_t* t, int key)
{
    int k = rsearch(t->root,key);
    return k;
}			  
			
int rsearch(tnode_t *root, int key)
{
	int result;
    if(root==NULL)
	{
		printf("\nEmpty tree\n");
		return 0;
	}
	if(root->data==key)
		return 1;
	if(key<root->data)
		result=rsearch(root->left,key);
	else
        result= rsearch(root->right,key);		
	return result;
}	
			
void tdelete_t(tree_t *t, int key)
{       
	tnode_t* curr,*prev, *q, *p,*temp;
	curr=t->root;//root;
	prev=NULL;
	//search for the key
	while((curr!=NULL)&&(curr->data!=key))
	{
		prev=curr;
		if(key<curr->data)
			curr=curr->left;
		else
			curr=curr->right;
	}
	if(curr==NULL)
	{
		printf("Key not found");
	}
	//if key is found
	//if one subtree or no subtree of node to be deleted
	else if((curr->left==NULL)||(curr->right==NULL))
	{
		if(curr->left==NULL) 
			q=curr->right; //get the right subtree
		else
			q=curr->left; // get the left subtree
		if(prev==NULL) //deleting root with one sub tree (left or right)
			t->root=q;    
		//return q; //return the root of left or right subtree as new root
		else if(curr==prev->left)
			prev->left=q;   //attach q to the left of prev(parent of deleted node)
		else
			prev->right=q; // attach q to the right of prev
			free(curr);
	}
	else // both subtrees present
	{
		//find the inorder successor
		p=NULL;
		temp=curr->right;
		while(temp->left!=NULL)
		{
			p=temp;
			temp=temp->left;
		}
		//temp is the inorder successor
		curr->data=temp->data; //copy data of inorder successor to curr
		if(p!=NULL)
			p->left=temp->right; 
		else
			curr->right=temp->right;
		free(temp); 
	}	
}		
