// Join a group of friends on an exciting quest to explore initialism. An abbreviation of a
// phrase that takes the first letter of each word, and is pronounced letter by letter.In this
// challenge, your input will be a sentence or group of words separated by space. The task
// is to fashion a single string containing all uppercase letters, extracting letters from each
// word at the 1st position.
// (NOTE: You are allowed to use the toupper( ) function from “ctype.h” to header file to
// convert characters to uppercase and strlen( ) function to find the length of the string , if
// required

#include <stdio.h>
#include <string.h>
#include <ctype.h>
void createInitialism(char *input, char *output)
{
    int len = strlen(input);
    int i, j = 0;

    // Convert the first letter of the first word to uppercase
    output[j++] = toupper(input[0]);
    for (i = 0; i < len; i++)
    {
        if (input[i] == ' ')
        {
            output[j++] = toupper(input[i + 1]);
        }
    }
    output[j] = '\0';
}
int main()
{
    char input[100];
    char output[100];
    scanf("%[^\n]", input);
    createInitialism(input, output);
    printf("%s", output);
    return 0;
}