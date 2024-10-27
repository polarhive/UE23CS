#include <stdio.h>
int main() {
    int numbers[5] = {10, 20, 30, 40, 50}; // declare and initialize an array of 5 integers
    for (int i = 0; i < 5; i++) {
        printf("element at index %d: %d\n", i, numbers[i]);
    }
    return 0;
}
