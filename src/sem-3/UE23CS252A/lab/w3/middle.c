#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct Node
{
    int info;
    struct Node *next;
} Node;

Node *createNode(int info)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->info = info;
    newNode->next = NULL;
    return newNode;
}

void printList(Node *head)
{
    if (head == NULL)
    {
        printf("-1\n");
        return;
    }

    while (head != NULL)
    {
        printf("%d ", head->info);
        head = head->next;
    }
    printf("\n");
}

void middle(Node **head)
{
    if (*head == NULL || (*head)->next == NULL)
    {
        *head = NULL;
        return;
    }

    Node *slow = *head;
    Node *fast = *head;
    Node *prev = NULL;

    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        if (fast != NULL)
        {
            prev = slow;
            slow = slow->next;
        }
    }

    if (prev == NULL)
    {
        // 2 nodes in the list
        Node *temp = *head;
        *head = (*head)->next;
        free(temp);
    }
    else
    {
        Node *temp = slow;
        prev->next = slow->next;
        free(temp);
    }
}

int main()
{
    int size, info;
    scanf("%d", &size);

    Node *head = NULL;
    Node *current = NULL;

    for (int i = 0; i < size; i++)
    {
        scanf("%d", &info);
        Node *newNode = createNode(info);
        if (head == NULL)
        {
            head = newNode;
            current = head;
        }
        else
        {
            current->next = newNode;
            current = newNode;
        }
    }

    middle(&head);
    printList(head);

    while (head != NULL)
    {
        Node *temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
