#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *link;
} node;

// Function to insert a node at the front of the linked list
node* insert_front(node *head, int data) {
    node *newNode = (node *)malloc(sizeof(node));
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->link = head;
    return newNode;
}

void display(node *head) {
    node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->link;
    }
    printf("\n");
}

int main() {
    int element;
    node *head = NULL;

    // at the front of the linked list
    for (int i = 0; i < 3; i++) {
        printf("Enter the element:\n");
        scanf("%d", &element);
        head = insert_front(head, element);
    }

    // display the linked list
    printf("Linked list elements: ");
    display(head);
}
