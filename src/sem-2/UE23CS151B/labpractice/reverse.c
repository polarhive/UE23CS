#include <stdio.h>
void reverse(int digit, int rev, int n)
{
    if (n > 0)
    {
        digit = n % 10;
        rev = rev * 10 + digit;
        reverse(digit, rev, n / 10);
    }
    else
        printf("%d", rev);
    return;
}
int main()
{
    int n;
    scanf("%d", &n);
    reverse(0, 0, n);
    return 0;
}