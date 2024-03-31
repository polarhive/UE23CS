#include <stdio.h>
int main()
{
    int rows, i, j, k;
    scanf("%d", &rows);
    for (i = 1; i <= rows; i++)
    {
        for (j = 1; j < i; j++)
        {
            printf(" ");
        }
        for (k = i; k <= rows; k++)
        {
            if (i == 1 || k == i || k == rows)
            {
                printf("* ");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
    for (i = rows - 1; i >= 1; i--)
    {
        for (j = 1; j < i; j++)
        {
            printf(" ");
        }
        for (k = i; k <= rows; k++)
        {
            if (i == 1 || k == i || k == rows)
            {
                printf("* ");
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