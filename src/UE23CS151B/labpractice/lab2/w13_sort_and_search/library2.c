// Create a structure called Library with the following members:
// a) book_id (int) - representing Book ID
// b) book_name (string) - representing Book’s Name
// c) borrower_name (string) - representing name of the book borrower
// d) no_of_days (int) – representing number of days since borrowed
// Write a program in C that
// 1. reads an integer ‘n’ (representing the number of books)
// 2. implements a function to read details of ‘n’ books from the user (Array of
// Structures).
// 3. read an integer ‘id’ (representing the book ID, that has to be searched in the ‘n’
// books’ details)
// 4. using the binary search technique, implement a function to perform search
// operation based on ‘id’. If the search is successful, function should display the Book
// details for that ID, otherwise display the message “No Book details found for the
// given ID”

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
void binarySearch(struct Library lib[], int l, int r, int id)
{
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (id == lib[mid].book_id)
        {
            printf("Book details found for given ID\n");
            printf("ID: %d\n", lib[mid].book_id);
            printf("Book Name: %s\n", lib[mid].book_name);
            printf("Borrower's Name: %s\n",
                   lib[mid].borrower_name);
            printf("Num of days: %d\n", lib[mid].no_of_days);
        }
        return;
        if (id > lib[mid].book_id)
            l = mid + 1;
        else
            r = mid - 1;
    }
    printf("No Book details found for the given ID");
}
int main()
{
    struct Library lib[10];
    int n, id;
    scanf("%d", &n);
    read(lib, n);
    scanf("%d", &id);
    binarySearch(lib, 0, n - 1, id);

    return 0;
}