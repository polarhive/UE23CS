// Design a structure named “Car” to store the following details:
// 1. Car ID
// 2. Another structure named “Properties” containing the members: Model name,
// Color, Number of Seats
// 3. Rental Rate per Day
// Write a C program with:
// 1. A function to read details of a car from the user.
// 2. A function to calculate the total rental rate of a car given the number of days.
// 3. A function to display the details of the car with the total rental rate of the car.

#include <stdio.h>
struct Car
{
    int carID;
    struct Properties
    {
        char name[50];
        char color[20];
        int no_of_seats;
    } prop;
    float rental_rate;
};

void read_details(struct Car *c)
{
    scanf("%d", &c->carID);
    scanf("%s", c->prop.name);
    scanf("%s", c->prop.color);
    scanf("%d", &c->prop.no_of_seats);
    scanf("%f", &c->rental_rate);
}
float calculate_total_rental_rate(struct Car *c, int days)
{
    return c->rental_rate * days;
}
void display_details(struct Car *c, int days)
{
    printf("Car ID: %d\n", c->carID);
    printf("Model: %s\n", c->prop.name);
    printf("Color: %s\n", c->prop.color);
    printf("Number of Seats: %d\n", c->prop.no_of_seats);
    printf("Total Rental Rate: %.2f\n", calculate_total_rental_rate(c, days));
}
int main()
{
    int days;
    struct Car c;
    read_details(&c);
    scanf("%d", &days);
    display_details(&c, days);
    return 0;
}