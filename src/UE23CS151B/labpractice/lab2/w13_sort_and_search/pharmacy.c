// Create a structure called Pharmacy with the following members:
// a) med_code (int) – Unique code for medicine
// b) med_name (string) - representing name of the medicine
// c) qty (int) - representing quantity of the medicine purchased
// d) price (float) – representing price of the medicine
// Using the array of Structures, sort the structures in the array based on the data member
// – med_code (Bubble sort Technique)
// Write a program in C that
// 1. reads an integer ‘n’ (representing the number of medicines)
// 2. use a function to read details of ‘n’ number of medicines
// 3. use a function to display details of all medicines - before sorting
// 4. implement sort operation using a function
// 5. use the function to display details of all medicines - after sorting

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
void sort(struct Pharmacy p[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (p[j].med_code > p[j + 1].med_code)
            {
                struct Pharmacy t;
                t = p[j + 1];
                p[j + 1] = p[j];
                p[j] = t;
            }
        }
    }
}
int main()
{
    struct Pharmacy p[10];
    int n;
    scanf("%d", &n);
    read(p, n);
    printf("Before Sorting:\n");
    display(p, n);
    sort(p, n);
    printf("After Sorting:\n");
    display(p, n);
    return 0;
}