// Create a Structure called library with following members
// CustomerName as a nested structure containing first name, middle name and last
// name as its members.
// book_id (an integer representing the book ID)
// book_name (the name of the book borrowed by the customer),
// book_author (the name of the book author),
// days (number of days since borrowed) .
// Write
// 1. A function to read all details from the user.
// 2. A function to display all the details entered by the user.
// 3. A function to calculate the fine on a book (if the days <= 7 then the fine = 0, but if the
// days >7 then for every additional day there is a fine of 20 rupees).

#include <stdio.h>
typedef struct Lib
{
    struct Customer_Name
    {
        char first_name[20];
        char mid_name[20];
        char last_name[20];
    } c;
    int book_id;
    char book_name[100];
    char book_author[50];
    int days; // Number of days since borrowing
} Library;
void read_details(Library *p)
{
    scanf(" %s", p->c.first_name);
    scanf(" %s", p->c.mid_name);
    scanf(" %s", p->c.last_name);
    scanf(" %d", &p->book_id);
    scanf(" %[^\n]s", p->book_name);
    scanf(" %[^\n]s", p->book_author);
    scanf(" %d", &p->days);
}
void display_details(Library lb)
{
    printf("Customer Name: %s %s %s\n", lb.c.first_name, lb.c.mid_name,
           lb.c.last_name);
    printf("Book ID: %d\n", lb.book_id);

    printf("Book Name: %s\n", lb.book_name);
    printf("Book Author: %s\n", lb.book_author);
    printf("Days since borrowing: %d\n", lb.days);
}
void calculate_fine(Library lb)
{
    // Calculate fine for each extra day
    float fine = 0;
    if (lb.days > 7)
        fine = (lb.days - 7) * 20.0;
    printf("Fine: %.2f rupees\n", fine);
}
int main()
{
    Library lib_var;
    read_details(&lib_var);
    display_details(lib_var);
    calculate_fine(lib_var);

    return 0;
}