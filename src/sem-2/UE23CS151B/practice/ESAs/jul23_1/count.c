/*
 * Write a C Program to count the number of digits in a number taken through
 * user input and also check if the individual digits are even or odd.
 *
 * Sample output:
 * Enter a number: 12345
 *
 * 5 is odd
 * 4 is even
 * 3 is odd
 * 2 is even
 * 1 is odd
 *
 * The number of digits in the number is: 5
 */

#include <stdio.h>

int main() {
    int number, digit, count = 0;

    printf("Enter a number: ");
    scanf("%d", &number);

    while (number > 0) {
        digit = number % 10;
        printf("%d is %s\n", digit, (digit % 2 == 0) ? "even" : "odd");
        number /= 10;
        count++;
    }

    printf("The number of digits in the number is: %d\n", count);
    return 0;
}
