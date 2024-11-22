#include <stdio.h>

int main() {
    printf("Size of void function return: %zu\n", sizeof(void));
    printf("Size of void function return: %zu\n", sizeof(main()));
    return 0;
}
