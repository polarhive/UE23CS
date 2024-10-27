// Write a C program to check if two strings are anagrams of each other, an anagram is a
// word formed by rearranging the letters of a different word, typically using all the
// original letters exactly once.

#include <stdio.h>
#include <string.h>
// Function to check if two strings are anagrams
int areAnagrams(const char *str1, const char *str2)
{
    int count1[256] = {0}; // Assuming ASCII characters
    int count2[256] = {0};
    // Calculate frequency of characters in the first string
    for (int i = 0; str1[i] != '\0'; i++)
    {
        count1[(int)str1[i]]++;
    }
    // Calculate frequency of characters in the second string
    for (int i = 0; str2[i] != '\0'; i++)
    {
        count2[(int)str2[i]]++;
    }

    // Check if both strings have the same character frequencies
    for (int i = 0; i < 256; i++)
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
    char str1[100], str2[100];
    // Input strings
    scanf("%s", str1);
    scanf("%s", str2);
    // Check if the strings are anagrams
    if (areAnagrams(str1, str2) == 1)
    {
        printf("'%s' and '%s' are anagrams.\n", str1, str2);
    }
    else
    {
        printf("'%s' and '%s' are not anagrams.\n", str1, str2);
    }
    return 0;
}