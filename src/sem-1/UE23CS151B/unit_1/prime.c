#include <stdio.h>
int main() {
    int num = 3;
    int isPrime = 1;

    for (int i = 2; i <= num / 2; i++) {
        if (num % i == 0) {
            isPrime = 0; // not a prime so get out of the loop
            break;
        }
    }

    if (isPrime) {
        printf("%d is a prime number\n", num);
    } 
    else {
        printf("%d is not a prime number\n", num);
    }

    return 0;
}