#pragma once
#include "SudokuUtilities.h"

class Row
{
private:

	CellType _row[BLOCK_SIZE];

public:
	Row(void);
	~Row(void);
	Row(char sBlockString[]);  // Build a row from a string
	bool bIsValid();
	bool bIsSolved();

private:
	bool convertToCellType(char sBlockString[],CellType gTestBlock[]);
};

