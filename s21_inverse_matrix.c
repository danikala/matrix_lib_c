#include "s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  if (check_m(A) || result == NULL) return s21_error;
  if (A->columns != A->rows) return s21_calc_error;
  int flag = s21_ok;
  double det = 0.0;
  s21_determinant(A, &det);
  if (fabs(det) > 1e-6) {
    matrix_t matrix_minor;
    flag = s21_calc_complements(A, &matrix_minor);
    if (flag == 0) {
      matrix_t matrix_trans;
      flag = s21_transpose(&matrix_minor, &matrix_trans);
      if (flag == 0) s21_mult_number(&matrix_trans, 1 / det, result);
      s21_remove_matrix(&matrix_trans);
    }
    s21_remove_matrix(&matrix_minor);
    if (A->columns == 1) result->matrix[0][0] = 1 / det;
  } else {
    flag = s21_calc_error;
  }
  return flag;
}
