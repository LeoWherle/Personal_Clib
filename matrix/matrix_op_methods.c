
#include <stddef.h>
#include "matrix.h"

int MatrixMethod_add(Matrix *pMatrix1, Matrix *pMatrix2)
{
    int i = 0;
    int j = 0;

    if (pMatrix1->rows != pMatrix2->rows || pMatrix1->cols != pMatrix2->cols) {
        return 1;
    }
    for (i = 0; i < pMatrix1->rows; i++) {
        for (j = 0; j < pMatrix1->cols; j++) {
            pMatrix1->data[i][j] = pMatrix1->data[i][j] + pMatrix2->data[i][j];
        }
    }
    return 0;
}

int MatrixMethod_subtract(Matrix *pMatrix1, Matrix *pMatrix2)
{
    int i = 0;
    int j = 0;

    if (pMatrix1->rows != pMatrix2->rows || pMatrix1->cols != pMatrix2->cols) {
        return 1;
    }
    for (i = 0; i < pMatrix1->rows; i++) {
        for (j = 0; j < pMatrix1->cols; j++) {
            pMatrix1->data[i][j] = pMatrix1->data[i][j] - pMatrix2->data[i][j];
        }
    }
    return 0;
}

int MatrixMethod_multiply(Matrix *pMatrix1, Matrix *pMatrix2)
{
    Matrix *pResult = NULL;

    pResult = Matrix_multiply(pMatrix1, pMatrix2);
    if (pResult == NULL) {
        return 1;
    }
    pMatrix1->copy(pMatrix1, pResult);
    pResult->Delete(pResult);
    return 0;
}

int MatrixMethod_transpose(Matrix *pMatrix)
{
    Matrix *pResult = NULL;

    pResult = Matrix_transpose(pMatrix);
    if (pResult == NULL) {
        return 1;
    }
    pMatrix->copy(pMatrix, pResult);
    pResult->Delete(pResult);
    return 0;
}

int MatrixMethod_inverse(Matrix *pMatrix)
{
    Matrix *pResult = NULL;
    pResult = Matrix_inverse(pMatrix);
    if (pResult == NULL) {
        return 1;
    }
    pMatrix->copy(pMatrix, pResult);
    pResult->Delete(pResult);
    return 0;
}
