#include<stdio.h>
int main()
{
    int a = 11;
    printf("%d\n", a++ == 12 || a == 12);
    printf("%d\n", a);
}
