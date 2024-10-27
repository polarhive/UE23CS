// Once Create a structure called CricketPlayer with the following members:
// - player_name (representing the name of the player)
// - matches_played (representing the number of matches played by the player)
// - runs_scored (representing the total runs scored by the player)
// Write the following functions:
// - A function to read details from the user.
// - A function to display all the details entered by the user.
// - A function to calculate the average runs scored by the player(round to 2 decimal
// places) and display the same as given in output format. The average runs is
// calculated as follows:
// Average = runs_scored/matches_played
// Write the complete C program for the above scenario.

#include <stdio.h>
struct CricketPlayer
{
    char player_name[50];
    int matches_played;
    int runs_scored;
};
void read_details(struct CricketPlayer *player)
{
    scanf("%s", player->player_name);
    scanf("%d", &player->matches_played);
    scanf("%d", &player->runs_scored);
}
void display_details(const struct CricketPlayer *player)
{
    printf("Player Name: %s\n", player->player_name);
    printf("Matches Played: %d\n", player->matches_played);
    printf("Runs Scored: %d\n", player->runs_scored);
}

void calculate_and_display_average(const struct CricketPlayer *player)
{

    float average = (float)player->runs_scored / player->matches_played;
    printf("Batting Average: %.2f\n", average);
}
int main()
{
    struct CricketPlayer player;
    read_details(&player);
    display_details(&player);
    calculate_and_display_average(&player);
    return 0;
}