// Write a program in C that reads a word and perform the Right Rotation of the given word
// by a number n. (Note: You are allowed to use strlen() to find the length of the word, if
// required).

#include <stdio.h>
#include <string.h>

int main()
{
    int n;
    char s[20];
    char last;
    scanf("%s", s);
    scanf("%d", &n);
    int len = strlen(s);
    for (int i = 0; i < n; i++)
    {
        last = s[len - 1];
        for (int i = len - 2; i >= 0; i--)
            s[i + 1] = s[i];
        s[0] = last;
    }
    printf("%s", s);
    return 0;
}