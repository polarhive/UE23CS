// Create a structure called ‘Flight’ with the following members:
// - flight_number: Represents the flight number.
// - departure_city: Represents the departure city of the flight.
// - destination_city: Represents the destination city of the flight.
// - departure_time: Represents the departure time of the flight.
// - arrival_time: Represents the arrival time of the flight.
// - ticket_price: Represents the price of a ticket for the flight.
// Write a C program that accomplishes the following tasks:
// - Implement a function to read details of a flight from the user.
// - Implement a function to display all the details entered by the user.
// - Implement a function to calculate the total cost based on number of tickets and
// ticket price and print it out.

#include <stdio.h>
#include <stdlib.h> // for atof function
struct Flight
{
    char flight_number[10];
    char departure_city[50];
    char destination_city[50];
    char departure_time[6]; // hh:mm format
    char arrival_time[6];   // hh:mm format
    int ticket_price;
};
void read_flight_details(struct Flight *flight)
{
    scanf("%s", flight->flight_number);
    scanf("%s", flight->departure_city);
    scanf("%s", flight->destination_city);
    scanf("%s", flight->departure_time);
    scanf("%s", flight->arrival_time);
    scanf("%d", &flight->ticket_price);
}

void display_flight_details(struct Flight flight, int num_tickets)
{
    printf("Flight Details:\n");
    printf("Flight Number: %s\n", flight.flight_number);
    printf("Departure City: %s\n", flight.departure_city);
    printf("Destination City: %s\n", flight.destination_city);
    printf("Departure Time: %s\n", flight.departure_time);
    printf("Arrival Time: %s\n", flight.arrival_time);
    printf("Ticket Price: $%d\n", flight.ticket_price);
    printf("Number of Tickets: %d\n", num_tickets);
}
void calculate_total_cost(int ticket_price, int num_tickets)
{
    printf("Total Cost: $%d\n", ticket_price * num_tickets);
}
int main()
{
    struct Flight flight1;
    int num_tickets;
    read_flight_details(&flight1);
    scanf("%d", &num_tickets);
    display_flight_details(flight1, num_tickets);
    calculate_total_cost(flight1.ticket_price, num_tickets);
    return 0;
}