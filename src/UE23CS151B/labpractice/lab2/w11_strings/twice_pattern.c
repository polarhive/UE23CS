// Write a function to check if a given pattern occurs twice in a sentence. Length of the
// pattern is less than that of the sentence. Print "True" only if there is a second occurrence
// of the pattern in the sentence, else print "False".
// (Note: You are allowed to use strlen() to find the length of the String, if required).

#include <stdio.h>
#include <string.h>
int isSecondOccurrence(const char *sentence, const char *pattern)
{
    int lenString = strlen(sentence);
    int lenPattern = strlen(pattern);
    if (lenPattern >= lenString)
        return 0;
    int i = 0;
    while (sentence[i] != '\0')
    {
        int j = 0;
        int match = 1;
        while (pattern[j] != '\0')
        {
            if (sentence[i + j] != pattern[j])
            {
                match = 0;
                break;
            }
            j++;
        }
        if (match)
        {
            i++;
            while (sentence[i] != '\0')
            {
                j = 0;
                match = 1;
                while (pattern[j] != '\0')
                {
                    if (sentence[i + j] != pattern[j])
                    {
                        match = 0;
                        break;
                    }
                    j++;
                }

                if (match)
                    return 1;
            }
        }
        i++;
        return 0;
        i++;
    }
    return 0;
}
int main()
{
    char sentence[100000];
    char pattern[100000];
    scanf("%s", sentence);
    scanf("%s", pattern);
    if (isSecondOccurrence(sentence, pattern) == 1)
    {
        printf("True\n");
    }
    else
    {
        printf("False\n");
    }

    return 0;
}