CC = g++
FLAGS = -std=c++20 -Wall -Werror -Wextra
GCOV_FLAGS = --coverage -fprofile-arcs -ftest-coverage
LCOV_FLAGS = --no-external --ignore-errors mismatch 
TESTS_PATH = unit_tests

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S), Linux)
	CHECK_LIB = -lsubunit -lgtest -lgmock -pthread
endif
ifeq ($(UNAME_S), Darwin)
	CHECK_LIB = -lgtest -lgmock -pthread
endif

all: clean check_format cppcheck test valgrind fsanitaze

clean:
	rm -f *.gcda *.gcno *.gcov *.o *.a *.out *.info *.report .clang-format
	rm -rf report

format:
	cp ../materials/linters/.clang-format .
	clang-format --version
	find . -name "*.cpp" -o -name "*.cc" -o -name "*.h" -o -name "*.tpp" | xargs clang-format -style=file -i
	rm -f .clang-format

check_format:
	cp ../materials/linters/.clang-format .
	clang-format --version
	find . -name "*.cpp" -o -name "*.cc" -o -name "*.h" -o -name "*.tpp" | xargs clang-format -style=file -n
	rm -f .clang-format

cppcheck:
	find . -name "*.cpp" -o -name "*.cc" -o -name "*.h" -o -name "*.tpp" | xargs \
	cppcheck --language=c++ --enable=all --suppress=missingIncludeSystem

test: clean
	$(CC) -o test.out $(GCOV_FLAGS) $(FLAGS) $(TESTS_PATH)/*.cc $(CHECK_LIB)
	./test.out

gcov_report: test 
	lcov -t "unit_test" -o unit_test.info -c -d . $(LCOV_FLAGS)
	genhtml -o report unit_test.info
	open ./report/index.html

valgrind: test
	valgrind --tool=memcheck --leak-check=full --show-leak-kinds=all --track-origins=yes ./test.out

leaks: test
	leaks -atExit -- ./test.out

fsanitaze: clean
	$(CC) -o test.out $(CFLAGS) $(TESTS_PATH)/*.cc -fsanitize=address -fsanitize=undefined $(CHECK_LIB)
	./test.out

+.PHONY: all clean format check_format cppcheck test gcov_report

