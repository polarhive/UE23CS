// Create a structure called YouTubeManagement with the following members:
// a) channel_id (int) - representing Channel ID
// b) channel_name (string) - representing name of the Channel
// c) total_videos (int) - representing total number of videos uploaded by the Channel
// Write a program in C that
// 1. reads an integer ‘n’ (representing the number of Channels)
// 2. implements a function to read details of ‘n’ Channels from the user (Array of
// Structures).
// 3. read an integer ‘id’ (representing the Channel ID, that has to be searched in the ‘n’
// Channels’ details)
// 4. using the binary search technique, implement a function to perform search
// operation based on ‘id’. If the search is successful, function should display the
// Channel details for that ID, otherwise display the message “No Channel details
// found for the given ID”.

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
void binarySearch(struct YouTubeManagement y[], int l, int r, int id)
{

    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (id == y[mid].channel_id)
        {
            printf("Channel details found for given ID\n");
            printf("Channel ID: %d\n", y[mid].channel_id);
            printf("Channel Name: %s\n", y[mid].channel_name);
            printf("Total Videos: %d\n", y[mid].total_videos);
        }
        return;
        if (id > y[mid].channel_id)
            l = mid + 1;
        else
            r = mid - 1;
    }

    printf("No Channel details found for the given ID");
}
int main()
{
    struct YouTubeManagement y[10];
    int n, id;
    scanf("%d", &n);
    read(y, n);
    scanf("%d", &id);
    binarySearch(y, 0, n - 1, id);
    return 0;
}