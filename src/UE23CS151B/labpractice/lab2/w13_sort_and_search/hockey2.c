// Create a structure called HockeyPlayer with the following members:
// a. player_id (int) - representing Player ID
// b. name (string) - representing Player’s Name
// c. no_of_matches (int) - representing number of matches played by the
// Player
// d. goals (int) – representing total number of goals scored by the Player
// Write a program in C that
// 1. reads an integer ‘n’ (representing the number of Players)
// 2. implements a function to read details of ‘n’ Players from the user (Array of
// Structures).
// 3. read an integer ‘id’ (representing the Player ID, that has to be searched in the ‘n’
// Players’ details)
// 4. using the binary search technique, implement a function to perform search
// operation based on ‘id’. If the search is successful, function should display the
// Player details for that ID, otherwise display the message “No Player details found
// for the given ID”.

#include <stdio.h>
struct HockeyPlayer
{
    int player_id;
    char name[50];
    int no_of_matches;
    int goals;
};
void read(struct HockeyPlayer h[], int n)
{
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &h[i].player_id);
        scanf(" %s", h[i].name);
        scanf("%d", &h[i].no_of_matches);
        scanf("%d", &h[i].goals);
    }
}
void binarySearch(struct HockeyPlayer h[], int l, int r, int id)
{
    while (l <= r)

    {
        int mid = (l + r) / 2;
        if (id == h[mid].player_id)
        {
            printf("Player details found for given ID\n");
            printf("ID: %d\n", h[mid].player_id);
            printf("Player name: %s\n", h[mid].name);
            printf("Num of matches: %d\n", h[mid].no_of_matches);
            printf("Total goals: %d\n", h[mid].goals);
        }
        return;
        if (id > h[mid].player_id)
            l = mid + 1;
        else
            r = mid - 1;
    }
    printf("No Player details found for the given ID");
}
int main()
{
    struct HockeyPlayer h[10];
    int n, id;
    scanf("%d", &n);
    read(h, n);
    scanf("%d", &id);
    binarySearch(h, 0, n - 1, id);

    return 0;
}