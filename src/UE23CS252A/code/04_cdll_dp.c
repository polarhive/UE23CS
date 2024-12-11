#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};
typedef struct node NODE;

// Insert at the beginning (CDLL)
/*
1. Create a new node.
2. If the list is empty (head is NULL):
   - Make the new node point to itself (both `prev` and `next` point to itself).
   - Return the new node as the head.
3. If the list is not empty:
   - Traverse to the last node.
   - Set the last node's next pointer to the new node.
   - Set the new node's prev pointer to the last node.
   - Set the new node's next pointer to the head.
   - Set the head's prev pointer to the new node.
   - Return the new node as the new head.
*/
NODE *insert_at_beginning(NODE *head, int data)
{
    NODE *new_node = (NODE *)malloc(sizeof(NODE));
    if (!new_node)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }
    new_node->data = data;

    if (head == NULL) // If the list is empty
    {
        new_node->next = new_node;
        new_node->prev = new_node;
        return new_node;
    }

    // If the list is not empty, find the last node
    NODE *temp = head->prev;

    // Insert the new node at the beginning
    temp->next = new_node;
    new_node->prev = temp;
    new_node->next = head;
    head->prev = new_node;
    return new_node;
}

// Insert at the end (CDLL)
/*
1. Create a new node.
2. If the list is empty (head is NULL):
   - Make the new node point to itself (both `prev` and `next` point to itself).
   - Return the new node as the head.
3. If the list is not empty:
   - Traverse to the last node (i.e., the node whose `next` pointer points to the head).
   - Set the last node's next pointer to the new node.
   - Set the new node's prev pointer to the last node.
   - Set the new node's next pointer to the head.
   - Set the head's prev pointer to the new node.
   - Return the unchanged head.
*/
NODE *insert_at_end(NODE *head, int data)
{
    NODE *new_node = (NODE *)malloc(sizeof(NODE));
    if (!new_node)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }
    new_node->data = data;

    if (head == NULL) // If the list is empty
    {
        new_node->next = new_node;
        new_node->prev = new_node;
        return new_node;
    }

    // If the list is not empty, find the last node
    NODE *temp = head->prev;

    // Insert the new node at the end
    temp->next = new_node;
    new_node->prev = temp;
    new_node->next = head;
    head->prev = new_node;
    return head;
}

// Insert at a specific position (CDLL)
/*
1. Create a new node.
2. If the position is 1:
   - Insert at the beginning (reusing the insert_at_beginning function).
3. If the position is greater than 1:
   - Traverse to the (position-1)th node.
   - If the position is invalid (i.e., the (position-1)th node is NULL):
     - Print an error message.
   - Otherwise:
     - Set the new node's next pointer to the (position-1)th node's next pointer.
     - Set the new node's prev pointer to the (position-1)th node.
     - Set the (position-1)th node's next pointer to the new node.
     - Set the new node's next node's prev pointer to the new node.
   - Return the unchanged head.
*/
NODE *insert_at_position(NODE *head, int data, int position)
{
    if (position < 1)
    {
        printf("Invalid position\n");
        return head;
    }

    NODE *new_node = (NODE *)malloc(sizeof(NODE));
    if (!new_node)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }
    new_node->data = data;

    if (position == 1) // Insert at the beginning
    {
        return insert_at_beginning(head, data);
    }

    // Insert at any other position
    NODE *temp = head;
    for (int i = 1; i < position - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Position out of range\n");
        free(new_node);
        return head;
    }

    new_node->next = temp->next;
    new_node->prev = temp;
    temp->next->prev = new_node;
    temp->next = new_node;
    return head;
}

// Delete the first node (CDLL)
/*
1. If the list is empty (head is NULL), print an error message and return the head.
2. If there is only one node in the list:
   - Free the node and set the head to NULL.
3. If there are multiple nodes:
   - Set the second node's prev pointer to the last node.
   - Set the last node's next pointer to the second node.
   - Free the first node and return the new head.
*/
NODE *delete_first_node(NODE *head)
{
    if (head == NULL)
    {
        printf("List is empty. Nothing to delete.\n");
        return head;
    }

    if (head->next == head) // Only one node in the list
    {
        free(head);
        return NULL;
    }

    // More than one node in the list
    NODE *temp = head;
    head->next->prev = head->prev;
    head->prev->next = head->next;
    head = head->next;
    free(temp);
    return head;
}

// Delete the last node (CDLL)
/*
1. If the list is empty (head is NULL), print an error message and return the head.
2. If there is only one node in the list:
   - Free the node and set the head to NULL.
3. If there are multiple nodes:
   - Set the second last node's next pointer to the head.
   - Set the head's prev pointer to the second last node.
   - Free the last node and return the unchanged head.
*/
NODE *delete_last_node(NODE *head)
{
    if (head == NULL)
    {
        printf("List is empty. Nothing to delete.\n");
        return head;
    }

    if (head->next == head) // Only one node in the list
    {
        free(head);
        return NULL;
    }

    // More than one node in the list
    NODE *temp = head->prev;
    head->prev = temp->prev;
    temp->prev->next = head;
    free(temp);
    return head;
}

// Print the circular doubly linked list
/*
1. If the list is empty (head is NULL), print a message indicating so.
2. Otherwise, traverse through the list starting from the head.
3. Print each node's data and move to the next node until the head is reached again, indicating it's a circular doubly linked list.
*/
void print_list(NODE *head)
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    NODE *temp = head;
    do
    {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(back to head)\n");
}

// Main function to demonstrate CDLL operations
int main()
{
    NODE *head = NULL; // Initialize the head pointer to NULL

    // Insert nodes at the beginning
    head = insert_at_beginning(head, 10);
    head = insert_at_beginning(head, 20);

    // Insert nodes at the end
    head = insert_at_end(head, 30);
    head = insert_at_end(head, 40);

    // Insert node at position 2 (1-based indexing)
    head = insert_at_position(head, 25, 2);

    // Print the circular doubly linked list
    print_list(head);

    // Delete first node
    head = delete_first_node(head);
    print_list(head);

    // Delete last node
    head = delete_last_node(head);
    print_list(head);

    return 0;
}
