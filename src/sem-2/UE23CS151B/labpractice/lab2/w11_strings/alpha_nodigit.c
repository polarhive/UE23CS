// Write a program in C that reads a string contains alphabets, digits and special symbols.
// Print the string with only alphabets without digits and special symbols. (NOTE: Don’t
// use any String built-in functions).

#include <stdio.h>
int main()
{
    char str[150];
    int i, j;
    scanf("%[^\n]s", str);
    for (i = 0; str[i] != '\0'; i++)
    {
        while (!((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z') || str[i] == '\0'))
        {
            for (j = i; str[j] != '\0'; j++)
            {
                str[j] = str[j + 1];
            }
            str[j] = '\0';
        }
    }
    printf("%s", str);
    return 0;
}