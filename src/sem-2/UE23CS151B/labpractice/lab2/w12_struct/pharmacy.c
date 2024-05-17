// Aastha Create a Structure called pharmacy with following members med_code (string):
// Unique code for the medicine (5 characters). med_name (string): Name of the medicine
// (1-50 characters). quantity (integer): quantity of the medicine purchased. price (float):
// Price per unit of the medicine.
// Write
// 1. A function to read details from the user.
// 2. A Function to display all the details entered by the user.
// 3. A function to Calculate the bill (Note:- if the bill goes beyond 200, give a discount of
// 20% on the bill) and display the total cost up to 2 decimal places.

#include <stdio.h>
#include <string.h>
struct pharmacy
{
    char med_code[6];
    char med_name[51];
    int quantity;
    float price;
};

void read_details(struct pharmacy *medicines, int n)
{
    for (int i = 0; i < n; i++)
    {
        scanf("%5s %50s %d %f", medicines[i].med_code,
              medicines[i].med_name, &medicines[i].quantity, &medicines[i].price);
    }
}
void display_details(struct pharmacy *medicines, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("Medicine Code: %s\n", medicines[i].med_code);
        printf("Medicine Name: %s\n", medicines[i].med_name);
        printf("Quantity of Medicine: %d\n", medicines[i].quantity);
        printf("Cost per Medicine: Rs %.2f\n", medicines[i].price);
        printf("Total Cost: Rs %.2f\n", medicines[i].quantity * medicines[i].price);
    }
}
void calculate_bill(struct pharmacy *medicines, int n)
{
    float total_cost = 0;
    for (int i = 0; i < n; i++)
    {
        total_cost += medicines[i].quantity * medicines[i].price;
    }

    if (total_cost > 200)
    {
        total_cost *= 0.8; // 20% discount
    }
    printf("Total Cost: Rs %.2f\n", total_cost);
}
int main()
{
    struct pharmacy medicines[100];
    int n = 1; // Number of medicines, you can change this to however many medicines you want to input
    read_details(medicines, n);
    display_details(medicines, n);
    calculate_bill(medicines, n);
    return 0;
}