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

// Define the node structure for the singly linked list
typedef struct node {
    int info;
    struct node *next;
} NODE;

// Function prototypes
NODE *insertFront(NODE *head, int ele);
void display(NODE *head);
NODE *deleteFront(NODE *head);
NODE *freeList(NODE *head);

int main() {
    NODE *head = NULL; // Initialize the head of the linked list to NULL
    int ele;
    int n;
    
    // Read the number of nodes to be inserted
    scanf("%d", &n);
    
    // Insert 'n' nodes into the linked list
    for (int i = 0; i < n; i++) {
        scanf("%d", &ele); // Read the element value
        head = insertFront(head, ele); // Insert the element at the front of the list
    }
    
    // Display the linked list after insertion
    display(head);
    
    // Delete the first node
    head = deleteFront(head);
    
    // Display the linked list after deletion
    display(head);
    
    // Free the entire list
    head = freeList(head);
    
    return 0;
}

// Function to create a new node with the given element
NODE *createNode(int ele) {
    NODE *newNode = (NODE *)malloc(sizeof(struct node));
    // Assume memory is always allocated successfully
    newNode->info = ele;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the front of the list
NODE *insertFront(NODE *head, int ele) {
    NODE *newNode = createNode(ele);
    newNode->next = head; // Point the new node's next to the current head
    head = newNode; // Update the head to the new node
    return head;
}

// Function to display all nodes in the list
void display(NODE *head) {
    if (head == NULL) {
        printf("List is empty\n");
    } else {
        NODE *p = head;
        printf("Elements are:\n");
        // Traverse the list and print each element
        while (p != NULL) {
            printf("%d\n", p->info);
            p = p->next;
        }
    }
}

// Function to delete the first node in the list
NODE *deleteFront(NODE *head) {
    if (head == NULL) {
        printf("List is empty\n");
    } else {
        NODE *p = head; // Node to be deleted (first node)
        printf("Deleted element is %d\n", p->info);
        head = p->next; // Update the head to the next node
        free(p); // Free the memory of the deleted node
    }
    return head;
}

// Function to free all nodes in the list
NODE *freeList(NODE *head) {
    NODE *p = head;
    while (head != NULL) {
        head = head->next;
        // Free each node's memory
        free(p);
        p = head;
    }
    return head;
}
