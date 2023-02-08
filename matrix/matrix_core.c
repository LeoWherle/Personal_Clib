
#include <unistd.h>
#include <stdlib.h>
#include "matrix.h"

static Matrix_Methods_t MatrixInterfaceLocation = {
    .Delete = delete_Matrix,
    .display = Matrix_display,
    .getRows = Matrix_getRows,
    .getCols = Matrix_getCols,
    .getElement = Matrix_getElement,
    .setElement = Matrix_setElement,
    .setAll = Matrix_setAll,
    .copy = copy_Matrix,

    .add = MatrixMethod_add,
    .subtract = MatrixMethod_subtract,
    .multiply = MatrixMethod_multiply,
    .transpose = MatrixMethod_transpose,
    .inverse = MatrixMethod_inverse
};


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
    pMatrix->data = NULL;
    pMatrix->data = malloc(sizeof(double*)*rows);
    if (pMatrix->data == NULL) {
        return NULL;
    }
    for (i = 0; i < rows; i++) {
        pMatrix->data[i] = NULL;
        pMatrix->data[i] = malloc(sizeof(double)*cols);
        if (pMatrix->data[i] == NULL) {
            return NULL;
        }
    }
    pMatrix->m = &MatrixInterfaceLocation;
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
