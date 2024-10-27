// The encoded message has to be decoded at the receiver’s end and so write a C program
// to decode the array of (encoded) integers being input. Th
#include <stdio.h>
int main()
{
    int encoded[100];
    int i = 0;
    // Reading the encoded integers
    while (scanf("%d", &encoded[i]) != EOF)
    {
        i++;
    }
    for (int j = 0; j < i; j++)
    {
        if (encoded[j] != 34)
        { // Skip decoding for space
            printf("%c", encoded[j] - 2);
        }
        else
        {
            printf(" "); // Print space if encoded value is 32
        }
    }
    return 0;
}