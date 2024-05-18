// Create a structure named Patient with the following members:
// 1. patient_id : Representing the patient's ID (an integer value).
// 2. name: Representing the patient's name.
// 3. age: Representing the patient's age.
// Using the array of Structures, sort the structures in the array based on the data member
// – patient_id (Bubble sort Technique)
// Write a program in C that
// 1. reads an integer ‘n’ (representing the number of patients)
// 2. use a function to read details of ‘n’ patients
// 3. use a function to display details of all patients - before sorting
// 4. implement sort operation using a function
// 5. use the function to display details of all patients - after sorting

#include <stdio.h>

struct Patient
{
    int patient_id;
    char name[50];
    int age;
};
void read(struct Patient p[], int n)
{
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &p[i].patient_id);
        scanf("%s", p[i].name);
        scanf("%d", &p[i].age);
    }
}
void display(struct Patient p[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d %s %d\n", p[i].patient_id, p[i].name, p[i].age);
    }
}
void sort(struct Patient p[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (p[j].patient_id > p[j + 1].patient_id)
            {
                struct Patient t;
                t = p[j + 1];
                p[j + 1] = p[j];
                p[j] = t;
            }
        }
    }
}

int main()
{
    struct Patient p[10];
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