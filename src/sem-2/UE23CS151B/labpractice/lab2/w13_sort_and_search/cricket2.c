// Create a structure called CricketPlayer with the following members:
// e. player_id (int) - representing Player ID
// f. name (string) - representing Player’s Name
// g. no_of_matches (int) - representing number of matches played by the
// Player
// h. runs (int) – representing total runs scored by the Player
// Write a program in C that
// 1. reads an integer ‘n’ (representing the number of Players)
// 2. implements a function to read details of ‘n’ Players from the user (Array
// of Structures).
// 3. read an integer ‘id’ (representing the Player ID, that has to be searched
// in the ‘n’ Players’ details)
// 4. using the binary search technique, implement a function to perform
// search operation based on ‘id’. If the search is successful, function
// should display the Player details for that ID, otherwise display the
// message “No Player details found for the given ID”.

#include <stdio.h>
struct CricketPlayer
{
    int player_id;
    char name[50];
    int no_of_matches;
    int runs;
};
void read(struct CricketPlayer c[], int n)
{
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &c[i].player_id);
        scanf(" %s", c[i].name);
        scanf("%d", &c[i].no_of_matches);
        scanf("%d", &c[i].runs);
    }
}
void binarySearch(struct CricketPlayer c[], int l, int r, int id)
{
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (id == c[mid].player_id)
        {
            printf("Player details found for given ID\n");
            printf("ID: %d\n", c[mid].player_id);
            printf("Player name: %s\n", c[mid].name);
            printf("Num of matches: %d\n", c[mid].no_of_matches);
            printf("Total runs: %d\n", c[mid].runs);
            return;
        }
        if (id > c[mid].player_id)
            l = mid + 1;
        else
            r = mid - 1;
    }
    printf("No Player details found for the given ID");
}
int main()
{
    struct CricketPlayer c[10];
    int n, id;
    scanf("%d", &n);
    read(c, n);
    scanf("%d", &id);
    binarySearch(c, 0, n - 1, id);
    return 0;
}