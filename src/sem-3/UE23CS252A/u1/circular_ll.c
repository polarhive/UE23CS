#include <stdio.h>
#include <stdlib.h>

typedef struct NODE
{
    int data;
    struct NODE *next;
    struct NODE *prev;
} NODE;
NODE* createNode(int data) {
    NODE* newNode = (NODE*)malloc(sizeof(NODE));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void insertNode(NODE** head, int data) {
    NODE* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        newNode->next = newNode;
        newNode->prev = newNode;
    } else {
        NODE* last = (*head)->prev;
        newNode->next = *head;
        newNode->prev = last;
        (*head)->prev = newNode;
        last->next = newNode;
    }
}

void displayList(NODE* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    NODE* current = head;
    do {
        printf("%d ", current->data);
        current = current->next;
    } while (current != head);
    printf("\n");
}

void deleteList(NODE** head) {
    if (*head == NULL) {
        return;
    }
    NODE* current = *head;
    NODE* next;
    do {
        next = current->next;
        free(current);
        current = next;
    } while (current != *head);
    *head = NULL;
}

int main() {
    NODE* head = NULL;

    // Insert nodes into the circular linked list
    insertNode(&head, 10);
    insertNode(&head, 20);
    insertNode(&head, 30);

    // Display the circular linked list
    printf("Circular Linked List: ");
    displayList(head);

    // Delete the circular linked list
    deleteList(&head);

    return 0;
}