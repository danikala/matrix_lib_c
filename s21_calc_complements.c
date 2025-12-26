#include "s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int flag = s21_ok;
  if (check_m(A) || result == NULL)
    flag = s21_error;
  else if (A->columns != A->rows)
    flag = s21_calc_error;
  else if (A->columns == 1) {
    s21_create_matrix(A->rows, A->columns, result);
    result->matrix[0][0] = A->matrix[0][0];
  } else if (A->columns > 1) {
    s21_create_matrix(A->rows, A->columns, result);
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        matrix_t matrix_minor;
        s21_create_matrix(A->rows - 1, A->columns - 1, &matrix_minor);
        double det = 0.0;
        minor(A, i, j, &matrix_minor);
        s21_determinant(&matrix_minor, &det);
        result->matrix[i][j] = det;
        if ((i + j) % 2 != 0) result->matrix[i][j] *= -1;
        s21_remove_matrix(&matrix_minor);
      }
    }
  }
  return flag;
}
