// A new taxonomy has been created, where the species is a part of a family/genus if it can
// be formed by deleting 1 or more characters from the genus string (Characters cannot be
// rearranged).
// Eg:
// Species - abc
// Genus - avbdc
// Write a C program that reads two strings genus and species. Program should display 1 if
// the species belongs to the genus; otherwise display 0.
// (Note: You are allowed to use strlen() to find the length of the String, if required)

#include <stdio.h>
#include <string.h>
int main()
{
    char species[100];
    char genus[100];
    scanf("%s", species);

    scanf("%s", genus);
    int i = 0;
    int j = 0;
    while (genus[i] != '\0')
    {
        if (genus[i] == species[j])
        {
            j++;
        }
        i++;
    }
    if (j == strlen(species))
        printf("%d", 1);
    else
        printf("%d", 0);
}