#include <stdio.h>
int main()
{
    int numRows;
    scanf("%d", &numRows);
    if (numRows <= 0)
    {
        printf("Invalid input\n");
        return 0;
    }
    for (int i = numRows - 1; i >= 0; --i)
    {
        for (int space = 0; space < numRows - i - 1; ++space)
            printf(" ");
        for (int j = 0; j <= i; ++j)
        {
            long coefficient = 1;
            for (int k = 1; k <= j; ++k)
            {
                coefficient *= (i - k + 1);
                coefficient /= k;
            }
            printf("%ld ", coefficient);
        }
        printf("\n");
    }
    return 0;
}