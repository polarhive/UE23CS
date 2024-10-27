// Create a Structure called Book with the following members: ISBN_No,
// Book_name, No_of_pages, publication_year, price and Author as a nested
// structure with its members as Author_name, description (Biographical
// profile about the author), birth_year. Write a program that implements
// 1. A function to read details from the user.
// 2. A Function to display all the details entered by the user.
// 3. A function to calculate the age of the author when publishing the book and
// display the appropriate message.

#include <stdio.h>
struct Book
{
    int ISBN_No;
    char book_name[50];
    int no_of_pages;
    int publication_year;
    float price;
    struct Author
    {
        char author_name[50];
        char description[100];
        int birth_year;
    } a;
};
struct Book read_details(struct Book b1);
void display_details(struct Book b1);
void author_age_at_publication(struct Book b1);
int main()
{
    struct Book b, ret_b;
    ret_b = read_details(b); // can also pass &b and in that case, no return is required
    display_details(ret_b);
    author_age_at_publication(ret_b);
    return 0;
}
struct Book read_details(struct Book b1)
{
    scanf("%d", &b1.ISBN_No);
    scanf(" %[^\n]s", b1.book_name);
    scanf("%d", &b1.no_of_pages);
    scanf("%d", &b1.publication_year);
    scanf("%f", &b1.price);
    scanf(" %[^\n]s", b1.a.author_name);
    scanf(" %[^\n]s", b1.a.description);
    scanf("%d", &b1.a.birth_year);

    return b1;
}
void display_details(struct Book b1)
{
    printf("ISBN No: %d\n", b1.ISBN_No);
    printf("Book Name: %s\n", b1.book_name);
    printf("Num of Pages: %d\n", b1.no_of_pages);
    printf("Year of Publication: %d\n", b1.publication_year);
    printf("Price: %.2f\n", b1.price);
    printf("Author's Name: %s\n", b1.a.author_name);
    printf("Author's Description: %s\n", b1.a.description);
    printf("Author's Birth Year: %d\n", b1.a.birth_year);
}
void author_age_at_publication(struct Book b1)
{
    int age = b1.publication_year - b1.a.birth_year;
    printf("Author's age at the time of Publication is %d", age);
}