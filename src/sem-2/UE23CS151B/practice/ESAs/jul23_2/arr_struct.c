#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Book
{
    char title[50];
    char author[50];
    int year;
};
int main()
{
    struct Book *books[3]; // alloc mem
    books[0] = malloc(sizeof(struct Book));
    books[1] = malloc(sizeof(struct Book));
    books[2] = malloc(sizeof(struct Book));

    strcpy(books[0]->title, "Moby Dick");
    strcpy(books[0]->author, "Herman Melville");
    books[0]->year = 1851;
    strcpy(books[1]->title, "1984");
    strcpy(books[1]->author, "George Orwell");
    books[1]->year = 1949;
    strcpy(books[2]->title, "To Kill a Mockingbird");
    strcpy(books[2]->author, "Harper Lee");
    books[2]->year = 1960;

    for (int i = 0; i < 3; i++)
    {
        printf("Title: %s\nAuthor: %s\nYear: %d\n", books[i]->title, books[i]->author, books[i]->year);
    }

    // dont forget to free
    for (int i = 0; i < 3; i++)
    {
        free(books[i]);
    }
}
