// Create a structure called HockeyPlayer with the following members:
// a) player_id (int) - representing Player ID
// b) name (string) - representing Player’s Name
// c) no_of_matches (int) - representing number of matches played by the Player
// d) goals (int) – representing total number of goals scored by the Player
// Using the array of Structures, sort the structures in the array based on the data member
// – player _id (Bubble sort Technique)
// Write a program in C that
// 1. reads an integer ‘n’ (representing the number of Players)
// 2. use a function to read details of ‘n’ Players
// 3. use a function to display details of all Players - before sorting
// 4. implement sort operation using a function
// 5. use the function to display details of all Players - after sorting

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
void display(struct HockeyPlayer h[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d %s %d %d\n",
               h[i].player_id, h[i].name, h[i].no_of_matches, h[i].goals);
    }
}
void sort(struct HockeyPlayer h[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (h[j].player_id > h[j + 1].player_id)
            {
                struct HockeyPlayer t;
                t = h[j + 1];
                h[j + 1] = h[j];
                h[j] = t;
            }
        }
    }
}

int main()
{
    struct HockeyPlayer h[10];
    int n;
    scanf("%d", &n);
    read(h, n);
    printf("Before Sorting:\n");
    display(h, n);
    sort(h, n);
    printf("After Sorting:\n");
    display(h, n);
    return 0;
}