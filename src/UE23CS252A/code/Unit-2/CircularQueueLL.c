#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
} Node;
int isEmpty(Node *f, Node *r)
{
    return (f == r && f == NULL);
}
int isOneElement(Node *f, Node *r)
{
    return (f == r && f != NULL); // f->next==f
}
Node *createNode(int d)
{
    Node *nn = (Node *)malloc(sizeof(Node));
    nn->data = d;
    nn->next = NULL;
    return nn;
}
void Enqueue(Node **f, Node **r, int d)
{
    Node *nn = createNode(d);
    if (isEmpty(*f, *r))
    {
        *r = *f = nn;
    }
    else
    {
        (*r)->next = nn;
        *r = nn;
    }
    (*r)->next = *f;
}
void Dequeue(Node **f, Node **r)
{
    Node *temp;
    if (isEmpty(*f, *r))
        printf("\nQueue is Empty;Cannot Delete");
    else if (isOneElement(*f, *r))
    {
        temp = *f;
        free(temp);
        *f = *r = NULL;
    }
    else
    {
        temp = *f;
        *f = (*f)->next;
        (*r)->next = *f; // rear is pointing to the new front node
        temp->next = NULL;
        free(temp);
    }
}
void display(Node *f, Node *r)
{
    Node *t = f;
    printf("\n");
    // printf("%p %p %p",f,r,f->next);
    if (!isEmpty(f, r))
    {
        while (t->next != f)
        {
            printf("%d ", t->data);
            t = t->next;
        }
        printf("%d ", t->data);
    }
    else
        printf("\nQueue is Empty");
}
void main()
{
    Node *f = NULL, *r = NULL;
    Enqueue(&f, &r, 5);
    display(f, r);
    Enqueue(&f, &r, 15);
    display(f, r);
    Dequeue(&f, &r);
    display(f, r);
    Dequeue(&f, &r);
    display(f, r);
    Dequeue(&f, &r);
    display(f, r);
}
