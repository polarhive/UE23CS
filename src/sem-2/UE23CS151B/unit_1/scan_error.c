#include <stdio.h>

int main() {
    int num;
    int result;

    printf("Enter a number: ");
    result = scanf("%d", &num);

    if (result < 0) { printf("Error occurred during input parsing\n"); } 
    else { printf("You entered: %d\n", num); }

    return 0;
}
