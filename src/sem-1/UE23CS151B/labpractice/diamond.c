#include <stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n + 1; i += 2)
    {
        for (int j = 0; j < (n - i) / 2; j++)
        {
            printf(" ");
        }
        for (int k = 0; k < i; k++)
        {
            if (k == 0 || k == i - 1)
            {
                printf("*");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
    for (int i = n - 2; i >= 1; i -= 2)
    {
        for (int j = 0; j < (n - i) / 2; j++)
        {
            printf(" ");
        }
        for (int k = 0; k < i; k++)
        {
            if (k == 0 || k == i - 1)
            {
                printf("*");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}