#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *prev;
    struct node *next;
} Node;
Node *createNode(int data);
Node *insert_start(Node *head, int data);
Node *insert_pos(Node *head, int data, int pos);
Node *insert_End(Node *head, int data);
void display(Node *head);
Node *delete_start(Node *head);
Node *delete_pos(Node *head, int pos);
Node *delete_End(Node *head);
int search(Node *head, int data);
Node *createNode(int data)
{
    Node *nn = (Node *)malloc(sizeof(Node));
    nn->data = data;
    nn->prev = NULL;
    nn->next = NULL;
    return nn;
}
Node *insert_start(Node *head, int data)
{
    Node *temp = head, *nn;
    nn = createNode(data);
    if (head == NULL)
    {
        head = nn;
    }
    else
    {
        nn->next = head;
        head->prev = nn;
        head = nn;
    }
    return head;
}
Node *insert_pos(Node *head, int data, int pos)
{
    Node *temp = head, *nn;
    int i = 1;
    nn = createNode(data);
    if (head == NULL)
        head = nn;
    else if (pos == 1)
    {
        nn->next = head;
        head->prev = nn;
        head = nn;
    }
    else
    {
        temp = head;
        while (temp->next != NULL && i < pos)
        {
            temp = temp->next;
            i++;
        }
        if (temp->next == NULL)
        {
            temp->next = nn;
            nn->prev = temp;
        }
        else
        {
            nn->next = temp;
            nn->prev = temp->prev;
            temp->prev->next = nn;
            temp->prev = nn;
        }
    }
    return head;
}
Node *insert_end(Node *head, int data)
{
    Node *temp = head, *nn;
    nn = createNode(data);
    if (head == NULL)
        head = nn;
    else
    {
        temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = nn;
        nn->prev = temp;
    }
    return head;
}
Node *delete_start(Node *head)
{
    Node *temp = head;
    if (head == NULL)
        printf("\nThis is an Empty List");
    else if (head->next == NULL)
    { // One Element
        free(temp);
        head = NULL;
    }
    else
    {
        head = head->next;
        head->prev = NULL;
        temp->next = NULL;
        free(temp);
    }
    return head;
}
Node *delete_pos(Node *head, int pos)
{
    Node *temp = head;
    int i = 1;
    if (pos == 1)
        head = delete_start(head);
    else if (pos > 1)
    {
        while (temp->next != NULL && i < pos)
        {
            i++;
            temp = temp->next;
        }

        if (temp->next == NULL)
        {
            if (temp == head)
            {
                head = NULL;
            }
            else
            {
                temp->prev->next = NULL;
                temp->prev = NULL;
            }
        }
        else
        {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            temp->next = temp->prev = NULL;
        }
        free(temp);
    }
    return head;
}
Node *delete_end(Node *head)
{
    Node *temp = head;
    if (head == NULL)
        printf("The list is empty");
    else
    {
        while (temp->next != NULL)
            temp = temp->next;
        if (temp == head)
        {
            head = NULL;
        }
        else
        {
            temp->prev->next = NULL;
            temp->prev = NULL;
        }
        free(temp);
    }
    return head;
}
void display(Node *head)
{
    Node *temp = head;
    if (head == NULL)
        printf("\nThe List is empty");
    else
    {
        while (temp->next != NULL)
        {
            printf("%d->", temp->data);
            temp = temp->next; // Important otherwise infinite loop
        }
        printf("%d->NULL", temp->data);
    }
}
int search(Node *head, int data)
{
    int pos = 0;
    Node *temp = head;
    if (head == NULL)
    {
        printf("The List is Empty");
        return 0;
    }
    do
    {
        pos++;
        if (temp->data == data)
        {
            return pos;
        }
        temp = temp->next;
    } while (temp != NULL);
    return 0;
}

int main()
{
    Node *head = NULL;
    int cont, ch, data, pos;
    do
    {
        printf("\nEnter your choice;");
        printf("\n1.Insertion at the beginning");
        printf("\n2.Insertion at the Position");
        printf("\n3.Insertion at the End");
        printf("\n4.Deletion at the beginning");
        printf("\n5.Deletion at the Position");
        printf("\n6.Deletion at the End");
        printf("\n7.Search for the data");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\nEnter the data to be inserted:");
            scanf("%d", &data);
            head = insert_start(head, data);
            display(head);
            break;
        case 2:
            printf("\nEnter the data to be inserted:");
            scanf("%d", &data);
            printf("\nEnter the position to be inserted:");
            scanf("%d", &pos);
            head = insert_pos(head, data, pos);
            display(head);
            break;
        case 3:
            printf("\nEnter the data to be inserted:");
            scanf("%d", &data);
            head = insert_end(head, data);
            display(head);
            break;
        case 4:
            head = delete_start(head);
            display(head);
            break;
        case 5:
            printf("\nEnter the position to be deleted:");
            scanf("%d", &pos);
            head = delete_pos(head, pos);
            display(head);
            break;
        case 6:
            head = delete_end(head);
            display(head);
            break;
        case 7:
            printf("\nEnter the data to be searched: ");
            scanf("%d", &data);
            pos = search(head, data);
            if (pos > 0)
                printf("\nThe data is found at position %d", pos);
            else
                printf("\nThe data is not found");
            break;
        default:
            printf("\nWrong Choice");
        }
        printf("\nPress 1 to continue and 0 to Exit");
        scanf("%d", &cont);
    } while (cont);
    return 0;
}
