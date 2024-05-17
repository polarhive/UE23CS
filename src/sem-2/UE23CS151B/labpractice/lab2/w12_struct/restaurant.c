// Create a Structure called Restaurant with following members:
// • c_name (representing Customer Name, white spaces are allowed)
// • Table number (representing unique table number for a given customer)
// • Food as a nested structure with members as:
// o Food name (white spaces are allowed)
// o number of plates ordered (integer)
// o cost per plate (floating point).
// Write
// 1. A function to read details from the user.
// 2. A function to display all the details entered by the user.
// 3. A function to Calculate the bill and display the total cost up to 2 decimal places.
// Total cost = (Cost per plate * Number of plates) + Tax
// where, tax is calculated as Table number * 10

#include <stdio.h>
struct Food
{
    char name[500];
    int num_plates;
    float cost_per_plate;
};
struct Restaurant
{
    char c_name[500];
    int table_number;

    struct Food food_details;
};
struct Restaurant read_details();
void display_details(struct Restaurant rest);
void calculate_bill(struct Restaurant rest);
int main()
{
    struct Restaurant customer = read_details();
    display_details(customer);
    calculate_bill(customer);
    return 0;
}

struct Restaurant read_details()
{
    struct Restaurant rest;
    scanf(" %[^\n]s", rest.c_name);
    scanf("%d", &rest.table_number);
    scanf(" %[^\n]s", rest.food_details.name);
    scanf("%d", &rest.food_details.num_plates);
    scanf("%f", &rest.food_details.cost_per_plate);
    return rest;
}
void display_details(struct Restaurant rest)
{
    printf("Customer Name: %s\n", rest.c_name);
    printf("Table Number: %d\n", rest.table_number);
    printf("Food Name: %s\n", rest.food_details.name);
    printf("Number of Plates: %d\n", rest.food_details.num_plates);
    printf("Cost per Plate: Rs %.2f\n", rest.food_details.cost_per_plate);
}
void calculate_bill(struct Restaurant rest)
{
    float tax = rest.table_number * 10;
    float total_bill = (rest.food_details.cost_per_plate *
                        rest.food_details.num_plates) +
                       tax;
    printf("Total Cost: Rs %.2f\n", total_bill);
}