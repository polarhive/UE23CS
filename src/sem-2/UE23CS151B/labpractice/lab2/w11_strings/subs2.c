// Write a program in C that determines the total occurrences of a substring in a sentence.
// (Note: You are allowed to use strlen() to find the length of substring and sentence, if
// required).

#include <stdio.h>
#include <string.h>
int main()
{
    char str[1000], substr[100];
    int len1, len2;
    int i, j, count = 0;
    scanf("%[^\n]s", str);
    scanf("%s", substr);
    len1 = strlen(str);
    len2 = strlen(substr);

    for (i = 0; i <= len1 - len2; i++)
    {
        for (j = 0; j < len2; j++)
        {
            if (str[i + j] != substr[j])
                break;
        }
        if (j == len2)
            count++;
    }
    printf("Count = %d", count);
    return 0;
}