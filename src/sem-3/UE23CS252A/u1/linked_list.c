#include <stdio.h>
#include <stdlib.h>
typedef struct NODE
{
    int data;
    struct NODE *next; //[data][*next]
} NODE;

void insert(NODE **head, int data) // where? data
{
    NODE *newNode = (NODE *)malloc(sizeof(NODE)); // make new NODE of same shape
    newNode->data = data;                         // store data
    newNode->next = NULL;                         // this is the END

    if (*head == NULL) // check if empty
    {
        *head = newNode; // replace the head with the new node
    }
    else
    {
        NODE *temp = *head;        // create a temporary pointer to traverse the linked list
        while (temp->next != NULL) // find the last node in the linked list
        {
            temp = temp->next;
        }
        temp->next = newNode; // assign the new node as the next node of the last node
    }
}

void display(NODE *head)
{
    NODE *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    NODE *head = NULL;

    insert(&head, 1);
    insert(&head, 2);
    insert(&head, 3);

    display(head);

    return 0;
}
