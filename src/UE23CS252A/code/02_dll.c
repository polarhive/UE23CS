#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *llink;
    struct node *rlink;
};

typedef struct node Node;

// Function prototypes
Node *create_node(int data);
Node *insert_at_beginning(Node *head, int data);
Node *insert_at_end(Node *head, int data);
Node *insert_at_position(Node *head, int data, int position);
Node *delete_first_node(Node *head);
Node *delete_last_node(Node *head);
Node *delete_at_position(Node *head, int position);
void display_list(Node *head);

// Function to create a new node
Node *create_node(int data)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    if (!new_node)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }
    new_node->data = data;
    new_node->llink = NULL;
    new_node->rlink = NULL;
    return new_node;
}

// Insert at the beginning
Node *insert_at_beginning(Node *head, int data)
{
    Node *new_node = create_node(data);
    if (head)
    {
        new_node->rlink = head;
        head->llink = new_node;
    }
    return new_node;
}

// Insert at the end
Node *insert_at_end(Node *head, int data)
{
    Node *new_node = create_node(data);
    if (!head)
    {
        return new_node;
    }
    Node *temp = head;
    while (temp->rlink)
    {
        temp = temp->rlink;
    }
    temp->rlink = new_node;
    new_node->llink = temp;
    return head;
}

// Insert at a given position
Node *insert_at_position(Node *head, int data, int position)
{
    if (position < 1)
    {
        printf("Invalid position\n");
        return head;
    }

    if (position == 1)
    {
        return insert_at_beginning(head, data);
    }

    Node *new_node = create_node(data);
    Node *temp = head;
    for (int i = 1; i < position - 1 && temp; i++)
    {
        temp = temp->rlink;
    }

    if (!temp)
    {
        printf("Position out of bounds\n");
        free(new_node);
        return head;
    }

    new_node->rlink = temp->rlink;
    new_node->llink = temp;
    if (temp->rlink)
    {
        temp->rlink->llink = new_node;
    }
    temp->rlink = new_node;
    return head;
}

// Delete the first node
Node *delete_first_node(Node *head)
{
    if (!head)
    {
        printf("List is empty\n");
        return NULL;
    }
    Node *temp = head;
    head = head->rlink;
    if (head)
    {
        head->llink = NULL;
    }
    free(temp);
    return head;
}

// Delete the last node
Node *delete_last_node(Node *head)
{
    if (!head)
    {
        printf("List is empty\n");
        return NULL;
    }

    Node *temp = head;
    while (temp->rlink)
    {
        temp = temp->rlink;
    }

    if (temp->llink)
    {
        temp->llink->rlink = NULL;
    }
    else
    {
        head = NULL;
    }
    free(temp);
    return head;
}

// Delete a node at a given position
Node *delete_at_position(Node *head, int position)
{
    if (position < 1 || !head)
    {
        printf("Invalid position or list is empty\n");
        return head;
    }

    if (position == 1)
    {
        return delete_first_node(head);
    }

    Node *temp = head;
    for (int i = 1; i < position && temp; i++)
    {
        temp = temp->rlink;
    }

    if (!temp)
    {
        printf("Position out of bounds\n");
        return head;
    }

    if (temp->rlink)
    {
        temp->rlink->llink = temp->llink;
    }
    if (temp->llink)
    {
        temp->llink->rlink = temp->rlink;
    }
    free(temp);
    return head;
}

// Display the list
void display_list(Node *head)
{
    if (!head)
    {
        printf("List is empty\n");
        return;
    }
    Node *temp = head;
    while (temp)
    {
        printf("%d ", temp->data);
        temp = temp->rlink;
    }
    printf("\n");
}

// Main function for testing
int main()
{
    Node *head = NULL;

    head = insert_at_beginning(head, 10);
    head = insert_at_end(head, 20);
    head = insert_at_end(head, 30);
    head = insert_at_position(head, 15, 2);
    display_list(head);

    head = delete_first_node(head);
    display_list(head);

    head = delete_last_node(head);
    display_list(head);

    head = delete_at_position(head, 2);
    display_list(head);

    return 0;
}
