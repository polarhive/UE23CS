// 1) Write a function to check if a given pattern occurs in a string. Length of the pattern is
// less than that of the string. Print the index of the first occurrence of the pattern in the
// string. If the pattern doesn't exist in the string, print -1.
// (Note: You are allowed to use strlen() to find the length of the String, if required).

#include <stdio.h>
#include <string.h>
int find(const char *string, const char *pattern)
{
    int lenString = strlen(string);
    int lenPattern = strlen(pattern);
    if (lenPattern >= lenString)
        return -1;
    int i = 0;
    while (string[i] != '\0')
    {
        int j = 0;
        int match = 1;
        while (pattern[j] != '\0')
        {
            if (string[i + j] != pattern[j])
            {
                match = 0;
                break;
            }
            j++;
        }
        if (match)
            return i;
        i++;
    }
    return -1;
}
int main()
{
    char string[100];
    char pattern[100];
    scanf("%s", string);
    scanf("%s", pattern);
    printf("%d", find(string, pattern));
    return 0;
}