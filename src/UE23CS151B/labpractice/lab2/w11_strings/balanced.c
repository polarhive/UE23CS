// Write a program in C to read a word and check if it is balanced or not. Here, the word is
// said to be balanced if it contains an equal number of small letters and capital letters.
// Print “Balanced” if the word is balanced otherwise print “Not Balanced”.

#include <stdio.h>
#include <string.h>
int main()
{
    char s[20];
    scanf("%s", s);
    int sm = 0, cap = 0, n = strlen(s);
    for (int i = 0; i < n; i++)
    {
        if (s[i] >= 'A' && s[i] <= 'Z')
            cap += 1;
        else if (s[i] >= 'a' && s[i] <= 'z')

            sm += 1;
    }
    if (sm != 0 || cap != 0)
    {
        if (sm == cap)
            printf("Balanced");
        else
            printf("Not Balanced");
    }
    else
        printf("Word must contain alphabets");
    return 0;
}