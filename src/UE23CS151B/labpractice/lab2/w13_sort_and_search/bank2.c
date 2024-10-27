// Create a structure BankAccount with following members:
// a) Account Number (int)
// b) Account Holder Name (String)
// c) Initial Balance (float)
// Write a program in C that
// 1. reads an integer ‘n’ (representing the number of accounts)
// 2. implements a function to read details of ‘n’ accounts from the user (Array of
// Structures).
// 3. read an integer ‘accNum’ (representing the account number, that has to be
// searched in the ‘n’ accounts’ details
// 4. using the binary search technique, implement a function to perform search
// operation based on ‘accNum’. If the search is successful, function should display
// the account details for that account number, otherwise display the message “No
// Account details found for the given number”.

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
void binarySearch(struct BankAccount b[], int l, int r, int accNum)
{
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (accNum == b[mid].acc_no)
        {
            printf("Account details found\n");
            printf("Account Number: %d\n", b[mid].acc_no);
            printf("Account Holder Name: %s\n", b[mid].acc_holder_name);
            printf("Initial Balance: %f\n", b[mid].initial_balance);
        }
        return;
        if (accNum > b[mid].acc_no)
            l = mid + 1;
        else
            r = mid - 1;
    }
    printf("No Account details found for the given number");
}
int main()
{
    struct BankAccount b[10];
    int n, accNum;
    scanf("%d", &n);
    read(b, n);
    scanf("%d", &accNum);
    binarySearch(b, 0, n - 1, accNum);
    return 0;
}