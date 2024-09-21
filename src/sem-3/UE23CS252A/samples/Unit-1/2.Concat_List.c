#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
} Node;
Node *createList(int n);
void display(Node *head);
Node *concat_List(Node *h1, Node *h2);

int main()
{
    Node *h1 = NULL, *h2 = NULL;
    int n; // no. of nodes in a list
    printf("\nEnter the no. of nodes in list1:");
    scanf("%d", &n);
    h1 = createList(n);
    display(h1);
    printf("\nEnter the no. of nodes in list2:");
    scanf("%d", &n);
    h2 = createList(n);
    display(h2);
    h1 = concat_List(h1, h2);
    printf("\n");
    display(h1);
    return;
}

Node *createList(int n)
{
    Node *head = NULL, *last = NULL, *temp;
    int data;
    for (int i = 1; i <= n; i++)
    {
        temp = (Node *)malloc(sizeof(Node));
        printf("\nEnter data: ");
        scanf("%d", &data);
        temp->data = data;
        temp->next = NULL;
        if (head == NULL)
        { // first Node
            head = temp;
            last = temp;
        }
        else
        {
            last->next = temp;
            last = last->next;
        }
    }
    return head;
}
void display(Node *head)
{
    Node *temp = head;
    if (head == NULL)
        printf("\nThe List is empty");
    else
    {
        while (temp->next != NULL)
        {
            printf("%d->", temp->data);
            temp = temp->next; // Important otherwise infinite loop
        }
        printf("%d->NULL", temp->data);
    }
}

Node *concat_List(Node *h1, Node *h2)
{
    Node *t1 = h1;
    if (h1 == NULL)
        return h2;
    if (h2 == NULL)
        return h1;

    while (t1->next != NULL)
        t1 = t1->next;
    t1->next = h2;
    return h1;
}
