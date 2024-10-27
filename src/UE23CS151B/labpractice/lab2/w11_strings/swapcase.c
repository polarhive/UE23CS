// Write a program in C to read a sentence and replace lowercase characters with
// uppercase and vice versa.

#include <stdio.h>
#include <string.h>
int main()
{
    char str[100];        // Declare a character array to store the string
    int i;                // Declare variable for iteration
    scanf("%[^\n]", str); // Read a string from the standard input

    // Loop through each character of the string
    for (i = 0; str[i] != '\0'; i++)
    {
        // Check if the character is lowercase
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            // Convert to uppercase by subtracting 32 from ASCII value
            str[i] = str[i] - 32;
        }
        // Check if the character is uppercase
        else if (str[i] >= 'A' && str[i] <= 'Z')
        {
            // Convert to lowercase by adding 32 to ASCII value
            str[i] = str[i] + 32;
        }
    }
    printf("%s\n", str); // Output the modified string
    return 0;
}