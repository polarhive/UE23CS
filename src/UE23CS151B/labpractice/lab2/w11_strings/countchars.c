// Write a program in C to read a sentence and print each character and its count in the
// sentence.
// (NOTE: Don’t use any String built-in functions).

#include <stdio.h>
int main()
{
    char str[100];
    int i, j, k, count = 0, n;
    scanf("%[^\n]s", str);
    for (i = 0; str[i] != '\0'; i++)
        ;
    n = i; // Getting the length of string
    for (i = 0; i < n; i++)
    {
        count = 1;
        if (str[i] != '\0')
        {
            {
                for (j = i + 1; j < n; j++)
                    if (str[i] == str[j])
                    {
                        count++;
                        str[j] = '\0';
                    }
            }
            printf("%c = %d\n", str[i], count);
        }
    }
    return 0;
}