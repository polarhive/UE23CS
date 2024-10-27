#include <stdio.h>

struct temp {
    int a[10];
    char p;
};

int main() {
    printf("Size of struct temp: %zu bytes\n", sizeof(struct temp));
    return 0;
}

// padding of 4 bytes!
