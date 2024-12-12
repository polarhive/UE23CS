#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} Node;
Node *createNode(int data);
void display(Node *head);

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
Node *createNode(int data)
{
    Node *newnode;
    newnode = (Node *)malloc(sizeof(Node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}
int main()
{
    Node *head = NULL, *temp, *prev = NULL, *nn;
    int data, ch = 0;
    do
    {
        printf("\nEnter the data to be inserted:");
        scanf("%d", &data);
        nn = createNode(data);
        if (head == NULL)
        {
            head = nn;
        }
        else if (data < head->data)
        {
            // if(data<head->data){
            nn->next = head;
            head = nn;
            // }
            /* else{
                 head->next=nn;
                 }*/
        }
        else
        {
            temp = head;
            while (temp->next != NULL && temp->data < data)
            {
                prev = temp;
                temp = temp->next;
            }
            if (temp->next == NULL)
            {
                temp->next = nn;
            }
            else
            {
                nn->next = temp;
                prev->next = nn;
            }
        }
        display(head);
        printf("\nPress 1 to continue...");
        scanf("%d", &ch);
    } while (ch);
    return;
}
