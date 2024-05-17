// Write You are tasked with creating a text compression utility. The compression
// algorithm replaces repeated characters in the text with a number indicating the count of
// repetitions.
// Eg 1:
// Text (before Compression) : aaabbbccc
// Text (after Compression) : a3b3c3
// Eg 2:
// Text (before Compression) : HELLO
// Text (after Compression) : H1E1L2O1
// Write a C program that reads a word and print the compressed form of it.

#include <stdio.h>
void compress(char *text)
{
    char current = text[0];
    int count = 1;
    for (int i = 1; text[i] != '\0'; i++)
    {
        if (text[i] == current)
        {
            count++;
        }
        else
        {
            printf("%c%d", current, count);
            current = text[i];
            count = 1;
        }
    }
    printf("%c%d\n", current, count); // Print the last character and count
}
int main()
{
    char text[101];
    scanf(" %[^\n]", text); // Read entire text with spaces
    compress(text);
    return 0;
}