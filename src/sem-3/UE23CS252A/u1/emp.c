#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Employee
{
    int id;
    char name[50];
    struct Employee *next;
} Employee;

void insert(Employee **head, int id, const char *name)
{
    Employee *newEmployee = (Employee *)malloc(sizeof(Employee));
    newEmployee->id = id;
    strcpy(newEmployee->name, name);
    newEmployee->next = NULL;

    if (*head == NULL)
    {
        *head = newEmployee;
    }
    else
    {
        Employee *temp = *head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newEmployee;
    }
}

void display(Employee *head)
{
    Employee *temp = head;
    while (temp != NULL)
    {
        printf("ID: %d, Name: %s\n", temp->id, temp->name);
        temp = temp->next;
    }
}

int main()
{
    Employee *head = NULL;

    insert(&head, 1, "John Doe");
    insert(&head, 2, "Jane Smith");
    insert(&head, 3, "Mike Johnson");

    display(head);

    return 0;
}
