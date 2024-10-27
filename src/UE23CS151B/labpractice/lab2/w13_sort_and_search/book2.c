// Create a Structure called Book with following members: ISBN, book_name,
// no_of_pages, publication_year.
// Write a program in C that
// 1. reads an integer ‘n’ (representing the number of books)
// 2. implements a function to read details of ‘n’ books from the user (Array
// of Structures).
// 3. read an integer ‘isbn’ (representing the book ISBN, that has to be
// searched in the ‘n’ books’ details)
// 4. using the binary search technique, implement a function to perform
// search operation based on ‘isbn’. If the search is successful, function
// should display the Book details for that ISBN, otherwise display the
// message “No Book details found for the given ISBN”.

#include <stdio.h>
struct Book
{
    int ISBN;
    char book_name[50];
    int no_of_pages;
    int publication_year;
};
void read(struct Book b[], int n);
void binarySearch(struct Book b[], int l, int r, int isbn);
int main()
{
    struct Book b[10];
    int n, isbn;
    scanf("%d", &n);
    read(b, n);
    scanf("%d", &isbn);
    binarySearch(b, 0, n - 1, isbn);
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
void binarySearch(struct Book b[], int l, int r, int isbn)
{
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (isbn == b[mid].ISBN)
        {
            printf("Book details found for given ISBN\n");
            printf("ISBN: %d\n", b[mid].ISBN);
            printf("Book Name: %s\n", b[mid].book_name);
            printf("Num of pages: %d\n", b[mid].no_of_pages);
            printf("Publication Year: %d\n", b[mid].publication_year);
            return;
        }

        if (isbn > b[mid].ISBN)
            l = mid + 1;
        else
            r = mid - 1;
    }
    printf("No Book details found for the given ISBN");
}