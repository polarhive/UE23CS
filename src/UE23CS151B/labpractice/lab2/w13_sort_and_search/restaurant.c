// 1) Create a structure called Restaurant with the following members:
// a. food_id (int) - representing Food ID
// b. food_name (string) - representing name of the food
// c. customer_name (string) - representing name of the customer ordering
// the food
// d. cost (float) – representing cost of the food
// Using the array of Structures, sort the structures in the array based on the data member
// – food _id (Bubble sort Technique)
// Write a program in C that
// 1. reads an integer ‘n’ (representing the number of food items)
// 2. use a function to read details of ‘n’ number of food items
// 3. use a function to display details of all food items - before sorting
// 4. implement sort operation using a function
// 5. use the function to display details of all food items - after sorting

#include <stdio.h>
struct Restaurant
{
    int food_id;
    char food_name[50];
    char customer_name[50];
    float cost;
};
void read(struct Restaurant r[], int n)
{
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &r[i].food_id);
        scanf(" %[^\n]s", r[i].food_name);
        scanf(" %[^\n]s", r[i].customer_name);
        scanf("%f", &r[i].cost);
    }
}

void display(struct Restaurant r[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d %s %s %.2f\n",
               r[i].food_id, r[i].food_name, r[i].customer_name, r[i].cost);
    }
}
void sort(struct Restaurant r[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (r[j].food_id > r[j + 1].food_id)
            {
                struct Restaurant t;
                t = r[j + 1];
                r[j + 1] = r[j];
                r[j] = t;
            }
        }
    }
}
int main()
{
    struct Restaurant r[10];
    int n;
    scanf("%d", &n);
    read(r, n);
    printf("Before Sorting:\n");
    display(r, n);
    sort(r, n);
    printf("After Sorting:\n");
    display(r, n);
    return 0;
}