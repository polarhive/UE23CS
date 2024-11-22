#include<stdio.h>
int main()
{
    int num1;
    float num2;
    printf("Input an integer: ");
    scanf("%d", &num1); //store the value in this location <memory addr>
    printf("Input a float: ");
    scanf("%f", &num2);
    printf("\nThe return value is: %d\n", printf("%d", num1));
    printf("\nThe return value is: %d\n", printf("%f", num2));
    return 0;
}
