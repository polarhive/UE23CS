// When texting or tweeting, it’s common to abbreviate words to save time or space, often
// by omitting vowels, similar to Twitter's original name 'twttr'. Write a C program to
// achieve the same effect, prompting the user for a string of text and then displaying that
// text without any vowels, whether in uppercase or lowercase.
// (NOTE: You are allowed to use the tolower( ) function from “ctype.h” to header file to
// convert characters to lowercase , if required)

#include <stdio.h>
#include <ctype.h>
// Function to check if a character is a vowel
int isVowel(char ch)
{
    ch = tolower(ch);
    return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
}
// Function to remove vowels from a string
void removeVowels(char *text)
{
    char *readPtr = text;
    char *writePtr = text;
    while (*readPtr)
    {
        if (!isVowel(*readPtr))
        {
            *writePtr = *readPtr;
            writePtr++;
        }
        readPtr++;
    }
    *writePtr = '\0'; // Null-terminate the modified string
}
int main()
{
    char inputText[100];
    scanf("%[^\n]", inputText);
    removeVowels(inputText);
    printf("%s", inputText);
    return 0;
}