#include <stdio.h>
#define SIZE 3

typedef struct queue
{
    int array[SIZE];
    int f;
    int r;
} Queue;
/* Calling method: q=init(q);
Queue init(Queue q){
    q.f=-1;
    q.r=-1;
    return q;
}
*/
void init(Queue *q)
{
    q->f = -1;
    q->r = -1;
}
int isEmpty(Queue q)
{
    return (q.r == q.f && q.f == -1);
}
int isOneElement(Queue q)
{
    return (q.r == q.f && q.f != -1);
}
int isFull(Queue q)
{
    return ((q.r == SIZE - 1 && q.f == 0) || ((q.r) + 1 == q.f)); // Change1
}
void Enqueue(Queue *q, int d)
{
    if (isEmpty(*q))
    {
        q->r = q->f = 0; // First element of the queue
        q->array[q->r] = d;
    }
    else if (isFull(*q))
        printf("\nQueue is full;Cannot insert");
    else
    {
        if (q->r == SIZE - 1) // Change2
            q->r = 0;
        else
            ++(q->r);
        q->array[q->r] = d;
    }
}
void InsertFront(Queue *q, int d)
{
    if (isEmpty(*q))
    {
        q->r = q->f = 0; // First element of the queue
        q->array[q->r] = d;
    }
    else if (isFull(*q))
        printf("\nQueue is full;Cannot insert");
    else
    {
        if (q->f == 0) // Change2
            q->f = SIZE - 1;
        else
            --(q->f);
        q->array[q->f] = d;
    }
}
void Dequeue(Queue *q)
{
    if (isEmpty(*q))
    {
        printf("\nQueue is Empty;Cannot delete");
    }
    else if (isOneElement(*q))
    {
        q->f = q->r = -1;
    }
    else
    {
        if (q->f == SIZE - 1) // Change 3
            q->f = 0;
        else
            ++(q->f);
    }
}
void DeleteRear(Queue *q)
{
    if (isEmpty(*q))
    {
        printf("\nQueue is Empty;Cannot delete");
    }
    else if (isOneElement(*q))
    {
        q->f = q->r = -1;
    }
    else
    {
        if (q->r == 0) // Change 3
            q->r = SIZE - 1;
        else
            --(q->r);
    }
}
void display(Queue q)
{
    if (!isEmpty(q))
    {
        printf("\n");
        if (q.r < q.f)
        { // Change 4
            for (int i = q.f; i <= SIZE - 1; i++)
                printf("%d ", q.array[i]);
            for (int i = 0; i <= q.r; i++)
                printf("%d ", q.array[i]);
        }
        else
        {
            for (int i = q.f; i <= q.r; i++)
                printf("%d ", q.array[i]);
        }
    }
    else
        printf("\nQueue is Empty");
}
void main()
{
    Queue q;
    init(&q);
    Dequeue(&q);
    display(q);
    Enqueue(&q, 5);
    display(q);
    Enqueue(&q, 15);
    display(q);
    Enqueue(&q, 25);
    display(q);
    Dequeue(&q);
    display(q);
    Enqueue(&q, 35);
    display(q);
    Dequeue(&q);
    display(q);
    Dequeue(&q);
    display(q);
    Dequeue(&q);
    display(q);
}