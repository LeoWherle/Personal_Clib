
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
    pMatrix->copy = copy_Matrix;

    pMatrix->add = MatrixMethod_add;
    pMatrix->subtract = MatrixMethod_subtract;
    pMatrix->multiply = MatrixMethod_multiply;
    pMatrix->transpose = MatrixMethod_transpose;
    pMatrix->inverse = MatrixMethod_inverse;
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
