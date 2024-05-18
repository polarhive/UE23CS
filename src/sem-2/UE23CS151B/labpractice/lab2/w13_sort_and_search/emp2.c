// Create a structure called Employee with the following members:
// a) id (int) - representing Employee ID
// b) name (string) - representing Employee Name
// c) salary (float) - representing Total Salary of Employee
// Write a program in C that
// 1. reads an integer ‘n’ (representing the number of employees)
// 2. implements a function to read details of ‘n’ Employees from the user (Array of
// Structures).
// 3. read an integer ‘id’ (representing the Employee ID, that has to be searched in the
// ‘n’ Employees details)
// 4. using the binary search technique, implement a function to perform search
// operation based on ‘id’. If the search is successful, function should display the
// Employee details for that ID, otherwise display the message “No Employee details
// found for the given ID”.

#include <stdio.h>
struct Employee
{
    int id;
    char name[100];
    float salary;
};
void read(struct Employee *emp, int n)
{
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &emp[i].id);
        scanf("%s", emp[i].name);
        scanf("%f", &emp[i].salary);
    }
}
void binarySearch(struct Employee *emp, int l, int r, int id)
{
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (emp[mid].id == id)
        {
            printf("Employee details found for given ID\n");
            printf("ID: %d\n", emp[mid].id);
            printf("Name: %s\n", emp[mid].name);
            printf("Salary: %.2f\n", emp[mid].salary);
        }
        return;
        if (id > emp[mid].id)
            l = mid + 1;
        else
            r = mid - 1;
    }
    printf("No Employee details found for the given ID");
}
int main()
{
    struct Employee emp[100];
    int n, id;
    scanf("%d", &n);
    read(emp, n);
    scanf("%d", &id);
    binarySearch(emp, 0, n - 1, id);

    return 0;
}