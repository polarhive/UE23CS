// Write a C program that accepts a string, only replace vowels with their ASCII value, and
// then prints the final modified string. Also count number of consonants present in the
// string.
// Note: String may also contain special character

#include <stdio.h>
#include <string.h>
void replaceVowelsWithASCII(char *str, int *consonants)
{
    int i;
    for (i = 0; str[i] != '\0'; ++i)
    {
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' ||
            str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U')
        {
            printf("%d", str[i]);
        }
        else
        {
            if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
            {
                printf("%c", str[i]);
                (*consonants)++;
            }
            else
            {
                printf("%c", str[i]);
            }
        }
    }
}
int main()
{
    char str[100];
    int consonants = 0;
    scanf("%s", str);
    replaceVowelsWithASCII(str, &consonants);
    printf("\n%d", consonants);
    return 0;
}