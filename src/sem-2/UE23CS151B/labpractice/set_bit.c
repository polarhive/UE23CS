#include <stdio.h>
int main()
{
    int number, bitPosition;
    scanf("%d", &number);
    scanf("%d", &bitPosition);
    if ((number & (1 << bitPosition)) != 0)
    {
        printf("BIT IS SET\n");
    }
    else
    {
        printf("BIT IS NOT SET\n");
    }

    int setNumber = number | (1 << bitPosition);
    printf("%d\n", setNumber);

    int clearNumber = number & ~(1 << bitPosition);
    printf("%d\n", clearNumber);
    return 0;
}