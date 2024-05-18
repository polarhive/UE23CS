// Create a structure named Patient with the following members:
// 1. patient_id : Representing the patient's ID (an integer value).
// 2. name: Representing the patient's name.
// 3. age: Representing the patient's age.
// Write a program in C that
// 1. reads an integer ‘n’ (representing the number of patients)
// 2. implements a function to read details of ‘n’ patients from the user (Array of
// Structures).
// 3. read an integer ‘id’ (representing the Patient ID, that has to be searched in the ‘n’
// patients’ details)
// 4. using the binary search technique, implement a function to perform search
// operation based on ‘id’. If the search is successful, function should display the
// patient details for that ID, otherwise display the message “No Patient details
// found for the given ID”.

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
void binarySearch(struct Patient p[], int l, int r, int id)
{
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (id == p[mid].patient_id)
        {
            printf("Patient details found for given ID\n");
            printf("ID: %d\n", p[mid].patient_id);
            printf("Name: %s\n", p[mid].name);
            printf("Age: %d\n", p[mid].age);
        }
        return;
        if (id > p[mid].patient_id)
            l = mid + 1;
        else
            r = mid - 1;
    }
    printf("No Patient details found for the given ID");
}
int main()
{
    struct Patient p[10];
    int n, id;
    scanf("%d", &n);
    read(p, n);
    scanf("%d", &id);
    binarySearch(p, 0, n - 1, id);
    return 0;
}