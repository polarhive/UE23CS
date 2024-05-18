// Create a structure called Car with the following members:
// a) id (int) - representing Car ID
// b) name (string) - representing Car’s Name
// c) no_of_seats (int) - representing number of seats
// d) rent (float) – representing rental rate per day
// Write a program in C that
// 1. reads an integer ‘n’ (representing the number of cars)
// 2. implements a function to read details of ‘n’ cars from the user (Array of
// Structures).
// 3. read an integer ‘id’ (representing the car ID, that has to be searched in the ‘n’ cars’
// details)
// 4. using the binary search technique, implement a function to perform search
// operation based on ‘id’. If the search is successful, function should display the Car
// details for that ID, otherwise display the message “No Car details found for the
// given ID”.

#include <stdio.h>
struct Car
{
    int id;
    char name[50];
    int no_of_seats;
    float rent;
};
void read(struct Car c[], int n);
void binarySearch(struct Car c[], int l, int r, int id);
int main()
{
    struct Car c[10];
    int n, id;
    scanf("%d", &n);
    read(c, n);
    scanf("%d", &id);
    binarySearch(c, 0, n - 1, id);
    return 0;
}
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
void binarySearch(struct Car c[], int l, int r, int id)
{
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (id == c[mid].id)
        {
            printf("Car details found for given ID\n");
            printf("ID: %d\n", c[mid].id);
            printf("Name: %s\n", c[mid].name);
            printf("Num of seats: %d\n", c[mid].no_of_seats);
            printf("Rental rate per day: %.2f\n", c[mid].rent);
        }
        return;
        if (id > c[mid].id)
            l = mid + 1;
        else
            r = mid - 1;
    }
    printf("No Car details found for the given ID");
}