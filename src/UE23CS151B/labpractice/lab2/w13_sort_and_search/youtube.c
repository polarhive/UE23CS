// Create a structure called YouTubeManagement with the following members:
// a) channel_id (int) - representing Channel ID
// b) channel_name (string) - representing name of the Channel
// c) total_videos (int) - representing total number of videos uploaded by the Channel
// Using the array of Structures, sort the structures in the array based on the data member
// – channel_id (Bubble sort Technique)
// Write a program in C that
// 1. reads an integer ‘n’ (representing the number of Channels)
// 2. use a function to read details of ‘n’ Channels
// 3. use a function to display details of all Channels - before sorting
// 4. implement sort operation using a function
// 5. use the function to display details of all Channels - after sorting

#include <stdio.h>
struct YouTubeManagement
{
    int channel_id;
    char channel_name[50];
    int total_videos;
};
void read(struct YouTubeManagement y[], int n)
{
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &y[i].channel_id);
        scanf(" %s", y[i].channel_name);
        scanf("%d", &y[i].total_videos);
    }
}
void display(struct YouTubeManagement y[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d %s %d\n",
               y[i].channel_id, y[i].channel_name, y[i].total_videos);
    }
}
void sort(struct YouTubeManagement y[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (y[j].channel_id > y[j + 1].channel_id)
            {
                struct YouTubeManagement t;
                t = y[j + 1];
                y[j + 1] = y[j];
                y[j] = t;
            }
        }
    }
}
int main()
{
    struct YouTubeManagement y[10];
    int n;
    scanf("%d", &n);
    read(y, n);
    printf("Before Sorting:\n");
    display(y, n);
    sort(y, n);
    printf("After Sorting:\n");
    display(y, n);
    return 0;
}