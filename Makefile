CC = gcc
CC_FLAGS = -Wall -Werror -Wextra -std=c11

all: clean test

s21_matrix.a:
	$(CC) $(CC_FLAGS) -c s21_*.c
	ar -rc s21_matrix.a *.o
	ranlib s21_matrix.a
	rm -rf *.o
clean:
	rm -rf *.out *.o *.a *.gcno *.gcda *.info report
test: s21_matrix.a
	$(CC) $(CC_FLAGS) test.c s21_matrix.a -lcheck -lsubunit -lm
	./a.out
test_valgrind:
	gcc s21_*.c test.c -lcheck -lsubunit -lm -Werror -Wextra -Wall -std=c11
	valgrind --tool=memcheck --leak-check=yes ./a.out
test_clang:
	clang-format -n *.c *.h
gcov_report:
	gcc  --coverage  test.c s21_*.c -lcheck -lsubunit -lm -Werror -Wextra -Wall -std=c11
	./a.out
	lcov   --capture  --directory . -o coverage.info
	genhtml --output-directory   report --legend coverage.info --ignore-errors unmapped,unmapped
	rm -rf *.gcno *.gcda *.info