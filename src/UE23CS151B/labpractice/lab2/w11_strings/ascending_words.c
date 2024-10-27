// Write a C program to arrange characters in each individual word of the string in
// ascending alphabetical order. The order of words in the string is not to be changed, only
// the order of characters in each individual word is to be ordered alphabetically.
// (Note : You are allowed to use strlen() to find the length of the String, if required).

#include <stdio.h>
#include <string.h>

void swap(char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}

void sortWord(char *word, int len)
{
    // Iterate through each character in the word
    for (int i = 0; i < len - 1; i++)
        // For each character, compare it with the next one and swap if necessary
        for (int j = 0; j < len - i - 1; j++)
            if (word[j] > word[j + 1])
                swap(&word[j], &word[j + 1]);
}

int main()
{
    char input[1000];
    int index = 0; // keep track of the current position in the buffer
    char ch;
    while ((ch = getchar()) != '\n' && ch != EOF)
        input[index++] = ch;
    input[index] = '\0';
    int len = strlen(input);

    // Initialize variables to keep track of the start of a word and its length
    int start = 0;
    int last_word_length = 0;

    // Iterate through each character in the string
    for (int i = 0; i <= len; i++)
        // If the character is a space, newline, or end of string, process the previous word
        if (input[i] == ' ' || input[i] == '\n' || input[i] == '\0')
        {
            // Sort the characters in the current word
            sortWord(input + start, last_word_length);
            start = i + 1;
            // Reset the length of the current word
            last_word_length = 0;
        }
        else
            last_word_length++;

    printf("%s", input);
    return 0;
}