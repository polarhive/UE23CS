// Write a program in C to read a sentence and convert all the alphabets into uppercase.
// (NOTE: Don’t use any String built-in functions).

#include <stdio.h>
void to_upper(char str[])
{
    int i = 0;
    // Loop through the string
    while (str[i] != '\0')
    {
        // If the current character is a lowercase letter, convert it to uppercase
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] = str[i] + 'A' - 'a'; // Conversion to uppercase
        i++;
    }
    printf("%s", str);
}
int main()
{
    char str[50];
    scanf("%[^\n]s", str);
    to_upper(str);
    return 0;
}