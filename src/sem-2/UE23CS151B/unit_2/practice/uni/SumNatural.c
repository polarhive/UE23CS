// Sum of natural numbers using recursion

#include <stdio.h>

int sum(int a); // Function declaration

int main(void)
{
    int num, x;

    printf("Enter a number: ");
    scanf("%d", &num);

    x = sum(num);

    printf("sum of natural number = %d", x);
    return 0;
}

int sum(int a)
{
    if (a != 0)
        return a + sum(a - 1); // sum() calls itself
    else
        return a;
}
