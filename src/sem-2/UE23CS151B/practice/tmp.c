#include <stdio.h>
typedef union x
{
    char a[20];
    long double b;
} x;

int main(void)
{
    printf("%llu", sizeof(x));
}