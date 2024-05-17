// Write a program in C to print the index of all vowels present in a sentence. If the sentence
// has no vowels, program should print “No vowels present”.
// (NOTE: Don’t use any String built-in functions).

#include <stdio.h>

int main()
{
    char str[255];
    int i;
    scanf("%[^\n]s", str);
    i = 0;
    int vc = 0;
    while (str[i] != '\0')
    {
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' ||
            str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U')
        {
            printf("%d ", i);
            vc++;
        }
        i++;
    }
    if (!vc)
        printf("No vowels present");
    return 0;
}