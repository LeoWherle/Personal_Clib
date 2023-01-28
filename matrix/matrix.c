
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "matrix.h"

static void Matrix_interfaces(Matrix* pMatrix)
{
    pMatrix->Delete = delete_Matrix;
    pMatrix->display = Matrix_display;
    pMatrix->getRows = Matrix_getRows;
    pMatrix->getCols = Matrix_getCols;
    pMatrix->getElement = Matrix_getElement;
    pMatrix->setElement = Matrix_setElement;
    pMatrix->setAll = Matrix_setAll;
    pMatrix->add = Matrix_add;
    pMatrix->subtract = Matrix_subtract;
    pMatrix->multiply = Matrix_multiply;
    pMatrix->transpose = Matrix_transpose;
    pMatrix->inverse = Matrix_inverse;
}

Matrix* new_Matrix(int rows, int cols)
{
    Matrix* pMatrix = NULL;
    int i = 0;

    pMatrix = (Matrix*)malloc(sizeof(Matrix));
    if (pMatrix == NULL) {
        return NULL;
    }
    pMatrix->rows = rows;
    pMatrix->cols = cols;
    pMatrix->data = (double**)malloc(sizeof(double*)*rows);
    if (pMatrix->data == NULL) {
        return NULL;
    }
    for (i = 0; i < rows; i++) {
        pMatrix->data[i] = (double*)malloc(sizeof(double)*cols);
        if (pMatrix->data[i] == NULL) {
            return NULL;
        }
    }
    Matrix_interfaces(pMatrix);
    return pMatrix;
}

void delete_Matrix(Matrix* pMatrix)
{
    int i = 0;
    for (i = 0; i < pMatrix->rows; i++) {
        free(pMatrix->data[i]);
    }
    free(pMatrix->data);
    free(pMatrix);
}

void Matrix_display(Matrix* pMatrix)
{
    int i = 0;
    int j = 0;
    for (i = 0; i < pMatrix->rows; i++) {
        for (j = 0; j < pMatrix->cols; j++) {
            printf("%f\t", pMatrix->data[i][j]);
        }
        printf("\n");
    }
}

void Matrix_display_element(Matrix* pMatrix, int row, int col)
{
    printf("%f", pMatrix->data[row][col]);
}

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

int main()
{
    Matrix* pMatrix = NULL;
    Matrix* pMatrix2 = NULL;
    Matrix* resMatrix = NULL;
    pMatrix = new_Matrix(3, 3);
    if (pMatrix == NULL) {
        return -1;
    }
    pMatrix->setAll(pMatrix, 1);
    pMatrix2 = new_Matrix(3, 3);
    if (pMatrix2 == NULL) {
        return -1;
    }
    pMatrix2->setAll(pMatrix2, 1);

    double element = 0;
    pMatrix->setElement(pMatrix, 0, 0, 65.9);
    element = pMatrix->getElement(pMatrix, 0, 0);
    pMatrix->setElement(pMatrix, 0, 1, 5441245.222);

    resMatrix = pMatrix->multiply(pMatrix, pMatrix2);
    if (resMatrix == NULL) {
        return -1;
    }
    printf("element: %f\n", element);
    pMatrix->display(resMatrix);
    pMatrix->Delete(pMatrix);
    pMatrix2->Delete(pMatrix2);
    resMatrix->Delete(resMatrix);
    return 0;
}
