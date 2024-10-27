// Create a structure BankAccount with following members:
// a) Account Number (int)
// b) Account Holder Name (String)
// c) Initial Balance (float)
// Using the array of Structures, sort the structures in the array based on the data member
// – Account Number (Bubble sort Technique)
// Write a program in C that
// 1. reads an integer ‘n’ (representing the number of accounts)
// 2. use a function to read details of ‘n’ accounts
// 3. use a function to display details of all accounts - before sorting
// 4. implement sort operation using a function
// 5. use the function to display details of all accounts - after sorting

#include <stdio.h>
struct BankAccount
{
    int acc_no;
    char acc_holder_name[50];
    float initial_balance;
};
void read(struct BankAccount b[], int n)
{
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &b[i].acc_no);
        scanf(" %s", b[i].acc_holder_name);
        scanf(" %f", &b[i].initial_balance);
    }
}

void display(struct BankAccount b[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d %s %f\n",
               b[i].acc_no, b[i].acc_holder_name, b[i].initial_balance);
    }
}
void sort(struct BankAccount b[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (b[j].acc_no > b[j + 1].acc_no)
            {
                struct BankAccount t;
                t = b[j + 1];
                b[j + 1] = b[j];
                b[j] = t;
            }
        }
    }
}
int main()
{
    struct BankAccount b[10];
    int n;
    scanf("%d", &n);
    read(b, n);
    printf("Before Sorting:\n");
    display(b, n);
    sort(b, n);
    printf("After Sorting:\n");
    display(b, n);

    return 0;
}