// Write a C program that takes a sentence as input and prints alternate words in
// uppercase starting from the 1st word, and rest in lowercase. For example, if a
// sentence has 5 words then the 1st, 3rd and 5th word will have all characters in
// uppercase while the 2nd and 4th word will have all characters in lowercase.
// (Note: Don't use any String built-in functions).

#include <stdio.h>
int main()
{
    char input[1000];
    int i = 0;
    char c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
        input[i++] = c;
    }
    input[i] = '\0';
    int uppercase = 1;
    for (i = 0; input[i] != '\0'; i++)
    {
        if (input[i] == ' ')
        {
            uppercase = !uppercase;
            putchar(' ');
        }
        else
        {
            if (uppercase)
                putchar(input[i] >= 'a' && input[i] <= 'z' ? input[i] - 'a' + 'A' : input[i]);
            else
                putchar(input[i] >= 'A' && input[i] <= 'Z' ? input[i] - 'A' + 'a' : input[i]);
        }
    }
    return 0;
}