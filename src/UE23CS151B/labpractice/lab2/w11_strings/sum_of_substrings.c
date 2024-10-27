// Write a Program in C to to find the sum of all substrings of a string representing a number.
// Input: "1234”
// Output: 1670 Sum = 1+2 + 3 + 4 + 12 + 23 + 34 + 123 + 234 + 1234 = 1670
// (NOTE: You are allowed to use the built-in function strlen() if required).

#include <stdio.h>
#include <string.h>
int main()
{
    char str[100];
    int i, j, len, res, sum = 0;
    scanf("%s", str);
    len = strlen(str);
    for (i = 0; i < len; i++)
    {
        res = 0;
        for (j = i; j < len; j++)
        {
            res = res * 10 + (str[j] - '0');
            sum = sum + res;
        }
    }
    printf("Sum = %d", sum);
    return 0;
}