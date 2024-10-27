// Create a structure called Employee with the following members:
// a) id (int) - representing Employee ID
// b) name (string) - representing Employee Name
// c) salary (float) - representing Total Salary of Employee
// Using the array of Structures, sort the structures in the array based on the data member
// – id (Bubble sort Technique)
// Write a program in C that
// 1. reads an integer ‘n’ (representing the number of employees)
// 2. use a function to read details of ‘n’ employees
// 3. use a function to display details of all employees - before sorting
// 4. implement sort operation using a function
// 5. use the function to display details of all employees - after sorting

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
void display(struct Employee *emp, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d %s %.2f\n", emp[i].id, emp[i].name, emp[i].salary);
    }
}
void sort(struct Employee *emp, int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (emp[j].id > emp[j + 1].id)
            {
                struct Employee t;
                t = emp[j + 1];
                emp[j + 1] = emp[j];
                emp[j] = t;
            }
        }
    }
}
int main()
{
    struct Employee emp[10];
    int n;

    scanf("%d", &n);
    read(emp, n);
    printf("Before Sorting:\n");
    display(emp, n);
    sort(emp, n);
    printf("After Sorting:\n");
    display(emp, n);

    return 0;
}