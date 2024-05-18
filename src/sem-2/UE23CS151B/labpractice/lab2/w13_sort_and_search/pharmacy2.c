// Create a structure called Pharmacy with the following members:
// a) med_code (int) – Unique code for medicine
// b) med_name (string) - representing name of the medicine
// c) qty (int) - representing quantity of the medicine purchased
// d) price (float) – representing price of the medicine
// Write a program in C that
// 1. reads an integer ‘n’ (representing the number of medicines)
// 2. implements a function to read details of ‘n’ number of medicines from the user
// (Array of Structures).
// 3. read an integer ‘medCode’ (representing the medicine code, that has to be
// searched in the ‘n’ medicines’ details)
// 4. using the binary search technique, implement a function to perform search
// operation based on ‘medCode’. If the search is successful, function should display
// the Medicine details for that med code, otherwise display the message “No
// Medicine details found for the given code”.

#include <stdio.h>
struct Pharmacy
{
    int med_code;
    char med_name[50];
    int qty;
    float price;
};
void read(struct Pharmacy p[], int n)
{
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &p[i].med_code);
        scanf("%s", p[i].med_name);
        scanf("%d", &p[i].qty);
        scanf("%f", &p[i].price);
    }
}
void display(struct Pharmacy p[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d %s %d %f\n",
               p[i].med_code, p[i].med_name, p[i].qty, p[i].price);
    }
}
void binarySearch(struct Pharmacy p[], int l, int r, int medCode)
{
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (medCode == p[mid].med_code)

        {
            printf("Medicine details found for given code\n");
            printf("Med Code: %d\n", p[mid].med_code);
            printf("Med Name: %s\n", p[mid].med_name);
            printf("Quantity: %d\n", p[mid].qty);
            printf("Price: %f\n", p[mid].price);
            return;
        }
        if (medCode > p[mid].med_code)
            l = mid + 1;
        else
            r = mid - 1;
    }
    printf("No Medicine details found for the given code");
}
int main()
{
    struct Pharmacy p[10];
    int n, medCode;
    scanf("%d", &n);
    read(p, n);
    scanf("%d", &medCode);
    binarySearch(p, 0, n - 1, medCode);
    return 0;
}