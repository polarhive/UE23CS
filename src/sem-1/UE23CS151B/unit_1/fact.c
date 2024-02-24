#include <stdio.h>
unsigned long factorial(int n) {
    unsigned long fact = 1;
    for(int i = 1; i <= n; ++i) {
        fact *= i;
    }
    return fact;
}

int main() {
    int num;
    printf("Enter a positive integer: ");
    scanf("%d", &num);
    printf("Factorial of %d = %llu", num, factorial(num));
    return 0;
}
