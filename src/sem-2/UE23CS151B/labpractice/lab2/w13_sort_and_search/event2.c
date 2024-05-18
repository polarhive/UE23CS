// Create a structure called event containing the following members:
// - event_id : representing the event ID (an integer value).
// - name: Representing the event name
// - venue: Representing the venue of the event.
// - no_of_passes: Number of passes.

// Write a program in C that
// 1. reads an integer ‘n’ (representing the number of events)
// 2. implements a function to read details of ‘n’ events from the user (Array of
// Structures).
// 3. read an integer ‘eventID’ (representing the event ID, that has to be searched in the
// ‘n’ events details)
// 4. using the binary search technique, implement a function to perform search
// operation based on ‘eventID’. If the search is successful, function should display
// the event details for that eventID, otherwise display the message “No event details
// found for the given event ID”.

#include <stdio.h>
struct event
{
    int event_id;
    char name[50];
    char venue[50];
    int no_of_passes;
};
void read(struct event e[], int n);
void binarySearch(struct event *e, int l, int r, int eventID);
int main()
{
    struct event e[10];
    int n, eventID;
    scanf("%d", &n);
    read(e, n);
    scanf("%d", &eventID); // eventID to be searched
    binarySearch(e, 0, n - 1, eventID);

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
void binarySearch(struct event *e, int l, int r, int eventID)
{
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (eventID == e[mid].event_id)
        {
            printf("Event details found for given event ID\n");
            printf("Event ID: %d\n", e[mid].event_id);
            printf("Event Name: %s\n", e[mid].name);
            printf("Venue: %s\n", e[mid].venue);
            printf("Num of Passes: %d\n", e[mid].no_of_passes);
        }
        return;
        if (eventID > e[mid].event_id)
            l = mid + 1;
        else
            r = mid - 1;
    }
    printf("No Event details found for the given event ID");
}