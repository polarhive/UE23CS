// Write a C program to check anagrams for a word. Program should read a word (Let it be
// target_word), followed by 3 words as input. Then, the program should check these 3
// words and print the words which are the anagram of the target_word.
// An anagram is a word or phrase formed by rearranging the letters of another word or
// phrase, using all the original letters exactly once.
// (Note: Don't use any String built-in functions).

#include <stdio.h>
int areAnagrams(const char *word1, const char *word2)
{
    int count1[26] = {0};
    int count2[26] = {0};
    for (int i = 0; word1[i] != '\0'; i++)
    {
        count1[word1[i] - 'a']++;
    }
    for (int i = 0; word2[i] != '\0'; i++)
    {
        count2[word2[i] - 'a']++;
    }
    for (int i = 0; i < 26; i++)
    {
        if (count1[i] != count2[i])
        {
            return 0;
        }
    }
    return 1;
}
int main()
{
    char word[11];
    char target_word[11];
    scanf("%s", target_word);
    for (int i = 0; i < 3; i++)
    {
        scanf("%s", word);
        if (areAnagrams(target_word, word))
        {
            printf("%s\n", word);
        }
    }
    return 0;