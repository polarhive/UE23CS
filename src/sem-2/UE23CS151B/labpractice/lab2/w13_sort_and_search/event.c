// Create a structure called event containing the following members:
// - event_id : representing the event ID (an integer value).
// - name: Representing the event name
// - venue: Representing the venue of the event.
// - no_of_passes: Number of passes.
// Using the array of Structures, sort the structures in the array based on the data member
// – event_id (Bubble sort Technique)
// Write a program in C that
// 1. reads an integer ‘n’ (representing the number of events)
// 2. use a function to read details of ‘n’ events
// 3. use a function to display details of all events - before sorting
// 4. implement sort operation using a function
// 5. use the function to display details of all events - after sorting

#include <stdio.h>
struct event
{
    int event_id;
    char name[50];
    char venue[50];
    int no_of_passes;
};
void read(struct event e[], int n);
void display(struct event e[], int n);
void sort(struct event e[], int n);
int main()
{
    struct event e[10];
    int n;
    scanf("%d", &n);
    read(e, n);
    printf("Before Sorting:\n");
    display(e, n);
    sort(e, n);
    printf("After Sorting:\n");
    display(e, n);

    return 0;
}
void read(struct event e[], int n)
{
    for (int i = 0; i < n; i++)
    {
        scanf(" %d", &e[i].event_id);
        scanf(" %[^\n]s", e[i].name);
        scanf(" %[^\n]s", e[i].venue);
        scanf(" %d", &e[i].no_of_passes);
    }
}
void display(struct event e[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf(" %d %s %s %d\n", e[i].event_id, e[i].name, e[i].venue, e[i].no_of_passes);
    }
}
void sort(struct event e[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (e[j].event_id > e[j + 1].event_id)
            {
                struct event t;
                t = e[j + 1];
                e[j + 1] = e[j];
                e[j] = t;
            }
        }
    }
}