
#include "matrix.h"

void Matrix_setAll(Matrix* pMatrix, double value)
{
    int i = 0;
    int j = 0;

    for (i = 0; i < pMatrix->rows; i++) {
        for (j = 0; j < pMatrix->cols; j++) {
            pMatrix->data[i][j] = value;
        }
    }
}

int Matrix_setIdentity(Matrix* pMatrix)
{
    int i = 0;

    if (pMatrix->rows != pMatrix->cols) {
        return 1;
    }
    pMatrix->setAll(pMatrix, 0);
    for (i = 0; i < pMatrix->rows; i++) {
        pMatrix->data[i][i] = 1;
    }
    return 0;
}

int copy_Matrix(Matrix *pMatrix1, Matrix *pMatrix2)
{
    int i = 0;
    int j = 0;
    if (pMatrix1->rows != pMatrix2->rows || pMatrix1->cols != pMatrix2->cols) {
        return 1;
    }
    for (i = 0; i < pMatrix1->rows; i++) {
        for (j = 0; j < pMatrix1->cols; j++) {
            pMatrix1->data[i][j] = pMatrix2->data[i][j];
        }
    }
    return 0;
}