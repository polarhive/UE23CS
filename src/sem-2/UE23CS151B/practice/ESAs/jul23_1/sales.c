#include <stdio.h>

#define SALESMEN 3
#define ITEMS 2

int main()
{
    int sales[SALESMEN][ITEMS];
    int totals[ITEMS] = {0};

    for (int i = 0; i < SALESMEN; ++i)
    {
        printf("Enter the sales of 2 items sold by salesman %d: ", i);
        scanf("%d %d", &sales[i][0], &sales[i][1]);
    }

    for (int j = 0; j < ITEMS; ++j)
    {
        for (int i = 0; i < SALESMEN; ++i)
        {
            totals[j] += sales[i][j];
        }
    }

    for (int j = 0; j < ITEMS; ++j)
    {
        printf("Total sales of each item %d = %d\n", j, totals[j]);
    }
}
