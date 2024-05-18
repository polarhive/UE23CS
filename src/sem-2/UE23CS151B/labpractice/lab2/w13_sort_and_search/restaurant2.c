// Create a structure called Restaurant with the following members:
// a) food_id (int) - representing Food ID
// b) food_name (string) - representing name of the food
// c) customer_name (string) - representing name of the customer ordering the food
// d) cost (float) – representing cost of the food
// Write a program in C that
// 1. reads an integer ‘n’ (representing the number of food items)
// 2. implements a function to read details of ‘n’ food items from the user (Array of
// Structures).
// 3. read an integer ‘id’ (representing the food ID, that has to be searched in the ‘n’
// food items’ details)
// 4. using the binary search technique, implement a function to perform search
// operation based on ‘id’. If the search is successful, function should display the
// food item details for that food ID, otherwise display the message “No Food
// items found for the given ID”.use the function to display details of all food items
// - after sorting

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
void binarySearch(struct Restaurant r[], int left, int right, int id)
{
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (id == r[mid].food_id)
        {
            printf("Food item details found for given ID\n");
            printf("ID: %d\n", r[mid].food_id);
            printf("Food Name: %s\n", r[mid].food_name);

            printf("Customer's Name: %s\n", r[mid].customer_name);
            printf("Cost: %.2f\n", r[mid].cost);
        }
        return;
        if (id > r[mid].food_id)
            left = mid + 1;
        else
            right = mid - 1;
    }

    printf("No Food items found for the given ID");
}

int main()
{
    struct Restaurant r[10];
    int n, id;
    scanf("%d", &n);
    read(r, n);
    scanf("%d", &id);
    binarySearch(r, 0, n - 1, id);
    return 0;
}