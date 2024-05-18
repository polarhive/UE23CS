// Write a Program in C to create a Singly Linked List with ‘n’ number of nodes. Perform
// the following operations in the same order:
// 1. Read the value of ‘n’ from user
// 2. Insert ‘n’ number of nodes – insert elements to the front of the linked list
// (Implement using a function insertFront() )
// 3. Display all the nodes – After insertion of nodes (Implement using a function
// display() )
// 4. Delete the first node – Implement using a function deleteFront()
// 5. Display all the nodes – After deletion of node (Use the function display() )
// 6. Free the list – Implement using a function freeList()

#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int info;
    struct node *next;
} NODE;
NODE *insertFront(NODE *head, int ele);
void display(NODE *head);
NODE *deleteFront(NODE *head);
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
        head = insertFront(head, ele);
    }
    display(head);
    head = deleteFront(head);
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
NODE *insertFront(NODE *head, int ele)
{
    NODE *newNode = createNode(ele);
    newNode->next = head;
    head = newNode;
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
NODE *deleteFront(NODE *head)
{
    if (head == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        NODE *p = head;
        printf("Deleted element is %d\n", p->info);
        head = p->next;
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