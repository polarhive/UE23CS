// Write a C program to reverse the individual words in a given string. A word is defined as
// a sequence of non-space characters. The program should take a string as input, reverse
// each word in the string, and print the resulting string. (Note: You are allowed to use
// strlen() to find the length of the String, if required).

// Input: A string containing a sequence of words separated by spaces. The length of the string does
// not exceed 100 characters.
// Output: Print the input string after reversing each individual word.

#include <stdio.h>
#include <string.h>
void reverseWord(char str[], int start, int end)
{
    while (start < end)
    {
        char temp;
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}
int main()
{
    char str[100];
    scanf("%[^\n]s", str);
    int start = 0;
    for (int i = 0; i <= strlen(str); i++)
    {
        if (str[i] == ' ' || str[i] == '\0')
        {
            reverseWord(str, start, i - 1);
            start = i + 1;
        }
    }
    printf("%s", str);
    return 0;
}