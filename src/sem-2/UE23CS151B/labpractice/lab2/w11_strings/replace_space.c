// Write a C Program to replace space in a sentence by a specific character. (NOTE: Don’t use
// any String built-in functions)

#include <stdio.h>
int main()
{
    char str[100];
    char c;
    // Reading a sentence
    scanf("%[^\n]s", str);
    // Reading a character
    scanf(" %c", &c);
    // Replace space by specific character
    int i = 0;
    while (str[i] != '\0')
    {
        if (str[i] == ' ')
            str[i] = c;

        i++;
    }
    printf("%s", str);
    return 0;
}