#include "s21_matrix.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int flag = SUCCESS;
  if (check_m(A) || check_m(B))
    flag = FAILURE;
  else if (A->rows == B->rows && A->columns == B->columns) {
    for (int i = 0; i < A->rows && flag == SUCCESS; i++) {
      for (int j = 0; j < A->columns && flag == SUCCESS; j++) {
        if ((float)A->matrix[i][j] != (float)B->matrix[i][j]) {
          flag = FAILURE;
        }
      }
    }
  } else
    flag = FAILURE;
  return flag;
}
