// Create a structure called CricketPlayer with the following members:
// a) player_id (int) - representing Player ID
// b) name (string) - representing Player’s Name
// c) no_of_matches (int) - representing number of matches played by
// the Player
// d) runs (int) – representing total runs scored by the Player
// Using the array of Structures, sort the structures in the array based on the data
// member – player _id (Bubble sort Technique)

// Write a program in C that
// 1. reads an integer ‘n’ (representing the number of Players)
// 2. use a function to read details of ‘n’ Players
// 3. use a function to display details of all Players - before sorting
// 4. implement sort operation using a function
// 5. use the function to display details of all Players - after sorting

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
void display(struct CricketPlayer c[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d %s %d %d\n",
               c[i].player_id, c[i].name, c[i].no_of_matches, c[i].runs);
    }
}
void sort(struct CricketPlayer c[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (c[j].player_id > c[j + 1].player_id)
            {

                struct CricketPlayer t;
                t = c[j + 1];
                c[j + 1] = c[j];
                c[j] = t;
            }
        }
    }
}
int main()
{
    struct CricketPlayer c[10];
    int n;
    scanf("%d", &n);
    read(c, n);
    printf("Before Sorting:\n");
    display(c, n);
    sort(c, n);
    printf("After Sorting:\n");
    display(c, n);

    return 0;
}