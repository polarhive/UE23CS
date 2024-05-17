// Write a Program in C to read a sentence including digits and print the product of all the
// digits in a String. Take care of special cases and alphabets too.
// (NOTE: Don’t use any String built-in functions).

#include <stdio.h>
int main()
{
    char str[100];
    scanf("%[^\n]s", str);
    int i = 0, product = 1, is_digit = 0;
    while (str[i] != '\0')
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            is_digit = 1;

            int num = str[i] - '0';
            product = product * num;
        }
        i++;
    }
    if (is_digit)
        printf("Product=%d", product);
    else
        printf("No digits found");
    return 0;
}