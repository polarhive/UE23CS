#include <stdio.h>
int main()
{
    int num1, num2;
    int sumDivisors1 = 1, sumDivisors2 = 1;
    scanf("%d %d", &num1, &num2);
    // Calculate sum of divisors for num1
    for (int i = 2; i <= num1 / 2; i++)
    {
        if (num1 % i == 0)
        {
            sumDivisors1 += i;
        }
    }
    // Calculate sum of divisors for num2
    for (int i = 2; i <= num2 / 2; i++)
    {
        if (num2 % i == 0)
        {
            sumDivisors2 += i;
        }
    }
    // Check if num1 and num2 form an amicable pair
    int areAmicable1 = (sumDivisors1 == num2 && sumDivisors2 == num1);
    printf("%s", areAmicable1 == 1 ? "True" : "False");
    return 0;
}