// Write a Program in C to read a sentence including digits and print the Square of all the
// digits in a String. Take care of special cases.
// Input: He1llo We2lcome to C-Lab10
// Output: 1
// 4
// 1
// 0

#include <stdio.h>
int main()
{
    char str[100];
    scanf("%[^\n]s", str);

    int i = 0, is_digit = 0;
    while (str[i] != '\0')
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            is_digit = 1;
            int num = str[i] - '0';
            printf("%d\n", num * num);
        }
        i++;
    }
    if (!is_digit)
        printf("No digits found");
    return 0;
}