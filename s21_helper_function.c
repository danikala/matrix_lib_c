#include "s21_matrix.h"

int check_m(matrix_t *A) {
  int flag = s21_ok;
  if (A != NULL && A->matrix != NULL && A->rows >= 1 && A->columns >= 1)
    flag = s21_ok;
  else
    flag = s21_error;
  return flag;
}

int minor(matrix_t *A, int row, int col, matrix_t *B) {
  int flag = s21_ok;
  if (check_m(A) || row < 0 || row >= A->rows || col < 0 || col >= A->columns)
    flag = s21_error;
  else if (A->rows != A->columns)
    flag = s21_calc_error;
  else {
    int k = 0;
    for (int i = 0; i < A->rows; i++) {
      if (i != row) {
        int l = 0;
        for (int j = 0; j < A->columns; j++)
          if (j != col) {
            B->matrix[k][l] = A->matrix[i][j];
            l++;
          }
        k++;
      }
    }
  }
  return flag;
}

int determinant_recurs(matrix_t *A) {
  double result = 0;
  if (A->rows == 2) {
    result =
        A->matrix[0][0] * A->matrix[1][1] - A->matrix[0][1] * A->matrix[1][0];
  } else {
    for (int i = 0; i < A->rows; i++) {
      matrix_t matrix_minor;
      if (s21_create_matrix(A->rows - 1, A->columns - 1, &matrix_minor) ==
          s21_ok) {
        minor(A, 0, i, &matrix_minor);
        result +=
            pow((-1), i) * A->matrix[0][i] * determinant_recurs(&matrix_minor);
        s21_remove_matrix(&matrix_minor);
      } else {
        s21_remove_matrix(&matrix_minor);
      }
    }
  }
  return result;
}