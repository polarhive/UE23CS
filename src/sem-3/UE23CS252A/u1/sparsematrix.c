#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int row;
    int col;
    int value;
} Element;

typedef struct
{
    int rows;
    int cols;
    int num; // Number of non-zero elements
    Element *elements;
} SparseMatrix;

SparseMatrix *createSparseMatrix(int rows, int cols, int num)
{
    SparseMatrix *sm = (SparseMatrix *)malloc(sizeof(SparseMatrix));
    sm->rows = rows;
    sm->cols = cols;
    sm->num = num;
    sm->elements = (Element *)malloc(sm->num * sizeof(Element));
    return sm;
}

void insertElement(SparseMatrix *sm, int index, int row, int col, int value)
{
    if (index >= 0 && index < sm->num)
    {
        sm->elements[index].row = row;
        sm->elements[index].col = col;
        sm->elements[index].value = value;
    }
}

void displaySparseMatrix(SparseMatrix *sm)
{
    int k = 0;
    for (int i = 0; i < sm->rows; i++)
    {
        for (int j = 0; j < sm->cols; j++)
        {
            if (k < sm->num && sm->elements[k].row == i && sm->elements[k].col == j)
            {
                printf("%d ", sm->elements[k].value);
                k++;
            }
            else
            {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

int main()
{
    int rows = 4;
    int cols = 5;
    int num = 4; // Number of non-zero elements

    SparseMatrix *sm = createSparseMatrix(rows, cols, num);

    insertElement(sm, 0, 0, 1, 5);
    insertElement(sm, 1, 1, 3, 8);
    insertElement(sm, 2, 2, 2, 6);
    insertElement(sm, 3, 3, 4, 9);

    printf("Sparse Matrix:\n");
    displaySparseMatrix(sm);

    free(sm->elements);
    free(sm);

    return 0;
}