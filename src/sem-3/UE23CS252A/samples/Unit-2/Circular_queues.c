#include<stdio.h>
#define SIZE 5

typedef struct queue{
 int array[SIZE];
 int f;
 int r;
}Queue;
void init(Queue *q){
    q->f=-1;
    q->r=-1;
}
int isEmpty(Queue q){
    return(q.f==q.r && q.f==-1);
}
int isFull(Queue q){
    return((q.r==SIZE-1 && q.f==0) ||(q.r+1 == q.f));
}
int isOneElement(Queue q){
    return(q.f==q.r && q.f!=-1);
}
void Enqueue(Queue *q,int d){
    if(isEmpty(*q))
        q->f=q->r=0;
    else if(isFull(*q))
        printf("\nQueue is full;Cannot insert");
    else
        (q->r)++;
    q->array[q->r]=d;
}
void Dequeue(Queue *q){
    if(isEmpty(*q))
        printf("\nCannot perform Deletion");
    else if(isOneElement(*q))
        q->f=q->r=-1;
    else
        (q->f)++;
}
void display(Queue q){
    if(!isEmpty(q)){
        printf("\n");
        for(int i=q.f;i<=q.r;i++)
            printf("%d ",q.array[i]);
    }
    else
        printf("\nThe Queue is Empty");
}
void main(){
    Queue q;
    init(&q);
    Dequeue(&q);
    display(q);
    Enqueue(&q,5);
    display(q);
    Enqueue(&q,15);
    display(q);
    Enqueue(&q,25);
    display(q);
    Enqueue(&q,35);
    display(q);
    Enqueue(&q,45);
    display(q);
    Dequeue(&q);
    display(q);
    Dequeue(&q);
    display(q);
    Dequeue(&q);
    display(q);
    Dequeue(&q);
    display(q);
    Dequeue(&q);
    display(q);
    Dequeue(&q);
    display(q);
    Enqueue(&q,55);
    display(q);
    Enqueue(&q,65);
    display(q);
}






