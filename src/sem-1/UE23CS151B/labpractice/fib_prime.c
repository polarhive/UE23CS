#include <stdio.h>
int main()
{
    int limit;
    if (scanf("%d", &limit) != 1 || limit <= 0)
    {
        printf("Wrong input\n");
        return 0;
    }
    int prev = 0, curr = 1, next, sum = 0;
    while (curr <= limit)
    {
        int is_prime = 1;
        if (curr == 1)
        {
            is_prime = 0;
        }
        else
        {
            for (int i = 2; i * i <= curr; i++)
            {
                if (curr % i == 0)
                {
                    is_prime = 0;
                    break;
                }
            }
        }
        if (is_prime)
            sum += curr;
        next = prev + curr;
        prev = curr;
        curr = next;
    }
    printf("%d\n", sum);
    return 0;
}