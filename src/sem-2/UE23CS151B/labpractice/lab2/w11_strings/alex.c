// Once upon a time, in a programming kingdom, there was a curious coder named Alex.
// Alex was given a unique challenge by the wise programming wizard. Alex had to write a
// C program that could reverse a given string (let's call it string1) and compare it with
// another string (string2). The goal was to determine if the reversed string1 was equal to
// string2. If the two strings matched after the reversal of string1, the program should
// print "True"; otherwise, it should print "False"

#include <stdio.h>
#include <string.h>
void reverseString(char *str)
{
    int length = strlen(str);
    for (int i = 0; i < length / 2; i++)
    {
        char temp = str[i];

        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }
}
int main()
{
    char string1[101], string2[101];
    scanf("%s", string1);
    scanf("%s", string2);
    reverseString(string1);
    if (strcmp(string1, string2) == 0)
    {
        printf("True");
    }
    else
    {
        printf("False");
    }

    return 0;
}