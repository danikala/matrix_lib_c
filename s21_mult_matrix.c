#include "s21_matrix.h"

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int flag = s21_ok;
  if (check_m(A) || check_m(B))
    flag = s21_error;
  else if (A->columns != B->rows)
    flag = s21_calc_error;
  else {
    s21_create_matrix(A->rows, B->columns, result);
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < B->columns; j++) {
        result->matrix[i][j] = 0;
        for (int k = 0; k < A->columns; k++)
          result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
      }
    }
  }
  return flag;
}
