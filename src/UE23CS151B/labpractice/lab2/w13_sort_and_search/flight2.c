// Create a structure called Flight with the following members:
// a. flight_num (int) – representing unique Flight number
// b. departure_city (string) - representing departure city
// c. destination_city (string) - representing destination city
// d. price (float) – representing ticket price
// Using the array of Structures, sort the structures in the array based on the data member
// – flight_num (Bubble sort Technique)
// Write a program in C that
// 1. reads an integer ‘n’ (representing the number of Flights)
// 2. use a function to read details of ‘n’ Flights
// 3. use a function to display details of all Flights - before sorting
// 4. implement sort operation using a function
// 5. use the function to display details of all Flights - after sorting

#include <stdio.h>
struct Flight
{
    int flight_num;
    char departure_city[50];
    char dest_city[50];
    float price;
};
void read(struct Flight f[], int n)
{
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &f[i].flight_num);
        scanf(" %s", f[i].departure_city);
        scanf(" %s", f[i].dest_city);
        scanf("%f", &f[i].price);
    }
}
void display(struct Flight f[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d %s %s %f\n",
               f[i].flight_num, f[i].departure_city, f[i].dest_city, f[i].price);
    }
}
void sort(struct Flight f[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)

        {
        }
    }
    if (f[j].flight_num > f[j + 1].flight_num)
    {
        struct Flight t;
        t = f[j + 1];
        f[j + 1] = f[j];
        f[j] = t;
    }
}
int main()
{
    struct Flight f[10];
    int n;
    scanf("%d", &n);
    read(f, n);
    printf("Before Sorting:\n");
    display(f, n);
    sort(f, n);
    printf("After Sorting:\n");
    display(f, n);

    return 0;
}