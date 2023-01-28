
#include <stdio.h>
#include "matrix.h"

void Matrix_display_element(Matrix* pMatrix, int row, int col)
{
    printf("%f", pMatrix->data[row][col]);
}

void Matrix_display_column(Matrix* pMatrix, int row)
{
    int i = 0;

    for (i = 0; i < pMatrix->cols; i++) {
        Matrix_display_element(pMatrix, row, i);
        printf("\t");
    }
}

void Matrix_display(Matrix* pMatrix)
{
    int i = 0;

    for (i = 0; i < pMatrix->rows; i++) {
        Matrix_display_column(pMatrix, i);
        printf("\n");
    }
}
