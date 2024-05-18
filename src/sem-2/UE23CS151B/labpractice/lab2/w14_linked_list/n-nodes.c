// Write a Program in C to create a Singly Linked List with ‘n’ number of nodes. Perform
// the following operations in the same order:
// 1. Read the value of ‘n’ from user
// 2. Insert ‘n’ number of nodes – insert nodes to the last of the linked list (Implement
// using a function insertLast() )
// 3. Display all the nodes – After insertion of nodes (Implement using a function
// display() )
// 4. Delete the last node – Implement using a function deleteLast()
// 5. Display all the nodes – After deletion of node (Use the function display() )
// 6. Free the list – Implement using a function freeList()

#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int info;
    struct node *next;
} NODE;
NODE *insertLast(NODE *head, int ele);
void display(NODE *head);
NODE *deleteLast(NODE *head);
NODE *freeList(NODE *head);
int main()
{
    NODE *head = NULL;
    int ele;
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &ele);
        head = insertLast(head, ele);
    }
    display(head);
    head = deleteLast(head);

    display(head);
    head = freeList(head);
}
NODE *createNode(int ele)
{
    NODE *newNode = malloc(sizeof(struct node));
    // We assume memory is always allocated to the newnode and
    // hence not checking for newNode==NULL
    newNode->info = ele;
    newNode->next = NULL;
    return newNode;
}
NODE *insertLast(NODE *head, int ele)
{
    NODE *temp;
    NODE *newNode = createNode(ele);
    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    return head;
}

void display(NODE *head)
{
    if (head == NULL)
        printf("List is empty\n");
    else
    {
        NODE *p = head;
        printf("Elements are:\n");
        while (p != NULL)
        {
            printf("%d\n", p->info);
            p = p->next;
        }
    }
}
NODE *deleteLast(NODE *head)
{
    if (head == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        NODE *p; // To be deleted (Last)
        NODE *q; // Referring to Last but one
        p = q = head;
        while (p->next != NULL)
        {
            q = p;
            p = p->next;
        }
        q->next = NULL;
        printf("Deleted element is %d\n", p->info);
        free(p);
    }
    return head;
}
NODE *freeList(NODE *head)
{
    NODE *p = head;
    while (head != NULL)
    {
        head = head->next;
        // printf("Freeing %d\n",p->info);
        free(p);
        p = head;
    }
    return head;
}
