// Write a program in C to read a sentence and print the repeated characters in the given
// sentence

#include <stdio.h>
int main()
{
    char str[100];
    int count[256] = {0};
    int repeat_flag = 0;
    scanf("%[^\n]s", str);
    for (int i = 0; str[i] != '\0'; i++)
        count[(unsigned char)str[i]]++;
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (count[(unsigned char)str[i]] > 1)
        {
            printf("%c ", str[i]);
            count[(unsigned char)str[i]] = 0;
            repeat_flag = 1;
        }
    }
    if (!repeat_flag)
        printf("No repeated characters found");
    return 0;
}