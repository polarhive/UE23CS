#include <stdio.h>
int main()
{
    int choice;
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
    {
        int rows, i, j, number = 1;
        scanf("%d", &rows);
        for (i = 1; i <= rows; i++)
        {
            for (j = 1; j <= i; ++j)
            {
                printf("%d ", number);
                ++number;
            }
            printf("\n");
        }
        break;
    }
    default:
        printf("Invalid");
    }
    return 0;
}
