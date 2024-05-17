// You are tasked with developing a program to manage bank accounts. Each
// bank account holds essential information about the account holder,
// including their account number, name, balance, and personal details such
// as date of birth, phone number, and email address.
// Write a structure BankAccount with following members:
// 1. Account Number
// 2. Account Holder Name
// 3. Initial Balance
// 4. PersonalInfo as Nested Structure with members, date of birth(consider as
// character array), mobile number (consider as character array), email ID
// (consider as character array)
// Write a C program that implements
// 1. A function to read details of the BankAccount from the user
// 2. A function to perform withdrawal of the amount given by the user - Display the
// message “Insufficient balance.” if the amount to be withdrawn is greater than the
// initial balance.
// 3. A function to display the details of the BankAccount after withdrawal

#include <stdio.h>
// Structure definition for personal information
struct PersonalInfo
{
    char date_of_birth[15];
    char mob_number[15];
    char email[50];
};
// Structure definition for bank account
struct BankAccount
{
    int account_number;
    char account_holder_name[50];
    float balance;
    struct PersonalInfo p; // Nested structure for personal information
};
// Function to input details for a single bank account
struct BankAccount input_customer_details()
{
    struct BankAccount b;
    scanf("%d", &b.account_number);
    scanf(" %[^\n]s", b.account_holder_name);
    scanf("%f", &b.balance);
    scanf("%s", b.p.date_of_birth);
    scanf("%s", b.p.mob_number);
    scanf("%s", b.p.email);
    return b;
}

// Function to display details of a bank account
void display_Account_details(struct BankAccount b)
{
    printf("Account Number: %d\n", b.account_number);
    printf("Account Holder Name: %s\n", b.account_holder_name);
    printf("Balance: %.2f\n", b.balance);
    printf("Date of Birth: %s\n", b.p.date_of_birth);
    printf("Phone Number: %s\n", b.p.mob_number);
    printf("Email: %s\n", b.p.email);
}
// Function to withdraw money from a bank account
void withdraw(struct BankAccount *b, float amount)
{

    if (amount > b->balance)
        printf("Insufficient balance.\n");
    else
    {
        b->balance = b->balance - amount;
        printf("Withdrawal of %.2f successful.\n", amount);
    }
}
int main()
{
    float withdrawal_amount;
    // Example usage: Creating a bank account from user input
    struct BankAccount b = input_customer_details();
    // Performing transaction
    scanf("%f", &withdrawal_amount);
    withdraw(&b, withdrawal_amount);
    display_Account_details(b);
    return 0;
}