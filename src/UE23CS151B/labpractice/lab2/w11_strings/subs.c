// Write a C program to find and print all occurrences of the substring within the string,
// the program will print all the starting indices where the substring is found in the given
// string.

#include <stdio.h>
#include <string.h>
void findSubstring(char *string, char *substring)
{
    int len1 = strlen(string);
    int len2 = strlen(substring);
    int found = 0;
    for (int i = 0; i <= len1 - len2; i++)
    {
        int j;
        for (j = 0; j < len2; j++)
        {
            if (string[i + j] != substring[j])
                break;
        }
        if (j == len2)
        {
            printf("Substring found at index %d\n", i);
            found = 1;
        }
    }
    if (!found)
    {
        printf("Substring not found.\n");
    }
}
int main()
{
    char string[100], substring[100];
    scanf(" %[^\n]s", string);    // Read the string with spaces
    scanf(" %[^\n]s", substring); // Read the substring with spaces
    findSubstring(string, substring);
    return 0;
}