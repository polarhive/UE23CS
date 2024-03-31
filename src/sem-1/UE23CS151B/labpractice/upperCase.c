#include <stdio.h>
int main()
{
    char ch;
    ch = getchar();
    putchar(ch - 'a' + 'A');
    return 0;
}