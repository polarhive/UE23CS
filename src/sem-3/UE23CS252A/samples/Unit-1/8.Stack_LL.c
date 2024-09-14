#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *prev;
};
typedef struct node Node;
typedef struct stack{
    Node *top;
}Stack;
Stack* init(Stack *s){
    s=(Stack*)malloc(sizeof(Stack));
    s->top=NULL;
}

int isEmpty(Stack *s){
    if(s->top==NULL)
        return 1;
    else
        return 0;
}
Node* createNode(int data){
    Node *nn=(Node*)malloc(sizeof(Node));
    nn->data=data;
    nn->prev=NULL;
    return nn;
}
Stack* push(Stack *s,int data){
    Node *nn=createNode(data);
    if(isEmpty(s)){//First Node insertion
       s->top=nn;
    }
    else{
        nn->prev=s->top;
        s->top=nn;
    }
    return s;
}
Stack* pop(Stack *s){
    if(isEmpty(s))
        printf("\nThe Stack is Empty;Cannot perform deletion");
    else{
        Node *temp=s->top;
        s->top=s->top->prev;
        temp->prev=NULL;
        printf("The data deleted is %d",temp->data);
        free(temp);}
    return s;
}
void peep(Stack *s){
    if(!isEmpty(s))
    printf("\nThe top most element of the stack is %d:",s->top->data);
}
void display(Stack *s){
    Node *temp;
    if(!isEmpty(s)){
        printf("\n");
        for(temp=s->top;temp->prev!=NULL;temp=temp->prev)
            printf("%d ",temp->data);
        printf("%d",temp->data);
    }
    }
int main(){
    Stack *s;
    s=init(s);
    s=pop(s);
    s=push(s,5);
    s=push(s,10);
    s=push(s,15);
    display(s);
    s=push(s,20);
    peep(s);
    display(s);
    return 0;
}
