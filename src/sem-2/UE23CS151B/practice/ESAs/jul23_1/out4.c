#include <stdio.h>
int main() {
    char a = 'z';
    char b = 'w';
    const char *c = &b;
    *c = 'x';
    printf("%c", *c);
    return 0;
}

