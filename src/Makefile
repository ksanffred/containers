CXX = g++
CXXFLAGS = -std=c++20 -Wall -Werror -Wextra
GCOV_FLAGS = --coverage -fprofile-arcs -ftest-coverage
LCOV_FLAGS = --no-external --ignore-errors mismatch 
TESTS_PATH = unit_tests

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S), Linux)
	CHECK_LIB = -lgtest -lgmock -pthread
endif
ifeq ($(UNAME_S), Darwin)
	CHECK_LIB = -lgtest -lgmock -pthread
endif

.PHONY: all clean format check_format cppcheck test gcov_report valgrind

all: test

clean:
	rm -f *.gcda *.gcno *.gcov *.o *.a *.out *.info *.report .clang-format
	rm -rf report

format:
	cp ../materials/linters/.clang-format .
	clang-format --version
	find . -name "*.cpp" -o -name "*.cc" -o -name "*.h" -o -name "*.tpp" | xargs clang-format -style=file -i

check_format:
	cp ../materials/linters/.clang-format .
	clang-format --version
	find . -name "*.cpp" -o -name "*.cc" -o -name "*.h" -o -name "*.tpp" | xargs clang-format -style=file -n

test: clean
	$(CXX) $(TESTS_PATH)/*.cc -o test.out $(CXXFLAGS) $(CHECK_LIB)
	./test.out

gcov_report: clean
	$(CXX) -o test.out $(GCOV_FLAGS) $(CXXFLAGS) $(TESTS_PATH)/*.cc $(CHECK_LIB)
	./test.out
	lcov -t "unit_test" -o unit_test.info -c -d . $(LCOV_FLAGS)
	genhtml -o report unit_test.info
	open ./report/index.html


valgrind: test
	valgrind --tool=memcheck --leak-check=full --show-leak-kinds=all --track-origins=yes ./test.out

