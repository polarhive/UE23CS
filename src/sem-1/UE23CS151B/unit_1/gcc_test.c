#include<stdio.h>
int main()
{
    int i = 1;
    i = ++i + i++ +2;
    printf("%d\n", i); // 7 on GCC, 6 on clang
}
