
typedef struct Matrix_s Matrix;

typedef void (*MatrixDelete)(Matrix *m);
typedef void (*MatrixDisplay)(Matrix *m);
typedef void (*MatrixDisplayElement)(Matrix *m, int row, int col);
typedef int (*MatrixGetRows)(Matrix *m);
typedef int (*MatrixGetCols)(Matrix *m);
typedef double (*MatrixGetElement)(Matrix *m, int row, int col);
typedef void (*MatrixSetElement)(Matrix *m, int row, int col, double value);
typedef void (*MatrixSetAll)(Matrix *m, double value);
typedef int (*MatrixSetIdentity)(Matrix *m);
typedef int (*MatrixCopy)(Matrix *m, Matrix *n);

typedef int (*MatrixAdd)(Matrix *m, Matrix *n);
typedef int (*MatrixSubtract)(Matrix *m, Matrix *n);
typedef int (*MatrixMultiply)(Matrix *m, Matrix *n);
typedef int (*MatrixTranspose)(Matrix *m);
typedef int (*MatrixInverse)(Matrix *m);

typedef struct Matrix_Methods_s {
    // Interface
    MatrixDelete Delete;
    MatrixDisplay display;
    MatrixDisplayElement displayElement;
    MatrixGetRows getRows;
    MatrixGetCols getCols;
    MatrixGetElement getElement;
    MatrixSetElement setElement;
    MatrixSetAll setAll;
    MatrixSetIdentity setIdentity;
    MatrixCopy copy;

    MatrixAdd add;
    MatrixSubtract subtract;
    MatrixMultiply multiply;
    MatrixTranspose transpose;
    MatrixInverse inverse;
}Matrix_Methods_t;

typedef struct Matrix_s {
    int rows;
    int cols;
    double **data;

    Matrix_Methods_t *m;
} Matrix;

Matrix *new_Matrix(int rows, int cols);
Matrix *new_IdentityMatrix(int rows, int cols);
void delete_Matrix(Matrix *m);

Matrix *Matrix_add(Matrix *m, Matrix *n);
Matrix *Matrix_subtract(Matrix *m, Matrix *n);
Matrix *Matrix_multiply(Matrix *m, Matrix *n);
Matrix *Matrix_transpose(Matrix *m);
Matrix *Matrix_inverse(Matrix *m);


void Matrix_display(Matrix *m);
void Matrix_display_element(Matrix *m, int row, int col);
int Matrix_getRows(Matrix *m);
int Matrix_getCols(Matrix *m);
double Matrix_getElement(Matrix *m, int row, int col);
void Matrix_setElement(Matrix *m, int row, int col, double value);
void Matrix_setAll(Matrix *m, double value);
int setIdentity(Matrix *m);
int copy_Matrix(Matrix *m, Matrix *n);

int MatrixMethod_add(Matrix *m, Matrix *n);
int MatrixMethod_subtract(Matrix *m, Matrix *n);
int MatrixMethod_multiply(Matrix *m, Matrix *n);
int MatrixMethod_transpose(Matrix *m);
int MatrixMethod_inverse(Matrix *m);