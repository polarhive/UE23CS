#include <stdio.h>
int main()
{
    int L, R, sum = 0;
    scanf("%d %d", &L, &R);
    // Prime checking logic implemented directly in the main function
    for (int i = L; i <= R; i++)
    {
        int isPrime = 1; // Assume i is prime initially
        if (i <= 1)
        {
            isPrime = 0; // 0 and 1 are not prime
        }
        else
        {
            for (int j = 2; j * j <= i; j++)
            {
                if (i % j == 0)
                {
                    isPrime = 0; // If i is divisible by any number other than 1 and itself, it's not prime
                    break;
                }
            }
        }
        if (isPrime)
        {
            sum += i; // Add prime numbers to the sum
        }
    }
    printf("%d\n", sum);
    return 0;
}