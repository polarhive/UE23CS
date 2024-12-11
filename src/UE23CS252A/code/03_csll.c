#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};
typedef struct node NODE;

// Insert at the beginning (Circular Linked List)
/*
1. Create a new node.
2. If the list is empty (head is NULL):
   - Make the new node point to itself (link to itself).
   - Return the new node as the head.
3. If the list is not empty:
   - Traverse to the last node.
   - Set the last node's link to the new node.
   - Make the new node's link point to the head.
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
        new_node->link = new_node; // Point to itself
        return new_node;
    }

    // If the list is not empty, find the last node
    NODE *temp = head;
    while (temp->link != head)
    {
        temp = temp->link;
    }

    // Insert the new node at the beginning
    temp->link = new_node;
    new_node->link = head;
    return new_node;
}

// Insert at the end (Circular Linked List)
/*
1. Create a new node.
2. If the list is empty (head is NULL):
   - Make the new node point to itself (link to itself).
   - Return the new node as the head.
3. If the list is not empty:
   - Traverse to the last node.
   - Set the last node's link to the new node.
   - Make the new node's link point to the head.
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
        new_node->link = new_node; // Point to itself
        return new_node;
    }

    // If the list is not empty, find the last node
    NODE *temp = head;
    while (temp->link != head)
    {
        temp = temp->link;
    }

    // Insert the new node at the end
    temp->link = new_node;
    new_node->link = head;
    return head;
}

// Insert at a specific position (Circular Linked List)
/*
1. Create a new node.
2. If the position is 1:
   - Insert at the beginning (reusing the insert_at_beginning function).
3. If the position is greater than 1:
   - Traverse to the (position-1)th node.
   - If the position is invalid (i.e., the (position-1)th node is NULL):
     - Print an error message.
   - Otherwise:
     - Set the new node's link to the (position-1)th node's link.
     - Set the (position-1)th node's link to the new node.
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
        temp = temp->link;
    }

    if (temp == NULL)
    {
        printf("Position out of range\n");
        free(new_node);
        return head;
    }

    new_node->link = temp->link;
    temp->link = new_node;
    return head;
}

// Delete the first node (Circular Linked List)
/*
1. If the list is empty (head is NULL), print an error message and return the head.
2. If there is only one node in the list:
   - Free the node and set the head to NULL.
3. If there are multiple nodes:
   - Traverse to the last node (which links to the head).
   - Set the last node's link to the second node.
   - Free the first node and return the new head.
*/
NODE *delete_first_node(NODE *head)
{
    if (head == NULL)
    {
        printf("List is empty. Nothing to delete.\n");
        return head;
    }

    if (head->link == head) // Only one node in the list
    {
        free(head);
        return NULL;
    }

    // More than one node in the list
    NODE *temp = head;
    while (temp->link != head)
    {
        temp = temp->link;
    }

    temp->link = head->link;
    free(head);
    return temp->link;
}

// Delete the last node (Circular Linked List)
/*
1. If the list is empty (head is NULL), print an error message and return the head.
2. If there is only one node in the list:
   - Free the node and set the head to NULL.
3. If there are multiple nodes:
   - Traverse to the second last node.
   - Set the second last node's link to head (removing the last node).
   - Free the last node and return the unchanged head.
*/
NODE *delete_last_node(NODE *head)
{
    if (head == NULL)
    {
        printf("List is empty. Nothing to delete.\n");
        return head;
    }

    if (head->link == head) // Only one node in the list
    {
        free(head);
        return NULL;
    }

    // More than one node in the list
    NODE *temp = head;
    while (temp->link->link != head)
    {
        temp = temp->link;
    }

    free(temp->link);
    temp->link = head;
    return head;
}

// Print the circular linked list
/*
1. If the list is empty (head is NULL), print a message indicating so.
2. Otherwise, traverse through the list starting from the head.
3. Print each node's data until the head is reached again, indicating it's a circular list.
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
        printf("%d -> ", temp->data);
        temp = temp->link;
    } while (temp != head);
    printf("(back to head)\n");
}

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

    // Print the circular linked list
    print_list(head);

    // Delete first node
    head = delete_first_node(head);
    print_list(head);

    // Delete last node
    head = delete_last_node(head);
    print_list(head);

    return 0;
}
