// Program that demonstrates the usage of pointers for reading integers
// for a two-dimensional array. Also, display the elements of the same
// array using Pointer.

#include <stdio.h>
int main()
{
    int row, col;
    int i, j;
    scanf("%d%d", &row, &col);
    int matrix[row][col];
    int(*p)[col];
    p = matrix;
    for (i = 0; i < row; i++)
        for (j = 0; j < col; j++)
            scanf("%d", (*(p + i) + j));
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            printf("%d ", *(*(p + i) + j));
        }
        printf("\n");
    }
    return 0;
}