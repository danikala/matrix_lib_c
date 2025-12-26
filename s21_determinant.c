#include "s21_matrix.h"

int s21_determinant(matrix_t *A, double *result) {
  int flag = s21_error;
  if (check_m(A) || result == NULL)
    flag = s21_error;
  else if (A->columns != A->rows)
    flag = s21_calc_error;
  else {
    flag = s21_ok;
    *result = A->matrix[0][0];
    if (A->rows != 1) *result = determinant_recurs(A);
  }
  return flag;
}
