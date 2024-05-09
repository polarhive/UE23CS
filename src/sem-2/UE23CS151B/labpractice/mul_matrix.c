#include <stdio.h>
#include <stdlib.h>
int main()
{
    int m1[10][10], m2[10][10], product[10][10];
    int r1, c1, r2, c2;
    int i, j, k;
    scanf("%d%d", &r1, &c1);
    scanf("%d%d", &r2, &c2);
    if (c1 != r2)
    {
        printf("Matrix multiplication not possible");
        exit(0);
    }
    for (i = 0; i < r1; i++)
        for (j = 0; j < c1; j++)
            scanf("%d", &m1[i][j]);
    for (i = 0; i < r2; i++)
        for (j = 0; j < c2; j++)
            scanf("%d", &m2[i][j]);
    for (i = 0; i < r1; i++)
    {
        for (j = 0; j < c2; j++)
        {
            product[i][j] = 0;
        }
    }
    for (i = 0; i < r1; i++)
    {
        for (j = 0; j < c2; j++)
        {
            for (k = 0; k < c1; k++)
            {
                product[i][j] = product[i][j] + m1[i][k] * m2[k][j];
            }
        }
    }

    for (i = 0; i < r1; i++)
    {
        for (j = 0; j < c2; j++)
        {
            printf("%d ", product[i][j]);
        }
        printf("\n");
    }
    return 0;
}