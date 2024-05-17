// Write a program in C that takes two string arguments and find the Cartesian product of
// passed strings.
// Input: str1: abc str2: ab and Output: aa, ab, ba, bb, ca, cb
// (NOTE: Don’t use any String built-in functions)

#include <stdio.h>

int main()
{
    char str1[100], str2[100];
    int i, j;
    scanf("%s", str1);
    scanf("%s", str2);
    i = 0;
    while (str1[i] != '\0')
    {
        j = 0;
        while (str2[j] != '\0')
        {
            printf("%c%c\n", str1[i], str2[j]);
            j++;
        }
        i++;
    }
    return 0;
}
