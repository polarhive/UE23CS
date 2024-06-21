#include <stdio.h>

int main()
{
    char c = '\r';
    printf("Size of '\\r' is: %lu byte(s)\n", sizeof('\r'));
    printf("Size of char variable is: %lu byte(s)\n", sizeof(c));
    return 0;
}
