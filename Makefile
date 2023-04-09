.PHONY: all tests clean open check

CFLAGS = -Wall -Werror -Wextra
TFLAGS = -lgtest -lstdc++ -std=c++17
CC = gcc
GCOV = --coverage
UNIT = unit_tests

all: clean test gcov_report

test:
	@$(CC) $(CFLAGS) $(TFLAGS) Model/s21_model.cc \
							   Model/Transformation/ObjectTransformation.cc \
							   Model/Parser/ObjectParser.cc Tests/unit_tests.cc -o $(UNIT)
	@./$(UNIT)
	@rm unit_tests
	@echo "=== TESTS DONE ==="

gcov_report:
	@$(CC) $(CFLAGS) $(TFLAGS) $(GCOV) Model/s21_model.cc \
                                       Model/Transformation/ObjectTransformation.cc \
                                       Model/Parser/ObjectParser.cc Tests/unit_tests.cc -o $(UNIT) -lgtest
	@./$(UNIT)
	@rm unit_tests
	@lcov -t "test" -o test.info -c -d .
	@genhtml -o report test.info

install:
	@make clean
	@mkdir build
	@cd View && qmake && make && make clean && rm Makefile && cd ../ && mv View/3D_front.app build

uninstall:
	@rm -rf build*

open:
	@cd build && open 3D_front.app

dist: install
	@rm -rf 3D_Viewer_arch/
	@mkdir 3D_Viewer_arch/
	@mv ./build/3D_front.app 3D_Viewer_arch/
	@tar cvzf 3D_Viewer_arch.tgz 3D_Viewer_arch/
	@rm -rf 3D_Viewer_arch/

dvi:
	@open dvi.html

check:
	@cp ../materials/linters/.clang-format .
	clang-format -n Model/*/*
	clang-format -n View/*.cc View/*.h
	clang-format -n Controller/*
	@rm -rf .clang-format

coverage:
	@open report/index.html

clean:
	@rm -rf *.o *.a *.so *.gcda *.gcno *.gch test.info *.css test report *.cfg *.dSYM unit_tests.o build
