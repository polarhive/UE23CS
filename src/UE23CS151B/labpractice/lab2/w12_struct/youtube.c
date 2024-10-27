// Create a Structure named “YouTubeManagement” with following members -
// • channel_name: A character array to store the name of the channel
// (whitespaces allowed).
// • total_videos: An integer to store the total number of videos uploaded by
// the channel.
// • subscriber_count: A long long integer to store the number of subscribers
// of the channel.
// • earnings: A double variable to store the earnings of the channel.
// • contact_info: An instance of the “ContactInfo” structure.
// “ContactInfo” structure members -
// • email: A character array to store the email address of the channel.
// • phone: A long long int variable to store the phone number of the channel.

// Create the below functions and execute in given order -
// 1. Function “readDetails” to read all the members of the structure except
// “earnings”.
// 2. Function “calculateEarnings” to calculate the earnings of the channel
// based on the assumption that all subscribers view every video uploaded
// by the channel and the earnings is calculated at Rs. 0.45 per view. Insert
// the calculated value in the “earnings” variable of the structure.
// 3. Function “displayDetails” to display all the fields of the structure in
// proper format.

#include <stdio.h>
struct ContactInfo
{
    char email[50];
    long long int phone;
};
struct YouTubeManagement
{
    char channel_name[50];
    int total_videos;
    long long int subscriber_count;
    double earnings;
    struct ContactInfo contact_info;
};
void readDetails(struct YouTubeManagement *channel)
{

    scanf("%[^\n]s", channel->channel_name);
    scanf("%d", &channel->total_videos);
    scanf("%lld", &channel->subscriber_count);
    scanf("%s", channel->contact_info.email);
    scanf("%lld", &channel->contact_info.phone);
}
void displayDetails(struct YouTubeManagement channel)
{
    printf("Channel Name: %s\n", channel.channel_name);
    printf("Total Videos: %d\n", channel.total_videos);
    printf("Subscriber Count: %lld\n", channel.subscriber_count);
    printf("Contact Email: %s\n", channel.contact_info.email);
    printf("Contact Phone: %lld\n", channel.contact_info.phone);
    printf("Total Earnings of the Channel: Rs. %.2f\n", channel.earnings);
}

void calculateEarnings(struct YouTubeManagement *channel)
{
    long long int total_views = channel->subscriber_count * channel->total_videos;
    channel->earnings = total_views * 0.45;
}
int main()
{

    struct YouTubeManagement channel;
    readDetails(&channel);
    calculateEarnings(&channel);
    displayDetails(channel);
    return 0;
}