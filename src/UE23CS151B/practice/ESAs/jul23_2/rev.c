#include <stdio.h>

int main()
{
    int num, temp, digitCount = 0;
    printf("Enter a number: ");
    scanf("%d", &num);
    temp = num;

    printf("The reverse of the number is ");
    while (temp != 0)
    {
        printf("%d", temp % 10);
        temp /= 10;
        ++digitCount;
    }
    printf("\n");

    printf("The number has %d digits.\n", digitCount);
    return 0;
}
