
#include <stdio.h>
#include "matrix.h"

int main()
{
    Matrix* pMatrix = NULL;
    Matrix* pMatrix2 = NULL;
    Matrix* resMatrix = NULL;
    pMatrix = new_Matrix(3, 3);
    if (pMatrix == NULL) {
        return -1;
    }
    pMatrix->m->setAll(pMatrix, 1);
    pMatrix2 = new_Matrix(3, 3);
    if (pMatrix2 == NULL) {
        return -1;
    }
    pMatrix2->m->setAll(pMatrix2, 1);

    double element = 0;
    pMatrix->m->setElement(pMatrix, 0, 0, 65.9);
    element = pMatrix->m->getElement(pMatrix, 0, 0);
    pMatrix->m->setElement(pMatrix, 0, 1, 5441245.222);

    // if (pMatrix->multiply(pMatrix, pMatrix2) != 0)
    //     return -1;
    resMatrix = Matrix_multiply(pMatrix, pMatrix2);
    pMatrix->m->multiply(pMatrix, pMatrix2);
    pMatrix->m->display(resMatrix);
    if (resMatrix == NULL) {
        return -1;
    }
    if (resMatrix == NULL) {
        return -1;
    }
    printf("element: %f\n", element);
    pMatrix->m->display(resMatrix);

    pMatrix->m->Delete(pMatrix);
    pMatrix2->m->Delete(pMatrix2);
    resMatrix->m->Delete(resMatrix);
    return 0;
}
