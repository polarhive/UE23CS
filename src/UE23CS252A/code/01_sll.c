#include <stdio.h>
#include <stdlib.h>

struct node
{
  int data;
  struct node *link;
};
typedef struct node NODE;

// Insert at the beginning
/*
1. Insertion at the beginning:
   - Create a node
   - If the list is empty:
     - Make the head pointer point towards the new node
   - Else:
     - Make the next pointer of the node point towards the first node of the list
     - Make the head pointer point towards this new node
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
  new_node->link = head;
  return new_node;
}

// Insert at the end
/*
2. Insertion at the end:
   - Create a node
   - If the list is empty:
     - Make the head pointer point towards the new node
   - Else:
     - Traverse the list to the last node
     - Make the last node's next pointer point towards the new node
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
  new_node->link = NULL;

  if (head == NULL)
  {
    return new_node; // If the list is empty
  }

  NODE *temp = head;
  while (temp->link != NULL)
  {
    temp = temp->link;
  }
  temp->link = new_node;
  return head;
}

// Insert at a specific position
/*
3. Insertion at a specific position:
   - Create a node
   - If position is invalid (less than 1):
     - Print an error message
     - Return the original list
   - If inserting at position 1:
     - Make the next pointer of the new node point to the head
     - Update the head to point to the new node
   - Else:
     - Traverse the list to the (position-1)th node
     - If the (position-1)th node is NULL:
       - Print an error message (position out of range)
       - Free the new node
     - Else:
       - Make the new node's next pointer point to the (position-1)th node's next pointer
       - Update the (position-1)th node's next pointer to point to the new node
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

  if (position == 1)
  { // Insert at the beginning
    new_node->link = head;
    return new_node;
  }

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

// Delete the first node
/*
1. Deleting the first node:
   - If the list is empty:
     - Print an error message
   - Else:
     - Store the head pointer in a temporary variable
     - Move the head pointer to the next node
     - Free the temporary variable
*/
NODE *delete_first_node(NODE *head)
{
  if (head == NULL)
  {
    printf("List is empty. Nothing to delete.\n");
    return head;
  }

  NODE *temp = head;
  head = head->link;
  free(temp);
  return head;
}

// Delete the last node
/*
2. Deleting the last node:
   - If the list is empty:
     - Print an error message
   - Else if the list has only one node:
     - Free the head pointer
     - Set head to NULL
   - Else:
     - Traverse the list to the second last node
     - Free the last node
     - Set the second last node's next pointer to NULL
*/
NODE *delete_last_node(NODE *head)
{
  if (head == NULL)
  {
    printf("List is empty. Nothing to delete.\n");
    return head;
  }

  if (head->link == NULL)
  { // Only one node in the list
    free(head);
    return NULL;
  }

  NODE *temp = head;
  while (temp->link->link != NULL)
  {
    temp = temp->link;
  }

  free(temp->link);
  temp->link = NULL;
  return head;
}

// Delete a node at a specific position
/*
3. Deleting a node at a specific position:
   - If position is invalid (less than 1):
     - Print an error message
   - If deleting the first node:
     - Call delete_first_node function
   - Else:
     - Traverse the list to the (position-1)th node
     - If the (position-1)th node or its next node is NULL:
       - Print an error message (position out of range)
     - Else:
       - Store the pointer to the node to be deleted
       - Update the (position-1)th node's next pointer to skip the node to be deleted
       - Free the node to be deleted
*/
NODE *delete_at_position(NODE *head, int position)
{
  if (position < 1)
  {
    printf("Invalid position\n");
    return head;
  }

  if (position == 1)
  {
    return delete_first_node(head);
  }

  NODE *temp = head;
  for (int i = 1; i < position - 1 && temp != NULL; i++)
  {
    temp = temp->link;
  }

  if (temp == NULL || temp->link == NULL)
  {
    printf("Position out of range\n");
    return head;
  }

  NODE *node_to_delete = temp->link;
  temp->link = node_to_delete->link;
  free(node_to_delete);
  return head;
}

// Print the linked list
/*
4. Print the linked list:
   - Initialize a temporary pointer to the head
   - While the temporary pointer is not NULL:
     - Print the data of the current node
     - Move to the next node
   - Print "NULL" to indicate the end of the list
*/
void print_list(NODE *head)
{
  NODE *temp = head;
  while (temp != NULL)
  {
    printf("%d -> ", temp->data);
    temp = temp->link;
  }
  printf("NULL\n");
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

  // Print the linked list
  print_list(head);

  // Delete first node
  head = delete_first_node(head);
  print_list(head);

  // Delete last node
  head = delete_last_node(head);
  print_list(head);

  // Delete node at position 2
  head = delete_at_position(head, 2);
  print_list(head);

  return 0;
}
