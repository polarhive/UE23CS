// Write a C program to eliminate/remove the first character of each word from a string.
// (NOTE: Don't use any String Built-in functions)

#include <stdio.h>
int main()
{
    char text[10000] = {0};
    int loop, j;
    scanf("%[^\n]s", text);
    for (loop = 0; text[loop] != '\0'; loop++)
    {
        if (loop == 0 || (text[loop] == ' ' && text[loop + 1] != ' '))
        {
            for (j = ((loop == 0) ? loop : loop + 1); text[j] != '\0'; j++)
                text[j] = text[j + 1];
        }
    }
    printf("%s\n", text);
    return 0;
}