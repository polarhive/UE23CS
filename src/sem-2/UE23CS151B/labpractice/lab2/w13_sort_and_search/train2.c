// Create a structure called Train with the following members:
// a) train_num (int) - representing Train Number
// b) train_name (string) - representing name of Train
// c) src (string) - representing Source City
// d) dest (string) – representing Destination City
// Using the array of Structures, sort the structures in the array based on the data member
// – train_num (Bubble sort Technique)
// Write a program in C that
// 1. reads an integer ‘n’ (representing the number of Trains)
// 2. use a function to read details of ‘n’ Trains
// 3. use a function to display details of all Trains - before sorting
// 4. implement sort operation using a function
// 5. use the function to display details of all Trains - after sorting

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
void display(struct Train t[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d %s %s %s\n",
               t[i].train_num, t[i].train_name, t[i].src, t[i].dest);
    }
}
void sort(struct Train t[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (t[j].train_num > t[j + 1].train_num)
            {
                struct Train temp;
                temp = t[j + 1];
                t[j + 1] = t[j];
                t[j] = temp;
            }
        }
    }
}
int main()
{
    struct Train t[10];
    int n;
    scanf("%d", &n);
    read(t, n);
    printf("Before Sorting:\n");
    display(t, n);
    sort(t, n);
    printf("After Sorting:\n");
    display(t, n);
    return 0;
}