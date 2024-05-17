// Create a structure called event containing the following members:
// - name: Representing the event name
// - host: Representing the hostname of event
// - date: A nested structure representing the date of the event contains day, month,
// year.
// - venue: Representing the venue of the event.
// - no_of_pass: Number of passes.
// - rate: Cost of each pass.
// - budget: The estimated total expenditure of the event.
// Write
// i. A function read_event() to read the details from the user and store it in a structure
// variable.
// ii.A function display_event() to display all details of the event as shown in sample output.
// iii.A function calc_profit_loss() to take reference to the event and calculate the Profit or Loss
// earned by conducting the event. Profit or Loss is calculated by using the formula
// (no_of_pass*rate)-budget
// Print the message “No profit/Loss” if there is no profit or loss.

#include <stdio.h>
#include <stdlib.h>
struct event
{
    char name[20], host[20], venue[20];
    struct date
    {
        int day, month, year;
    } d;
    int no_of_pass, rate, budget;
};
void read_event(struct event *ev);
void display_event(struct event *ev);
void calc_profit_loss(struct event *ev);
int main()
{
    struct event e;
    read_event(&e);
    display_event(&e);

    calc_profit_loss(&e);
    return 0;
}
void read_event(struct event *ev)
{
    scanf("%[^\n]s", ev->name);
    scanf(" %[^\n]s", ev->host);
    scanf(" %d-%d-%d", &ev->d.day, &ev->d.month, &ev->d.year);
    scanf(" %[^\n]s", ev->venue);
    scanf("%d", &ev->no_of_pass);
    scanf("%d", &ev->rate);
    scanf("%d", &ev->budget);
}
void display_event(struct event *ev)
{
    printf("Event name: %s\n", ev->name);
    printf("Event host: %s\n", ev->host);
    printf("Event date: %02d-%02d-%04d\n", ev->d.day, ev->d.month,
           ev->d.year);
    printf("Event venue: %s\n", ev->venue);
    printf("Number of passes: %d\n", ev->no_of_pass);
    printf("Rate of each pass: %d\n", ev->rate);
    printf("Event budget: %d\n", ev->budget);
}
void calc_profit_loss(struct event *ev)
{
    int profit = (ev->rate) * (ev->no_of_pass) - (ev->budget);
    if (profit == 0)
        printf("No Profit/Loss");
    else if (profit > 0)
        printf("Profit = %d", profit);
    else
        printf("Loss = %d", abs(profit));
}