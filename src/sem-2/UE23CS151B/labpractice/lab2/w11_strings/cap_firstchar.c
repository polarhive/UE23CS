// Write a C Program to capitalize first character of each word in a sentence. (NOTE: Don’t
// use any built-in function).

#include <stdio.h>
int main()
{
    char str[100];
    int i;
    scanf("%[^\n]s", str);
    if (str[0] >= 'a' && str[0] <= 'z')
        str[0] = str[0] - 32;
    {
        for (i = 1; str[i] != '\0'; i++)
        {
            if (str[i] == ' ')
                i++;
            if (str[i] >= 'a' && str[i] <= 'z')
            {
                str[i] = str[i] - 32;
                continue;
            }
        }
    }
    printf("%s", str);
    return 0;
}