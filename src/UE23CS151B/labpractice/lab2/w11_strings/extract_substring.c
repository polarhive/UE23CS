// Write a program in C to extract a substring from a String. Program should read two
// integers, position and length of the substring and generate the substring as the output.
// (NOTE: Don’t use any String built-in functions).

#include <stdio.h>
int main()
{
    char s[100], sub[100];
    int pos, len, i = 0;
    scanf("%[^\n]s", s);
    scanf("%d", &pos); // Read the starting position for substring extraction
    scanf("%d", &len); // Read the length of the substring
    // Extracting the substring
    for (i = 0; i < len; i++)
        sub[i] = s[pos - 1 + i];             // Copy characters from the specified position into the substring
    sub[i] = '\0';                           // Add null terminator to mark the end of the substring
    printf("Extracted substring : %s", sub); // Display the extracted substring
}