
#include <stddef.h>
#include "matrix.h"

Matrix *Matrix_add(Matrix *pMatrix1, Matrix *pMatrix2)
{
    Matrix *pResult = NULL;
    int i = 0;
    int j = 0;
    if (pMatrix1->rows != pMatrix2->rows || pMatrix1->cols != pMatrix2->cols) {
        return NULL;
    }
    pResult = new_Matrix(pMatrix1->rows, pMatrix1->cols);
    if (pResult == NULL) {
        return NULL;
    }
    for (i = 0; i < pMatrix1->rows; i++) {
        for (j = 0; j < pMatrix1->cols; j++) {
            pResult->data[i][j] = pMatrix1->data[i][j] + pMatrix2->data[i][j];
        }
    }
    return pResult;
}

Matrix *Matrix_subtract(Matrix *pMatrix1, Matrix *pMatrix2)
{
    Matrix *pResult = NULL;
    int i = 0;
    int j = 0;
    if (pMatrix1->rows != pMatrix2->rows || pMatrix1->cols != pMatrix2->cols) {
        return NULL;
    }
    pResult = new_Matrix(pMatrix1->rows, pMatrix1->cols);
    if (pResult == NULL) {
        return NULL;
    }
    for (i = 0; i < pMatrix1->rows; i++) {
        for (j = 0; j < pMatrix1->cols; j++) {
            pResult->data[i][j] = pMatrix1->data[i][j] - pMatrix2->data[i][j];
        }
    }
    return pResult;
}

Matrix *Matrix_multiply(Matrix *pMatrix1, Matrix *pMatrix2)
{
    Matrix *pResult = NULL;
    int i = 0;
    int j = 0;
    int k = 0;
    if (pMatrix1->cols != pMatrix2->rows) {
        return NULL;
    }
    pResult = new_Matrix(pMatrix1->rows, pMatrix2->cols);
    if (pResult == NULL) {
        return NULL;
    }
    pResult->setAll(pResult, 0);
    for (i = 0; i < pMatrix1->rows; i++) {
        for (j = 0; j < pMatrix2->cols; j++) {
            for (k = 0; k < pMatrix1->cols; k++) {
                pResult->data[i][j] += pMatrix1->data[i][k] * pMatrix2->data[k][j];
            }
        }
    }
    return pResult;
}

Matrix *Matrix_transpose(Matrix *pMatrix)
{
    Matrix *pResult = NULL;
    int i = 0;
    int j = 0;
    pResult = new_Matrix(pMatrix->cols, pMatrix->rows);
    if (pResult == NULL) {
        return NULL;
    }
    for (i = 0; i < pMatrix->rows; i++) {
        for (j = 0; j < pMatrix->cols; j++) {
            pResult->data[j][i] = pMatrix->data[i][j];
        }
    }
    return pResult;
}

Matrix *Matrix_inverse(Matrix *pMatrix)
{
    Matrix *pResult = NULL;
    int i = 0;
    int j = 0;
    int k = 0;
    double temp = 0;

    if (pMatrix->rows != pMatrix->cols) {
        return NULL;
    }
    pResult = new_Matrix(pMatrix->rows, pMatrix->cols);
    if (pResult == NULL) {
        return NULL;
    }
    pResult->setIdentity(pResult);
    for (i = 0; i < pMatrix->rows; i++) {
        temp = pMatrix->data[i][i];
        for (j = 0; j < pMatrix->cols; j++) {
            pMatrix->data[i][j] /= temp;
            pResult->data[i][j] /= temp;
        }
        for (j = 0; j < pMatrix->rows; j++) {
            if (i != j) {
                temp = pMatrix->data[j][i];
                for (k = 0; k < pMatrix->cols; k++) {
                    pMatrix->data[j][k] -= pMatrix->data[i][k] * temp;
                    pResult->data[j][k] -= pResult->data[i][k] * temp;
                }
            }
        }
    }
    return pResult;
}
