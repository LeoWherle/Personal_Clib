
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

    // if (pMatrix->multiply(pMatrix, pMatrix2) != 0)
    //     return -1;
    resMatrix = Matrix_multiply(pMatrix, pMatrix2);
    if (resMatrix == NULL) {
        return -1;
    }
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
