#include<stdio.h>
#include<stdlib.h>
#define SIZE 3
struct stack{
    int top;
    int array[SIZE];
};
typedef struct stack Stack;
Stack* init(Stack *s){
    s=(Stack*)malloc(sizeof(Stack));
    s->top=-1;
}
int isFull(Stack *s){
    if(s->top>=SIZE-1)
        return 1;
    else
        return 0;
}
int isEmpty(Stack *s){
    if(s->top==-1)
        return 1;
    else
        return 0;
}
Stack* push(Stack *s,int data){
    if(isFull(s))
        printf("\nThe Stack is full;Cannot perform insertion");
    else{
        s->array[++(s->top)]=data;
    }
    return s;
}
Stack* pop(Stack *s){
    if(isEmpty(s))
        printf("\nThe Stack is Empty;Cannot perform deletion");
    else{
        printf("The data deleted is %d",s->array[(s->top)--]);
    }
    return s;
}
void peep(Stack *s){
    if(!isEmpty(s))
    printf("\nThe top most element of the stack is %d:",s->array[s->top]);
}
void display(Stack *s){
    if(!isEmpty(s)){
        printf("\n");
        for(int i=0;i<=s->top;i++)
            printf("%d ",s->array[i]);
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
