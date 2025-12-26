#include "s21_matrix.h"

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int flag = s21_ok;
  if (check_m(A) || check_m(B))
    flag = s21_error;
  else if (A->rows != B->rows || A->columns != B->columns)
    flag = s21_calc_error;
  else if (A->rows == B->rows && A->columns == B->columns && flag == s21_ok) {
    if (s21_create_matrix(A->rows, A->columns, result) == 0) {
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++)
          result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
      }
    } else
      flag = s21_error;
  } else
    flag = s21_error;
  return flag;
}
