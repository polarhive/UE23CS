// Create a structure called Train with the following members:
// a) train_num (int) - representing Train Number
// b) train_name (string) - representing name of Train
// c) src (string) - representing Source City
// d) dest (string) – representing Destination City
// Write a program in C that
// 1. reads an integer ‘n’ (representing the number of Trains)
// 2. implements a function to read details of ‘n’ Trains from the user (Array of
// Structures).
// 3. read an integer ‘trainNum’ (representing the train number, that has to be searched
// in the ‘n’ Trains’ details)
// 4. using the binary search technique, implement a function to perform search
// operation based on ‘trainNum’. If the search is successful, function should display
// the Train details for that train number, otherwise display the message “No Train
// details found for the given number”.

#include <stdio.h>
struct Train
{
    int train_num;
    char train_name[50];
    char src[50];
    char dest[50];
};
void read(struct Train t[], int n)
{
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &t[i].train_num);
        scanf(" %s", t[i].train_name);
        scanf(" %s", t[i].src);
        scanf(" %s", t[i].dest);
    }
}
void binarySearch(struct Train t[], int l, int r, int trainNum)

{
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (trainNum == t[mid].train_num)
        {
            printf("Train details found for given number\n");
            printf("Train Number: %d\n", t[mid].train_num);
            printf("Train Name: %s\n", t[mid].train_name);
            printf("Source: %s\n", t[mid].src);
            printf("Destination: %s\n", t[mid].dest);
        }
        return;
        if (trainNum > t[mid].train_num)
            l = mid + 1;
        else
            r = mid - 1;
    }
    printf("No Train details found for the given number");
}
int main()
{
    struct Train t[10];
    int n, trainNum;
    scanf("%d", &n);
    read(t, n);
    scanf("%d", &trainNum);
    binarySearch(t, 0, n - 1, trainNum);
    return 0;
}