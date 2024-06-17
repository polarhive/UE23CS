#include <stdio.h>

struct Example {
    int a : 4;
    int b : 8;
    int : 2;
};

int main() {
    struct Example ex;
    printf("Size of struct Example: %d bytes\n", sizeof(ex));
    return 0;
}
