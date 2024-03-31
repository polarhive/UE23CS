#include <stdio.h>
int main()
{
    int n, temp, digit, rev = 0;
    scanf("%d", &n);
    temp = n;
    while (n > 0)
    {
        digit = n % 10;
        rev = rev * 10 + digit;
        n = n / 10;
    }
    if (temp == rev)
        printf("Palindrome.");
    else
        printf("Not a Palindrome.");
    return 0;
}