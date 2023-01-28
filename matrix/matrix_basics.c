
#include "matrix.h"

double Matrix_getElement(Matrix* pMatrix, int row, int col)
{
    return pMatrix->data[row][col];
}

void Matrix_setElement(Matrix* pMatrix, int row, int col, double value)
{
    pMatrix->data[row][col] = value;
}

int Matrix_getRows(Matrix* pMatrix)
{
    return pMatrix->rows;
}

int Matrix_getCols(Matrix* pMatrix)
{
    return pMatrix->cols;
}
