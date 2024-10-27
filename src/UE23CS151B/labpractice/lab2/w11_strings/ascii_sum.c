// Write a program in C to print the sum of ASCII values of all characters in a string.
// (NOTE: Don’t use any built-in function)

#include <stdio.h>
int main()
{
    char str[100];
    int i, sum = 0;
    scanf("%[^\n]s", str);
    i = 0;
    while (str[i] != '\0')
    {
        sum = sum + str[i];
        i++;
    }
    printf("%d", sum);
    return 0;
}