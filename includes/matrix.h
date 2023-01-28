
typedef struct _Matrix Matrix;
/**
 * @brief Matrix structure
 * 
 * @param rows Number of rows
 */
typedef void (*MatrixDelete)(Matrix *m);
typedef void (*MatrixDisplay)(Matrix *m);
typedef void (*MatrixDisplayElement)(Matrix *m, int row, int col);
typedef int (*MatrixGetRows)(Matrix *m);
typedef int (*MatrixGetCols)(Matrix *m);
typedef double (*MatrixGetElement)(Matrix *m, int row, int col);
typedef void (*MatrixSetElement)(Matrix *m, int row, int col, double value);
typedef void (*MatrixSetAll)(Matrix *m, double value);

typedef Matrix *(*MatrixAdd)(Matrix *m, Matrix *n);
typedef Matrix *(*MatrixSubtract)(Matrix *m, Matrix *n);
typedef Matrix *(*MatrixMultiply)(Matrix *m, Matrix *n);
typedef Matrix *(*MatrixTranspose)(Matrix *m);
typedef Matrix *(*MatrixInverse)(Matrix *m);


typedef struct _Matrix {
    int rows;
    int cols;
    double **data;

    // Interface
    MatrixDelete Delete;
    MatrixDisplay display;
    MatrixDisplayElement displayElement;
    MatrixGetRows getRows;
    MatrixGetCols getCols;
    MatrixGetElement getElement;
    MatrixSetElement setElement;
    MatrixSetAll setAll;

    MatrixAdd add;
    MatrixSubtract subtract;
    MatrixMultiply multiply;
    MatrixTranspose transpose;
    MatrixInverse inverse;
} Matrix;

Matrix *new_Matrix(int rows, int cols);
//void Matrix_interfaces(Matrix *m);
void delete_Matrix(Matrix *m);

void Matrix_display(Matrix *m);
void Matrix_display_element(Matrix *m, int row, int col);
int Matrix_getRows(Matrix *m);
int Matrix_getCols(Matrix *m);
double Matrix_getElement(Matrix *m, int row, int col);
void Matrix_setElement(Matrix *m, int row, int col, double value);
void Matrix_setAll(Matrix *m, double value);

Matrix *Matrix_add(Matrix *m, Matrix *n);
Matrix *Matrix_subtract(Matrix *m, Matrix *n);
Matrix *Matrix_multiply(Matrix *m, Matrix *n);
Matrix *Matrix_transpose(Matrix *m);
Matrix *Matrix_inverse(Matrix *m);
