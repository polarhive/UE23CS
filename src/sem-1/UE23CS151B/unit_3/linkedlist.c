#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a node at the end of the linked list
void insertLast(struct Node** head, int value) {

    // Allocate memory for the new node
    struct Node* newNode = malloc(sizeof(struct Node));

    // Assign data and next pointer
    newNode->data = value;
    newNode->next = NULL;

    // If the list is empty; make new node = head
    if (*head == NULL) {
        *head = newNode;
        return;
    }

    // Otherwise, goto the end of the list and insert the new node
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to delete the last node
void deleteLast(struct Node** head) {

    // If the list is empty or has only one node
    if (*head == NULL)
        return;
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }

    // Traverse to the second last node
    struct Node* temp = *head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    // Free the last node and update next pointer of the second last node
    free(temp->next);
    temp->next = NULL;
}

// Function to display all the nodes in the linked list
void display(struct Node* head) {

    // If the list is empty, print a message
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    // Otherwise, traverse and print each node's data
    printf("Elements are:\n");
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

// Function to free the memory allocated for the linked list
void freeList(struct Node** head) {
    struct Node* temp;
    // Traverse the list and free each node
    while (*head != NULL) {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

int main() {
    struct Node* head = NULL;
    int n, value;

    // Read the value of 'n'
    scanf("%d", &n);

    // Insert 'n' number of nodes
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        insertLast(&head, value);
    }

    // Display all the nodes after insertion
    display(head);

    // Delete the last node
    deleteLast(&head);
    printf("Deleted element is %d\n", value);

    // Display all the nodes after deletion
    display(head);

    // Free the memory allocated for the linked list
    freeList(&head);

    return 0;
}
