// Create a Structure called Book with following members: ISBN, book_name,
// no_of_pages, publication_year.
// Using the array of Structures, sort the structures in the array based on the data
// member – ISBN (Bubble sort Technique)
// Write a program in C that
// 1. reads an integer ‘n’ (representing the number of books)
// 2. use a function to read details of ‘n’ books
// 3. use a function to display details of all books - before sorting
// 4. implement sort operation using a function
// 5. use the function to display details of all books - after sorting

#include <stdio.h>
struct Book
{
    int ISBN;
    char book_name[50];
    int no_of_pages;
    int publication_year;
};
void read(struct Book b[], int n);
void display(struct Book b[], int n);
void sort(struct Book b[], int n);
int main()
{
    struct Book b[10];
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
void read(struct Book b[], int n)
{
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &b[i].ISBN);
        scanf(" %s", b[i].book_name);
        scanf("%d", &b[i].no_of_pages);
        scanf("%d", &b[i].publication_year);
    }
}
void display(struct Book b[], int n)
{
    for (int i = 0; i < n; i++)
    {

        printf("%d %s %d %d\n", b[i].ISBN, b[i].book_name, b[i].no_of_pages, b[i].publication_year);
    }
}
void sort(struct Book b[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (b[j].ISBN > b[j + 1].ISBN)
            {
                struct Book t;
                t = b[j + 1];
                b[j + 1] = b[j];
                b[j] = t;
            }
        }
    }
}