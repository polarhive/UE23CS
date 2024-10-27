// Create a structure called Library with the following members:
// a) book_id (int) - representing Book ID
// b) book_name (string) - representing Book’s Name
// c) borrower_name (string) - representing name of the book borrower
// d) no_of_days (int) – representing number of days since borrowed

// Using the array of Structures, sort the structures in the array based on the data member
// – book_id (Bubble sort Technique)
// Write a program in C that
// 1. reads an integer ‘n’ (representing the number of books)
// 2. use a function to read details of ‘n’ books
// 3. use a function to display details of all books - before sorting
// 4. implement sort operation using a function
// 5. use the function to display details of all books - after sorting

#include <stdio.h>
struct Library
{
    int book_id;
    char book_name[50];
    char borrower_name[50];
    int no_of_days;
};
void read(struct Library lib[], int n)
{
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &lib[i].book_id);
        scanf(" %s", lib[i].book_name);
        scanf(" %s", lib[i].borrower_name);
        scanf("%d", &lib[i].no_of_days);
    }
}
void display(struct Library lib[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d %s %s %d\n", lib[i].book_id, lib[i].book_name, lib[i].borrower_name, lib[i].no_of_days);
    }
}
void sort(struct Library lib[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)

        {
        }
    }
    if (lib[j].book_id > lib[j + 1].book_id)
    {
        struct Library t;
        t = lib[j + 1];
        lib[j + 1] = lib[j];
        lib[j] = t;
    }
}

int main()
{
    struct Library lib[10];
    int n;
    scanf("%d", &n);
    read(lib, n);
    printf("Before Sorting:\n");
    display(lib, n);
    sort(lib, n);
    printf("After Sorting:\n");
    display(lib, n);

    return 0;
}
