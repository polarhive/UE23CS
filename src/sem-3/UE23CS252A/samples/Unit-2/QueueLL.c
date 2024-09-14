#include<stdio.h>
#include<stdlib.h>>

typedef struct node{
    int data;
    struct node *next;
}Node;
int isEmpty(Node *f,Node *r){
    return(f==r && f==NULL);
}
int isOneElement(Node *f,Node *r){
    return(f==r && f!=NULL);//f->next==f
}
Node* createNode(int d){
    Node* nn=(Node*)malloc(sizeof(Node));
    nn->data=d;
    nn->next=NULL;
    return nn;
}
void Enqueue(Node **f,Node **r,int d){
    Node *nn=createNode(d);
    //nn->next=*f;
    if(isEmpty(*f,*r)){
        *f=*r=nn;
    }
    else{
        (*r)->next=nn;
        *r=nn;          //*r=(*r)->next
    }
    (*r)->next=*f; //Change
}
void Dequeue(Node **f,Node **r){
    Node *temp;
    if(isEmpty(*f,*r)){
        printf("\nQueue is Empty;Cannot Delete");
    }
    else if(isOneElement(*f,*r)){
        temp=*f;
        *f=*r=NULL;
        free(temp);
    }
    else{
        temp=*f;
        (*f)=(*f)->next;
        (*r)->next=*f; // Change
        temp->next=NULL;
        free(temp);
    }
}
void display(Node *f,Node *r){
    Node *temp;
    if(!isEmpty(f,r)){
        printf("\n");
        for(temp=f;temp->next!=f;temp=temp->next){
            printf("%d ",temp->data);
            }
        printf("%d ",temp->data);
    }
    else
        printf("\nQueue is Empty");
}
void main(){
    Node *f=NULL,*r=NULL;
    Enqueue(&f,&r,5);
    display(f,r);
    Enqueue(&f,&r,15);
    display(f,r);
    Enqueue(&f,&r,25);
    display(f,r);
    Dequeue(&f,&r);
    display(f,r);
    Dequeue(&f,&r);
    display(f,r);
    Dequeue(&f,&r);
    display(f,r);
    Dequeue(&f,&r);
    display(f,r);
    Dequeue(&f,&r);
    display(f,r);

}
