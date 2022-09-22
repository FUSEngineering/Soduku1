// SudokuUtilities.h
// Steve Frezza

#include <iostream>

#ifndef SUDOKU_UTILITIES
#define SUDOKU_UTILITIES 

    // Type Definitions
	enum CellType
	{
		One, Two, Three, Four, Five, Six, Seven, Eight, Nine, Blank
	};

	// Globals
	const int BLOCK_SIZE = 9;
	extern CellType gSudokuPuzzle[BLOCK_SIZE][BLOCK_SIZE];

	// Function Declarations
	bool bIsSolution(CellType gPuzzle[BLOCK_SIZE][BLOCK_SIZE]); //STUB
	void gPrintGrid(CellType gPuzzle[BLOCK_SIZE][BLOCK_SIZE]);
	bool bValidBlock(char sBlockSpecification[]);
	bool bInputGrid();
	bool IsSolution(CellType [BLOCK_SIZE][BLOCK_SIZE]);

#endif
