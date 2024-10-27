// Bob is very upset that many people on the internet mix uppercase and lowercase letters
// in one word. That's why he decided to invent an extension for his favourite browser that
// would change every word so that it either only consisted of lowercase letters or, vice
// versa, only of uppercase ones.
// The conversion method is as follows:
// a) If the word contains maximum number of uppercase letters, all the letters in the
// word should be converted to uppercase.
// b) If the word contains maximum number of lowercase letters, all the letters in the
// word should be converted to lowercase.
// c) If a word contains an equal number of uppercase and lowercase letters, all the
// letters in the word should be converted to lowercase.
// Write a C program to read a word and perform this task. Program should print the
// converted string.
// (NOTE: Don’t use any String built-in functions).

#include <stdio.h>
int main()
{
    char str[100];
    scanf("%s", str);
    int upper = 0, lower = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
            upper++;
        else
            lower++;
        if (upper > lower)
        {
            for (int i = 0; str[i] != '\0'; i++)
            {
                if (str[i] >= 'a' && str[i] <= 'z')
                    str[i] = str[i] - 32;
            }
        }
        else
        {
            for (int i = 0; str[i] != '\0'; i++)
            {
                if (str[i] >= 'A' && str[i] <= 'Z')
                    str[i] = str[i] + 32;
            }
        }
        printf("%s", str);
        return 0;
    }