#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 100

typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
    float salary;
} Employee;

void addEmployee(Employee **employees, int *size, int id, const char *name, float salary) {
    // Allocate memory for a new employee
    Employee *temp = realloc(*employees, (*size + 1) * sizeof(Employee));
    if (temp == NULL) {
        printf("Error\n");
        return;
    }
    *employees = temp;

    // Assign the new employee's details
    (*employees)[*size].id = id;
    strncpy((*employees)[*size].name, name, MAX_NAME_LENGTH);
    (*employees)[*size].salary = salary;
    
    // Increment the size
    (*size)++;
    printf("Successfully added\n");
}

void updateSalary(Employee *employees, int size, int id, float newSalary) {
    for (int i = 0; i < size; i++) {
        if (employees[i].id == id) {
            employees[i].salary = newSalary;
            printf("Successfully updated\n");
            return;
        }
    }
    printf("Error\n");
}

void displayEmployees(Employee *employees, int size) {
    if (size == 0) {
        printf("No Employees Found\n");
        return;
    }
    
    for (int i = 0; i < size; i++) {
        printf("ID: %d, Name: %s, Salary: %.2f\n", employees[i].id, employees[i].name, employees[i].salary);
    }
}

int main() {
    Employee *employees = NULL;
    int size = 0;
    int choice;
    int id;
    char name[MAX_NAME_LENGTH];
    float salary;

    while (1) {
        scanf("%d", &choice);
        getchar();  // Consume newline character

        switch (choice) {
            case 1:
                scanf("%d", &id);
                getchar();  // Consume newline character
                
                fgets(name, MAX_NAME_LENGTH, stdin);
                name[strcspn(name, "\n")] = '\0';  // Remove newline character
                
                scanf("%f", &salary);
                addEmployee(&employees, &size, id, name, salary);
                break;

            case 2:
                scanf("%d", &id);
                
                scanf("%f", &salary);
                updateSalary(employees, size, id, salary);
                break;

            case 3:
                displayEmployees(employees, size);
                break;
                
            case 4:
                free(employees);
                return 0;
                
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
}
