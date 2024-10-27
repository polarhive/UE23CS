#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    int lthread;
    int rthread;
    struct node *left;
    struct node *right;
}
NODE;
NODE* createNode(int data){
    NODE *nn=(NODE*)malloc(sizeof(NODE));
    nn->data=data;
    return nn;
}
NODE* insertNode(NODE *root,int data){
    NODE *t=root,*parent,*nn;
    nn=createNode(data);
    if(t==NULL){ //root node
        nn->lthread=1;
        nn->rthread=1;
        nn->left=NULL;
        nn->right=NULL;
        root=nn;
        return root;
    }
    /*if lthread=0, it means it has a left child
    rthread=0, it means it has a right child*/
    //To determine the parent of the node to be inserted
    while(t!=NULL){
        parent=t;
        if(data<t->data){
            if(t->lthread==0)
                t=t->left;
            else
                break;
        }
        else if(data>t->data){
            if(t->rthread==0)
                t=t->right;
            else
                break;
        }
        else{
            printf("\nDuplicate Key");
            return root;
        }
    }
    if(data<parent->data){//left child
           nn->lthread=1;
           nn->rthread=1;
           nn->data=data;
           nn->left=parent->left;
           nn->right=parent;
           parent->left=nn;
           parent->lthread=0;
        }
    else{//right child
          nn->lthread=1;
          nn->rthread=1;
          nn->data=data;
          nn->left=parent;
          nn->right=parent->right;
          parent->right=nn;
          parent->rthread=0;
        }
    return root;
}
NODE* inorderSuccessor(NODE *t){
    if(t->rthread==1)//if it doesn't has a right child
        return t->right;//inorder successor link is present in the right link
    //if(t->rthread==0)//if it has a right child
    t=t->right;
    while(t->lthread==0)
        t=t->left;
    return t;
}
void inorder(NODE *root){
    NODE *t=root;
    if(root!=NULL){
        while(t->lthread==0)//t->left!=NULL
            t=t->left;
        while(t!=NULL){
            printf("%d ",t->data);
            t=inorderSuccessor(t);
        }
    }
}
void main(){
    NODE *tbst=NULL;
    int data,ch;
    do{
    printf("\nEnter the data: ");
    scanf("%d",&data);
    tbst=insertNode(tbst,data);
    printf("\n");
    inorder(tbst);
    printf("\nPress 1 to Continue: ");//0 to quit
    scanf("%d",&ch);
    }while(ch);
    inorder(tbst);
}
