// Create a structure called Car with the following members:
// a) id (int) - representing Car ID
// b) name (string) - representing Car’s Name
// c) no_of_seats (int) - representing number of seats
// d) rent (float) – representing rental rate per day
// Using the array of Structures, sort the structures in the array based on the data member
// – id (Bubble sort Technique)
// Write a program in C that
// 1. reads an integer ‘n’ (representing the number of Cars)
// 2. use a function to read details of ‘n’ Cars
// 3. use a function to display details of all Cars - before sorting
// 4. implement sort operation using a function
// 5. use the function to display details of all Cars - after sorting

#include <stdio.h>
struct Car
{
    int id;
    char name[50];
    int no_of_seats;
    float rent;
};
void read(struct Car c[], int n)

{
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &c[i].id);
        scanf(" %s", c[i].name);
        scanf(" %d", &c[i].no_of_seats);
        scanf(" %f", &c[i].rent);
    }
}
void display(struct Car c[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d %s %d %.2f\n", c[i].id, c[i].name, c[i].no_of_seats, c[i].rent);
    }
}
void sort(struct Car c[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (c[j].id > c[j + 1].id)
            {
                struct Car t;
                t = c[j + 1];
                c[j + 1] = c[j];
                c[j] = t;
            }
        }
    }
}
int main()
{
    struct Car c[10];
    int n;
    scanf("%d", &n);
    read(c, n);
    printf("Before Sorting:\n");
    display(c, n);
    sort(c, n);
    printf("After Sorting:\n");
    display(c, n);
    return 0;
}