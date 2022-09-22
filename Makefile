all: a.out

a.out:
	g++ -std=c++17 -lm Row.cpp SudokuUtilities.cpp Sudoku1.cpp

test: a.out
	./a.out

clean:
	rm a.out
