#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define MAX 10

typedef struct node{
    int utype;
    union {
        float operand;
        char operater;
    }u;
    struct node *l;
    struct node *r;
}NODE;
static int top=-1;
NODE* pop(NODE *stack[]){//**stack
    if(top==-1)
        printf("The stack is empty");
    else
        return stack[top--];
}
void push(NODE *nn,NODE *stack[]){
    if(top<MAX){
        stack[++top]=nn;
    }
}

NODE* construct(char exp[]) {
    NODE stack[MAX],*nn;
    int i=0;
    while(exp[i]){
        nn=(NODE*)malloc(sizeof(NODE));//inside while loop
        if(isdigit(exp[i])){//operand
           nn->utype=1;
           nn->u.operand=exp[i]-'0';//char to int
           nn->l=NULL;
           nn->r=NULL;
           push(nn,&stack);
        }
        else{
            nn->utype=2;
            nn->u.operater=exp[i];
            nn->r=pop(&stack);
            nn->l=pop(&stack);
            push(nn,&stack);
        }
        i++;
    }
    return pop(&stack);
}
void inorder(NODE *bt){
    if(bt!=NULL){
        inorder(bt->l);
        if(bt->utype==1)
            printf("%g ",bt->u.operand);
        else
            printf("%c ",bt->u.operater);
        inorder(bt->r);
    }
}
float calculate(float x,char op,float y){
float res;
switch(op){
    case '+':
        res=x+y;
        break;
    case '-':
        res=x-y;
        break;
    case '*':
        res=x*y;
        break;
    case '/':
        res=x/y;
        break;
}
return res;
}
float evaluate(NODE *bt){
    if(bt->utype==1)//operand
        return bt->u.operand;
    float x=evaluate(bt->l);
    float y=evaluate(bt->r);
    return calculate(x,bt->u.operater,y);
}
int main(){
    NODE *bt;
    char exp[MAX]="567*+8-";
    bt=construct(exp);
    inorder(bt);
    printf("\n%g",evaluate(bt));
    return 0;
}



