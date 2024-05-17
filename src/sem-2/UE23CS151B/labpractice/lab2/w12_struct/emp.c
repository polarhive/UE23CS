// Create a structure called Employee with the following members:
// a. id (int) - representing Employee ID
// b. name (string) - representing Employee Name
// c. phone (structure)
// i. current (long long int) - representing current mob number of
// Employee
// ii. alternate (long long int) - representing alternate mob number
// of Employee
// d. salary (float) - representing Total Salary of Employee
// Write a program in C to implement
// 1. A function to read details of an Employee from the user.
// 2. A function to display all the details of an Employee.
// 3. A function to calculate the income of an employee after deduction of tax. (If the
// salary is less than or equal to 1,00,000, tax is 5%. If the salary is more than
// 1,00,000 and less than or equal to 10,00,000, tax is 10%. If the salary is more
// than 10,00,000, the tax is 20%)

#include <stdio.h>
struct Employee
{
    int id;
    char name[100];
    struct phone
    {
        long long int current;
        long long int alternate;
    } p;
    float salary;
};
void read(struct Employee *emp)
{
    scanf("%d", &emp->id);
    scanf("%s", emp->name);
    scanf("%lld", &emp->p.current);
    scanf("%lld", &emp->p.alternate);
    scanf("%f", &emp->salary);
}
void display(struct Employee emp)
{
    printf("ID: %d\n", emp.id);
    printf("Name: %s\n", emp.name);
    printf("Current Mob number: %lld\n", emp.p.current);
    printf("Alternate Mob number: %lld\n", emp.p.alternate);
    printf("Total Salary: %.2f\n", emp.salary);
}

float calculate_income(struct Employee emp)
{
    float tax;
    if (emp.salary <= 100000)
        tax = 0.05;
    else if (emp.salary > 100000 && emp.salary <= 1000000)
        tax = 0.10;
    else
        tax = 0.20;
    float actual_salary = emp.salary - (emp.salary * tax);
    return actual_salary;
}

int main()
{
    struct Employee emp;
    read(&emp);
    display(emp);
    printf("After deduction: %.2f\n", calculate_income(emp));
    return 0;
}