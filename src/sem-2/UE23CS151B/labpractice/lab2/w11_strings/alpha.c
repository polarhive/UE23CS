// Write a C program to arrange characters in each individual word of the string in
// ascending alphabetical order. The order of words in the string is not to be changed, only
// the order of characters in each individual word is to be ordered alphabetically.
//(Note : You are allowed to use strlen() to find the length of the String, if required).

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
    for (int i = 0; i < len - 1; i++)
        for (int j = 0; j < len - i - 1; j++)
            if (word[j] > word[j + 1])
                swap(&word[j], &word[j + 1]);
}
int main()
{
    char input[1000];
    int index = 0;
    char ch;
    while ((ch = getchar()) != '\n' && ch != EOF)
        input[index++] = ch;
    input[index] = '\0';
    int len = strlen(input);
    int start = 0;
    int last_word_length = 0;
    for (int i = 0; i <= len; i++)
        if (input[i] == ' ' || input[i] == '\n' || input[i] == '\0')
        {
            sortWord(input + start, last_word_length);
            start = i + 1;
            last_word_length = 0;
        }
        else
            last_word_length++;

    printf("%s", input);
    return 0;
}