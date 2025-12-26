#include <check.h>

#include "s21_matrix.h"

START_TEST(test_eq_1) {
  matrix_t A;
  matrix_t B;
  int rowsA = 100;
  int columnsA = 100;
  int columnsB = 100;
  int rowsB = 100;
  s21_create_matrix(rowsA, columnsA, &A);
  s21_create_matrix(rowsB, columnsB, &B);
  for (int i = 0; i < rowsA; i++) {
    for (int j = 0; j < columnsA; j++) {
      A.matrix[i][j] = 5.0;
      B.matrix[i][j] = 5.0;
    }
  }
  ck_assert_int_eq(s21_eq_matrix(&A, &B), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_eq_2) {
  matrix_t A;
  matrix_t B;
  int rowsA = 10;
  int columnsA = 5;
  int columnsB = 4;
  int rowsB = 1;
  s21_create_matrix(rowsA, columnsA, &A);
  s21_create_matrix(rowsB, columnsB, &B);
  ck_assert_int_eq(s21_eq_matrix(&A, &B), FAILURE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_eq_3) {
  matrix_t A;
  matrix_t B;
  int rowsA = 100;
  int columnsA = 100;
  int columnsB = 100;
  int rowsB = 100;
  s21_create_matrix(rowsA, columnsA, &A);
  s21_create_matrix(rowsB, columnsB, &B);
  for (int i = 0; i < rowsA; i++) {
    for (int j = 0; j < columnsA; j++) {
      A.matrix[i][j] = 5.0;
    }
  }
  for (int i = 0; i < rowsB; i++) {
    for (int j = 0; j < columnsB; j++) {
      B.matrix[i][j] = 5.01;
    }
  }
  ck_assert_int_eq(s21_eq_matrix(&A, &B), FAILURE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_sum_matrix_1) {
  matrix_t A;
  matrix_t B;
  matrix_t res = {0};
  matrix_t origin_res;
  int rowsA = 100;
  int columnsA = 100;
  int columnsB = 100;
  int rowsB = 100;
  int rowsRes = 100;
  int columnsRes = 100;
  s21_create_matrix(rowsA, columnsA, &A);
  s21_create_matrix(rowsB, columnsB, &B);
  s21_create_matrix(rowsRes, columnsRes, &origin_res);
  for (int i = 0; i < rowsA; i++) {
    for (int j = 0; j < columnsA; j++) {
      A.matrix[i][j] = 5.0;
    }
  }
  for (int i = 0; i < rowsB; i++) {
    for (int j = 0; j < columnsB; j++) {
      B.matrix[i][j] = 5.0;
    }
  }
  for (int i = 0; i < rowsRes; i++) {
    for (int j = 0; j < columnsRes; j++) {
      origin_res.matrix[i][j] = 10.0;
    }
  }
  ck_assert_int_eq(s21_sum_matrix(&A, &B, &res), s21_ok);
  ck_assert_int_eq(s21_eq_matrix(&origin_res, &res), SUCCESS);
  s21_remove_matrix(&res);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&origin_res);
}
END_TEST

START_TEST(test_sum_matrix_2) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t res = {0};
  int rowsA = -100;
  int columnsA = 100;
  int columnsB = 100;
  int rowsB = 100;
  s21_create_matrix(rowsA, columnsA, &A);
  A.rows = -100;
  s21_create_matrix(rowsB, columnsB, &B);
  ck_assert_int_eq(s21_sum_matrix(&A, &B, &res), s21_error);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_sum_matrix_3) {
  matrix_t A;
  matrix_t B;
  matrix_t res = {0};
  int rowsA = 2;
  int columnsA = 3;
  int columnsB = 5;
  int rowsB = 2;
  s21_create_matrix(rowsA, columnsA, &A);
  s21_create_matrix(rowsB, columnsB, &B);
  ck_assert_int_eq(s21_sum_matrix(&A, &B, &res), s21_calc_error);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST
START_TEST(test_sub_matrix_1) {
  matrix_t A;
  matrix_t B;
  matrix_t res = {0};
  matrix_t origin_res;
  int rowsA = 100;
  int columnsA = 100;
  int columnsB = 100;
  int rowsB = 100;

  s21_create_matrix(rowsA, columnsA, &A);
  s21_create_matrix(rowsB, columnsB, &B);
  s21_create_matrix(rowsA, columnsA, &origin_res);
  for (int i = 0; i < rowsA; i++) {
    for (int j = 0; j < columnsA; j++) {
      A.matrix[i][j] = 5.0;
    }
  }
  for (int i = 0; i < rowsB; i++) {
    for (int j = 0; j < columnsB; j++) {
      B.matrix[i][j] = 2.0;
    }
  }
  for (int i = 0; i < rowsA; i++) {
    for (int j = 0; j < columnsA; j++) {
      origin_res.matrix[i][j] = 3.0;
    }
  }
  ck_assert_int_eq(s21_sub_matrix(&A, &B, &res), s21_ok);
  ck_assert_int_eq(s21_eq_matrix(&origin_res, &res), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&res);
  s21_remove_matrix(&origin_res);
}
END_TEST

START_TEST(test_sub_matrix_2) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t res = {0};
  int rowsA = -100;
  int columnsA = 100;
  int columnsB = 100;
  int rowsB = 100;
  s21_create_matrix(rowsA, columnsA, &A);
  A.rows = -100;
  s21_create_matrix(rowsB, columnsB, &B);
  ck_assert_int_eq(s21_sub_matrix(&A, &B, &res), s21_error);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_sub_matrix_3) {
  matrix_t A;
  matrix_t B;
  matrix_t res = {0};
  int rowsA = 2;
  int columnsA = 3;
  int columnsB = 5;
  int rowsB = 2;
  s21_create_matrix(rowsA, columnsA, &A);
  s21_create_matrix(rowsB, columnsB, &B);
  ck_assert_int_eq(s21_sub_matrix(&A, &B, &res), s21_calc_error);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST
START_TEST(test_mult_number_1) {
  matrix_t A;
  matrix_t res = {0};
  matrix_t origin_res;
  int rowsA = 10;
  int columnsA = 10;
  int num = 10;
  s21_create_matrix(rowsA, columnsA, &A);
  s21_create_matrix(rowsA, columnsA, &origin_res);
  for (int i = 0; i < rowsA; i++) {
    for (int j = 0; j < columnsA; j++) {
      A.matrix[i][j] = 5.0;
    }
  }
  for (int i = 0; i < rowsA; i++) {
    for (int j = 0; j < columnsA; j++) {
      origin_res.matrix[i][j] = 50.0;
    }
  }
  ck_assert_int_eq(s21_mult_number(&A, num, &res), s21_ok);
  ck_assert_int_eq(s21_eq_matrix(&origin_res, &res), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&res);
  s21_remove_matrix(&origin_res);
}
END_TEST

START_TEST(test_mult_number_2) {
  matrix_t A = {0};
  matrix_t res = {0};
  int rowsA = -100;
  int columnsA = 100;
  int num = 10;
  s21_create_matrix(rowsA, columnsA, &A);
  A.rows = -100;
  ck_assert_int_eq(s21_mult_number(&A, num, &res), s21_error);
}
END_TEST

END_TEST
START_TEST(test_mult_matrix_1) {
  matrix_t A;
  matrix_t B;
  matrix_t res = {0};
  matrix_t origin_res;
  int rowsA = 2;
  int columnsA = 2;
  int columnsB = 2;
  int rowsB = 2;
  s21_create_matrix(rowsA, columnsA, &A);
  s21_create_matrix(rowsB, columnsB, &B);
  s21_create_matrix(rowsA, columnsA, &origin_res);
  A.matrix[0][0] = 1.0;
  A.matrix[0][1] = 2.0;
  A.matrix[1][0] = 3.0;
  A.matrix[1][1] = 4.0;
  B.matrix[0][0] = 5.0;
  B.matrix[0][1] = 6.0;
  B.matrix[1][0] = 7.0;
  B.matrix[1][1] = 8.0;
  origin_res.matrix[0][0] = 19.0;
  origin_res.matrix[0][1] = 22.0;
  origin_res.matrix[1][0] = 43.0;
  origin_res.matrix[1][1] = 50.0;
  ck_assert_int_eq(s21_mult_matrix(&A, &B, &res), s21_ok);
  ck_assert_int_eq(s21_eq_matrix(&origin_res, &res), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&res);
  s21_remove_matrix(&origin_res);
}
END_TEST

START_TEST(test_mult_matrix_2) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t res = {0};
  int rowsA = -100;
  int columnsA = 100;
  int columnsB = 100;
  int rowsB = 100;
  s21_create_matrix(rowsA, columnsA, &A);
  A.rows = -100;
  s21_create_matrix(rowsB, columnsB, &B);
  ck_assert_int_eq(s21_mult_matrix(&A, &B, &res), s21_error);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_mult_matrix_3) {
  matrix_t A;
  matrix_t B;
  matrix_t res = {0};
  int rowsA = 2;
  int columnsA = 3;
  int columnsB = 5;
  int rowsB = 2;
  s21_create_matrix(rowsA, columnsA, &A);
  s21_create_matrix(rowsB, columnsB, &B);
  ck_assert_int_eq(s21_mult_matrix(&A, &B, &res), s21_calc_error);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST
START_TEST(test_mult_matrix_4) {
  matrix_t A;
  matrix_t B;
  matrix_t res = {0};
  matrix_t origin_res;
  int rowsA = 2;
  int columnsA = 3;
  int rowsB = 3;
  int columnsB = 2;
  s21_create_matrix(rowsA, columnsA, &A);
  s21_create_matrix(rowsB, columnsB, &B);
  s21_create_matrix(rowsA, columnsB, &origin_res);
  A.matrix[0][0] = 1.5;
  A.matrix[0][1] = 2.7;
  A.matrix[0][2] = 3.3;
  A.matrix[1][0] = 0.44;
  A.matrix[1][1] = 5.34;
  A.matrix[1][2] = 6.32;
  B.matrix[0][0] = 1.5;
  B.matrix[0][1] = 232.3;
  B.matrix[1][0] = 0.34444;
  B.matrix[1][1] = 4.22;
  B.matrix[2][0] = 5.23;
  B.matrix[2][1] = 6.2;
  origin_res.matrix[0][0] = 20.438988f;
  origin_res.matrix[0][1] = 380.304000f;
  origin_res.matrix[1][0] = 35.552910f;
  origin_res.matrix[1][1] = 163.930800f;
  ck_assert_int_eq(s21_mult_matrix(&A, &B, &res), s21_ok);
  ck_assert_int_eq(s21_eq_matrix(&origin_res, &res), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&res);
  s21_remove_matrix(&origin_res);
}
END_TEST

START_TEST(test_transpose_matrix_1) {
  matrix_t A;
  matrix_t res = {0};
  matrix_t origin_res;
  int rowsA = 3;
  int columnsA = 2;
  int rowsRes = 2;
  int columnsRes = 3;
  s21_create_matrix(rowsA, columnsA, &A);
  s21_create_matrix(rowsRes, columnsRes, &origin_res);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 4;
  A.matrix[1][0] = 2;
  A.matrix[1][1] = 5;
  A.matrix[2][0] = 3;
  A.matrix[2][1] = 6;
  origin_res.matrix[0][0] = 1;
  origin_res.matrix[0][1] = 2;
  origin_res.matrix[0][2] = 3;
  origin_res.matrix[1][0] = 4;
  origin_res.matrix[1][1] = 5;
  origin_res.matrix[1][2] = 6;
  ck_assert_int_eq(s21_transpose(&A, &res), s21_ok);
  ck_assert_int_eq(s21_eq_matrix(&origin_res, &res), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&res);
  s21_remove_matrix(&origin_res);
}
END_TEST

START_TEST(test_calc_complements_matrix_1) {
  matrix_t A;
  matrix_t res = {0};
  matrix_t origin_res;
  int rowsA = 3;
  int columnsA = 3;
  int rowsRes = 3;
  int columnsRes = 3;
  s21_create_matrix(rowsA, columnsA, &A);
  s21_create_matrix(rowsRes, columnsRes, &origin_res);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 4;
  A.matrix[1][2] = 2;
  A.matrix[2][0] = 5;
  A.matrix[2][1] = 2;
  A.matrix[2][2] = 1;
  origin_res.matrix[0][0] = 0;
  origin_res.matrix[0][1] = 10;
  origin_res.matrix[0][2] = -20;
  origin_res.matrix[1][0] = 4;
  origin_res.matrix[1][1] = -14;
  origin_res.matrix[1][2] = 8;
  origin_res.matrix[2][0] = -8;
  origin_res.matrix[2][1] = -2;
  origin_res.matrix[2][2] = 4;
  ck_assert_int_eq(s21_calc_complements(&A, &res), s21_ok);
  ck_assert_int_eq(s21_eq_matrix(&origin_res, &res), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&res);
  s21_remove_matrix(&origin_res);
}
END_TEST
START_TEST(test_calc_complements_matrix_2) {
  matrix_t A = {0};
  matrix_t res = {0};
  A.rows = -1;
  A.columns = 2;
  ck_assert_int_eq(s21_calc_complements(&A, &res), s21_error);
}
END_TEST

START_TEST(test_inverse_matrix_1) {
  matrix_t A;
  matrix_t B;
  matrix_t res;
  s21_create_matrix(1, 1, &A);
  s21_create_matrix(1, 1, &B);
  A.matrix[0][0] = 50;
  B.matrix[0][0] = 1.0 / 50.0;
  ck_assert_int_eq(s21_inverse_matrix(&A, &res), s21_ok);
  ck_assert_int_eq(s21_eq_matrix(&B, &res), SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(test_s21_determinant_1) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 4;
  A.matrix[1][1] = 5;
  A.matrix[1][2] = 6;
  A.matrix[2][0] = 7;
  A.matrix[2][1] = 8;
  A.matrix[2][2] = 9;

  double det;
  ck_assert_int_eq(s21_determinant(&A, &det), s21_ok);
  ck_assert_double_eq(det, 0.0);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_s21_determinant_2) {
  matrix_t A = {0};
  s21_create_matrix(3, 3, &A);
  A.rows = -100;
  double det;
  ck_assert_int_eq(s21_determinant(&A, &det), s21_error);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_inverse_matrix_2) {
  matrix_t A;
  matrix_t B;
  matrix_t res;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 5;
  A.matrix[0][2] = 7;

  A.matrix[1][0] = 6;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 4;

  A.matrix[2][0] = 5;
  A.matrix[2][1] = -2;
  A.matrix[2][2] = -3;

  B.matrix[0][0] = 1;
  B.matrix[0][1] = -1;
  B.matrix[0][2] = 1;

  B.matrix[1][0] = -38;
  B.matrix[1][1] = 41;
  B.matrix[1][2] = -34;

  B.matrix[2][0] = 27;
  B.matrix[2][1] = -29;
  B.matrix[2][2] = 24;

  ck_assert_int_eq(s21_inverse_matrix(&A, &res), s21_ok);
  ck_assert_int_eq(s21_eq_matrix(&B, &res), SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&res);
}
END_TEST

Suite *s21_matrix_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("s21_matrix");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_eq_1);
  tcase_add_test(tc_core, test_eq_2);
  tcase_add_test(tc_core, test_eq_3);
  tcase_add_test(tc_core, test_sum_matrix_1);
  tcase_add_test(tc_core, test_sum_matrix_2);
  tcase_add_test(tc_core, test_sum_matrix_3);
  tcase_add_test(tc_core, test_sub_matrix_1);
  tcase_add_test(tc_core, test_sub_matrix_2);
  tcase_add_test(tc_core, test_sub_matrix_3);
  tcase_add_test(tc_core, test_mult_number_1);
  tcase_add_test(tc_core, test_mult_number_2);
  tcase_add_test(tc_core, test_mult_matrix_1);
  tcase_add_test(tc_core, test_mult_matrix_2);
  tcase_add_test(tc_core, test_mult_matrix_3);
  tcase_add_test(tc_core, test_mult_matrix_4);
  tcase_add_test(tc_core, test_transpose_matrix_1);
  tcase_add_test(tc_core, test_calc_complements_matrix_1);
  tcase_add_test(tc_core, test_calc_complements_matrix_2);
  tcase_add_test(tc_core, test_inverse_matrix_1);
  tcase_add_test(tc_core, test_s21_determinant_1);
  tcase_add_test(tc_core, test_s21_determinant_2);
  tcase_add_test(tc_core, test_inverse_matrix_2);
  suite_add_tcase(s, tc_core);
  return s;
}

int main(void) {
  int number_failed;
  Suite *s;
  SRunner *sr;
  s = s21_matrix_suite();
  sr = srunner_create(s);
  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return (number_failed == 0) ? 0 : 1;
}
