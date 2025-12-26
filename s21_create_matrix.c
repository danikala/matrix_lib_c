#include "s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  if (result == NULL || rows < 1 || columns < 1) return s21_error;
  int flag = s21_ok;

  result->rows = rows;
  result->columns = columns;

  result->matrix = (double **)calloc(rows, sizeof(double *));
  if (result->matrix == NULL) flag = s21_error;

  if (flag == s21_ok) {
    result->matrix[0] = (double *)calloc(rows * columns, sizeof(double));
    if (result->matrix[0] == NULL) {
      free(result->matrix);
      result->matrix = NULL;
      flag = s21_error;
    }
  }
  if (flag == s21_ok) {
    for (int i = 1; i < rows; i++)
      result->matrix[i] = result->matrix[0] + i * columns;
  }
  return flag;
}
