// Create a structure called Flight with the following members:
// a. flight_num (int) – representing unique Flight number
// b. departure_city (string) - representing departure city
// c. destination_city (string) - representing destination city
// d. price (float) – representing ticket price
// Write a program in C that
// 1. reads an integer ‘n’ (representing the number of Flights)
// 2. implements a function to read details of ‘n’ Flights from the user (Array of
// Structures).
// 3. read an integer ‘flightNum (representing the flight number, that has to be searched
// in the ‘n’ Flights’ details)
// 4. using the binary search technique, implement a function to perform search
// operation based on ‘flightNum’. If the search is successful, function should
// display the Flight details for that Flight number, otherwise display the message
// “No Flight details found for the given number”.

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
void binarySearch(struct Flight f[], int l, int r, int flightNum)
{
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (flightNum == f[mid].flight_num)
        {
            printf("Flight details found for given number\n");
            printf("Flight Number: %d\n", f[mid].flight_num);
            printf("Departure City: %s\n", f[mid].departure_city);
            printf("Destination City: %s\n", f[mid].dest_city);
            printf("Ticket Price: %f\n", f[mid].price);
            return;
        }
        if (flightNum > f[mid].flight_num)
            l = mid + 1;

        else
            r = mid - 1;
    }

    printf("No Flight details found for the given number");
}

int main()
{
    struct Flight f[10];
    int n, flightNum;
    scanf("%d", &n);
    read(f, n);
    scanf("%d", &flightNum);
    binarySearch(f, 0, n - 1, flightNum);
    return 0;
}