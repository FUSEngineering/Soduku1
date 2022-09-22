// SudokuUtilities.cpp : Support structures for a Console-App for specifying and solving Sudoku puzzles
//Steve Frezza
//Sudoku Puzzle Analysis

#include "stdafx.h"
#include "SudokuUtilities.h"
#include "Row.h"

using namespace std;

//Global used for puzzle inputs. Note the initialization to mostly blanks.
CellType gSudokuPuzzle[BLOCK_SIZE][BLOCK_SIZE] = {{One,   Two,   Three, Four,  One,   Blank, Blank, Blank, Blank}, // Block 0
													{Blank, Blank, Blank, Blank, Two,   Six,   Seven, Blank, Blank}, // Block 1
													{Blank, Blank, Blank, Blank, Three, Blank, Blank, Eight, Nine},  // Block 2
													{Nine,  Eight, Seven, Blank, Four,  Blank, Blank, Blank, Blank}, // Block 3
													{Blank, Blank, Blank, Blank, Five,  Blank, Blank, Blank, Blank},// Block 4
													{Blank, Blank, Blank, Blank, Six,   Blank, Blank, Blank, Blank},// Block 5
													{Blank, Blank, Blank, Blank, Seven, Blank, Blank, Blank, Blank},// Block 6
													{Blank, Blank, Blank, Blank, Eight, Blank, Blank, Blank, Blank}, // Block 7
													{Blank, Blank, Blank, Blank, Nine, Blank, Blank, Blank, Blank}};




//All of the functions used in tmain are defined hereafter.

char cPrintBlockValue(CellType eBlkValue)
{
	switch(eBlkValue)
	{
	case One:
		return '1';
		break;
	case Two:
		return '2';
		break;
	case Three:
		return '3';
		break;
	case Four:
		return '4';
		break;
	case Five:
		return '5';
		break;
	case Six:
		return '6';
		break;
	case Seven:
		return '7';
		break;
	case Eight:
		return '8';
		break;
	case Nine:
		return '9';
		break;
	default:
		return ' ';
		break;
	}
	return ' ';
}

void gPrintThreeBlocks(CellType gBlock1[BLOCK_SIZE], CellType gBlock2[BLOCK_SIZE], CellType gBlock3[BLOCK_SIZE])
{
	const char BLOCK_VERTICAL_WALL = '|';
	
	// Prints one row at a time until the whole puzzle is printed.
	for (int index=0; index < BLOCK_SIZE; index +=3)
	{
		cout << BLOCK_VERTICAL_WALL << ' ' << cPrintBlockValue(gBlock1[index+0])
									<< ' ' << cPrintBlockValue(gBlock1[index+1]) 
									<< ' ' << cPrintBlockValue(gBlock1[index+2]) 
									<< ' ';
		cout << BLOCK_VERTICAL_WALL << ' ' << cPrintBlockValue(gBlock2[index+0])
									<< ' ' << cPrintBlockValue(gBlock2[index+1]) 
									<< ' ' << cPrintBlockValue(gBlock2[index+2]) 
									<< ' ';
		cout << BLOCK_VERTICAL_WALL << ' ' << cPrintBlockValue(gBlock3[index+0])
									<< ' ' << cPrintBlockValue(gBlock3[index+1]) 
									<< ' ' << cPrintBlockValue(gBlock3[index+2]) 
									<< ' ';
		cout << BLOCK_VERTICAL_WALL << endl;
	}
	return;
}

void gPrintGrid(CellType gPuzzle[BLOCK_SIZE][BLOCK_SIZE]) 
{
	const char* ROW_HEADING = "+-------+-------+-------+";
	for (int iBlockNo = 0; iBlockNo < BLOCK_SIZE; iBlockNo +=3)
	{
		cout << ROW_HEADING << endl;
		// Print next three blocks
		gPrintThreeBlocks(gPuzzle[iBlockNo], gPuzzle[iBlockNo+1], gPuzzle[iBlockNo+2]);
	}
	cout << ROW_HEADING;
	return;
}

bool bSOLVEDBlock(CellType sBlockString[]) 
{
	bool bIsUsed[BLOCK_SIZE] = {false, false, false, false, false, false, false, false, false};
	for (int iCharNo=0; iCharNo<BLOCK_SIZE; iCharNo++)
	{
		switch (sBlockString[iCharNo])
		{
		case One: 
			if (bIsUsed[One]) return false;
			bIsUsed[One] = true;
			break;
		case Two: 
			if (bIsUsed[Two]) return false;
			bIsUsed[Two] = true;
			break;
		case Three: 
			if (bIsUsed[Three]) return false;
			bIsUsed[Three] = true;
			break;
		case Four: 
			if (bIsUsed[Four]) return false;
			bIsUsed[Four] = true;
			break;
		case Five: 
			if (bIsUsed[Five]) return false;
			bIsUsed[Five] = true;
			break;
		case '6': 
			if (bIsUsed[Six]) return false;
			bIsUsed[Six] = true;
			break;
		case '7': 
			if (bIsUsed[Seven]) return false;
			bIsUsed[Seven] = true;
			break;
		case '8': 
			if (bIsUsed[Eight]) return false;
			bIsUsed[Eight] = true;
			break;
		case '9': 
			if (bIsUsed[Nine]) return false;
			bIsUsed[Nine] = true;
			break;
		default:
			return false;
			break;
		}
	}
	return true;
}

bool bValidBlock(char sBlockString[]) 
{
	bool bIsUsed[BLOCK_SIZE] = {false, false, false, false, false, false, false, false, false};
	for (int iCharNo=0; iCharNo<BLOCK_SIZE; iCharNo++)
	{
		switch (sBlockString[iCharNo])
		{
		case '_':  break;
		case '1': 
			if (bIsUsed[One]) return false;
			bIsUsed[One] = true;
			break;
		case '2': 
			if (bIsUsed[Two]) return false;
			bIsUsed[Two] = true;
			break;
		case '3': 
			if (bIsUsed[Three]) return false;
			bIsUsed[Three] = true;
			break;
		case '4': 
			if (bIsUsed[Four]) return false;
			bIsUsed[Four] = true;
			break;
		case '5': 
			if (bIsUsed[Five]) return false;
			bIsUsed[Five] = true;
			break;
		case '6': 
			if (bIsUsed[Six]) return false;
			bIsUsed[Six] = true;
			break;
		case '7': 
			if (bIsUsed[Seven]) return false;
			bIsUsed[Seven] = true;
			break;
		case '8': 
			if (bIsUsed[Eight]) return false;
			bIsUsed[Eight] = true;
			break;
		case '9': 
			if (bIsUsed[Nine]) return false;
			bIsUsed[Nine] = true;
			break;
		default:
			return false;
			break;
		}
	}
	return true;
}



bool bGetBlockString(char sBlockString[])  //STUB
{
	// Fill the char array with something from the user. Return true iff the string contains a Q or q.
	cout << "Please type in 9 characters" << endl;
	cin >> sBlockString;
	for(int i = 0; sBlockString[i] != '\0'; i++)
	{
		if ((sBlockString[i] == 'q') || (sBlockString[i] == 'Q')) return true;

	}
	return false;
}
bool bInputGrid(Row *gGrid[BLOCK_SIZE])  
{

	char sBlockString[BLOCK_SIZE][BLOCK_SIZE+20];
	for(int iBlockNo = 0; iBlockNo < BLOCK_SIZE; )
	{
		// Read in the block information sequentially; verify it; 
		// continue or exit as necessary
		cout << "For Block #" << iBlockNo << " ";
		if (bGetBlockString(sBlockString[iBlockNo]))
		{	
			cout << "You chose to quit.  Enter a character to exit. " << endl;
			return false;	
		}
		else if(bValidBlock(sBlockString[iBlockNo]))
		{
			gGrid[iBlockNo] = new Row(sBlockString[iBlockNo]);
			
			//convertToCellType(sBlockString[iBlockNo],gSudokuPuzzle[iBlockNo]);
			iBlockNo++;
		}
		else // if(bValidBlock(sBlockString[iBlockNo])==false)
		{
			cout << "\tInvalid block!\n\n";
		}
	}
	return true;
}

bool bSolvedBlock(int iBlockNo, CellType gBlock[BLOCK_SIZE][BLOCK_SIZE]) 
{
	bool bIsUsed[BLOCK_SIZE] = {false, false, false, false, false, false, false, false, false};
	for (int iIndexNo=0; iIndexNo<BLOCK_SIZE; iIndexNo++)
	{
		switch (gBlock[iBlockNo][iIndexNo])
		{
		case One: 
			if (bIsUsed[One]) return false;
			bIsUsed[One] = true;
			break;
		case Two: 
			if (bIsUsed[Two]) return false;
			bIsUsed[Two] = true;
			break;
		case Three: 
			if (bIsUsed[Three]) return false;
			bIsUsed[Three] = true;
			break;
		case Four: //four
			if (bIsUsed[Four]) return false;
			bIsUsed[Four] = true;
			break;
		case Five: 
			if (bIsUsed[Five]) return false;
			bIsUsed[Five] = true;
			break;
		case Six: 
			if (bIsUsed[Six]) return false;
			bIsUsed[Six] = true;
			break;
		case Seven: 
			if (bIsUsed[Seven]) return false;
			bIsUsed[Seven] = true;
			break;
		case Eight: 
			if (bIsUsed[Eight]) return false;
			bIsUsed[Eight] = true;
			break;
		case Nine: 
			if (bIsUsed[Nine]) return false;
			bIsUsed[Nine] = true;
			break;
		default:
			return false;
			break;
		}
	}
	return true;
}
bool bSolvedRow(int iRowID, CellType gRowOrientedPuzzle[BLOCK_SIZE][BLOCK_SIZE])
{
	bool bIsUsed[BLOCK_SIZE] = {false, false, false, false, false, false, false, false, false};

	for (int iColNo=0; iColNo<BLOCK_SIZE; iColNo++)
	{
		switch (gRowOrientedPuzzle[iRowID][iColNo])
		{
		case One: 
			if (bIsUsed[One]) return false;
			bIsUsed[One] = true;
			break;
		case Two: 
			if (bIsUsed[Two]) return false;
			bIsUsed[Two] = true;
			break;
		case Three: 
			if (bIsUsed[Three]) return false;
			bIsUsed[Three] = true;
			break;
		case Four: 
			if (bIsUsed[Four]) return false;
			bIsUsed[Four] = true;
			break;
		case Five: 
			if (bIsUsed[Five]) return false;
			bIsUsed[Five] = true;
			break;
		case Six: 
			if (bIsUsed[Six]) return false;
			bIsUsed[Six] = true;
			break;
		case Seven: 
			if (bIsUsed[Seven]) return false;
			bIsUsed[Seven] = true;
			break;
		case Eight: 
			if (bIsUsed[Eight]) return false;
			bIsUsed[Eight] = true;
			break;
		case Nine: 
			if (bIsUsed[Nine]) return false;
			bIsUsed[Nine] = true;
			break;
		default:
			return false;
			break;
		}
	}
	return true;
}
bool bSolvedCol(int iColNo, CellType gRowOrientedPuzzle[BLOCK_SIZE][BLOCK_SIZE])
{
	bool bIsUsed[BLOCK_SIZE] = {false, false, false, false, false, false, false, false, false};

	for (int iRowID=0; iRowID<BLOCK_SIZE; iRowID++)
	{
		switch (gRowOrientedPuzzle[iRowID][iColNo])
		{
		case One: 
			if (bIsUsed[One]) return false;
			bIsUsed[One] = true;
			break;
		case Two: 
			if (bIsUsed[Two]) return false;
			bIsUsed[Two] = true;
			break;
		case Three: 
			if (bIsUsed[Three]) return false;
			bIsUsed[Three] = true;
			break;
		case Four: 
			if (bIsUsed[Four]) return false;
			bIsUsed[Four] = true;
			break;
		case Five: 
			if (bIsUsed[Five]) return false;
			bIsUsed[Five] = true;
			break;
		case Six: 
			if (bIsUsed[Six]) return false;
			bIsUsed[Six] = true;
			break;
		case Seven: 
			if (bIsUsed[Seven]) return false;
			bIsUsed[Seven] = true;
			break;
		case Eight: 
			if (bIsUsed[Eight]) return false;
			bIsUsed[Eight] = true;
			break;
		case Nine: 
			if (bIsUsed[Nine]) return false;
			bIsUsed[Nine] = true;
			break;
		default:
			return false;
			break;
		}
	}
	return true;
}
bool bAllRowsSolved(CellType gRowOrientedPuzzle[BLOCK_SIZE][BLOCK_SIZE] )
{
	for (int iRowNo=0; iRowNo<BLOCK_SIZE; iRowNo++)
	{
		if (!bSolvedRow(iRowNo, gRowOrientedPuzzle)) return false;
	}
	return true;
}
bool bAllColumnsSolved(CellType gRowOrientedPuzzle[BLOCK_SIZE][BLOCK_SIZE] ) 
{
	for (int iColNo=0; iColNo<BLOCK_SIZE; iColNo++)
	{
		if (!bSolvedCol(iColNo, gRowOrientedPuzzle)) return false;
	}
	return true;
}
bool bAllBlocksSolved(CellType gBlockOrientedPuzzle[BLOCK_SIZE][BLOCK_SIZE] ) // STUB
{
	for (int iBlockNo=0; iBlockNo<BLOCK_SIZE; iBlockNo++)
	{
		if (!bSolvedBlock(iBlockNo, gBlockOrientedPuzzle)) return false;
	}
	return true;
}
void gConvertToRowCol(CellType gSudokuPuzzle[BLOCK_SIZE][BLOCK_SIZE], CellType gRowOrientedPuzzle[BLOCK_SIZE][BLOCK_SIZE])
{
	for (int iBlockNo = 0; iBlockNo < BLOCK_SIZE; iBlockNo +=3)
	{
		int baseRow = iBlockNo;
		for (int iCellID = 0; iCellID < BLOCK_SIZE; iCellID += 3)
		{
			int col = iCellID;
			gRowOrientedPuzzle[baseRow][col] = gSudokuPuzzle[iBlockNo][iCellID];
			gRowOrientedPuzzle[baseRow][col+1] = gSudokuPuzzle[iBlockNo][iCellID+1];
			gRowOrientedPuzzle[baseRow][col+2] = gSudokuPuzzle[iBlockNo][iCellID+2];

			gRowOrientedPuzzle[baseRow+1][col] = gSudokuPuzzle[iBlockNo+1][iCellID];
			gRowOrientedPuzzle[baseRow+1][col+1] = gSudokuPuzzle[iBlockNo+1][iCellID+1];
			gRowOrientedPuzzle[baseRow+1][col+2] = gSudokuPuzzle[iBlockNo+1][iCellID+2];

			gRowOrientedPuzzle[baseRow+2][col] = gSudokuPuzzle[iBlockNo+2][iCellID];
			gRowOrientedPuzzle[baseRow+2][col+1] = gSudokuPuzzle[iBlockNo+2][iCellID+1];
			gRowOrientedPuzzle[baseRow+2][col+2] = gSudokuPuzzle[iBlockNo+2][iCellID+2];		}
	}
	return;
}
void gConvertToColRow(CellType gSudokuPuzzle[BLOCK_SIZE][BLOCK_SIZE], CellType gColOrientedPuzzle[BLOCK_SIZE][BLOCK_SIZE])
{
	int const iDIM = (int)sqrt((double)BLOCK_SIZE);
	for (int iCol = 0; iCol < BLOCK_SIZE; iCol++)
	{
		int iStartBlock = (iCol / iDIM);
		int iRow = 0;
		for (int iBlockNo = iStartBlock; iBlockNo < BLOCK_SIZE; iBlockNo += iDIM)
		{
			int iStartIndex = (iCol % iDIM);
			for(int iIndex = iStartIndex; iIndex < BLOCK_SIZE; iIndex += iDIM)
			{
				gColOrientedPuzzle[iCol][iRow++] = gSudokuPuzzle[iBlockNo][iIndex];
			}
		}
	}
	return;
}

bool bAllRowsSolved1(CellType gBlockOrientedPuzzle[BLOCK_SIZE][BLOCK_SIZE] )
{
	const int iDIM = (int)sqrt((double)BLOCK_SIZE);
	for (int iRowNo=0; iRowNo<BLOCK_SIZE; iRowNo++)	// Itterate over all rows
	{
		bool bIsUsed[BLOCK_SIZE] = {false, false, false, false, false, false, false, false, false}; // Reset the check duplication

		int iInitBlock = (iRowNo / iDIM) * iDIM;
		for(int iBlockNo = iInitBlock; iBlockNo < iInitBlock + 3; iBlockNo++)	
		{
			int iInitIndex = (iRowNo % iDIM) * iDIM;
			for (int iIndex = iInitIndex; iIndex < iInitIndex+3; iIndex++)
			{
				switch (gBlockOrientedPuzzle[iBlockNo][iIndex])
				{
				case One: 
					if (bIsUsed[One]) return false;
					bIsUsed[One] = true;
					break;
				case Two: 
					if (bIsUsed[Two]) return false;
					bIsUsed[Two] = true;
					break;
				case Three: 
					if (bIsUsed[Three]) return false;
					bIsUsed[Three] = true;
					break;
				case Four: 
					if (bIsUsed[Four]) return false;
					bIsUsed[Four] = true;
					break;
				case Five: 
					if (bIsUsed[Five]) return false;
					bIsUsed[Five] = true;
					break;
				case Six: 
					if (bIsUsed[Six]) return false;
					bIsUsed[Six] = true;
					break;
				case Seven: 
					if (bIsUsed[Seven]) return false;
					bIsUsed[Seven] = true;
					break;
				case Eight: 
					if (bIsUsed[Eight]) return false;
					bIsUsed[Eight] = true;
					break;
				case Nine: 
					if (bIsUsed[Nine]) return false;
					bIsUsed[Nine] = true;
					break;
				default:
					return false; // This element is duplicated (or blank) in this row.
					break;
				}
			}		
		}
	}
	return true; // All Rows Succeeded
}
bool bAllColumnsSolved1(CellType gBlockOrientedPuzzle[BLOCK_SIZE][BLOCK_SIZE] )
{
	const int iDIM = (int)sqrt((double)BLOCK_SIZE);
	for (int iColNo=0; iColNo<BLOCK_SIZE; iColNo++)	// Itterate over all columns
	{
		bool bIsUsed[BLOCK_SIZE] = {false, false, false, false, false, false, false, false, false}; // Reset the check duplication

		int iInitBlock = (iColNo / iDIM) * iDIM;
		for(int iBlockNo = iInitBlock; iBlockNo < BLOCK_SIZE; iBlockNo+=3)	
		{
			int iInitIndex = (iColNo % iDIM) * iDIM;
			for (int iIndex = iInitIndex; iIndex < BLOCK_SIZE; iIndex+=3)
			{
				switch (gBlockOrientedPuzzle[iBlockNo][iIndex])
				{
				case One: 
					if (bIsUsed[One]) return false;
					bIsUsed[One] = true;
					break;
				case Two: 
					if (bIsUsed[Two]) return false;
					bIsUsed[Two] = true;
					break;
				case Three: 
					if (bIsUsed[Three]) return false;
					bIsUsed[Three] = true;
					break;
				case Four: 
					if (bIsUsed[Four]) return false;
					bIsUsed[Four] = true;
					break;
				case Five: 
					if (bIsUsed[Five]) return false;
					bIsUsed[Five] = true;
					break;
				case Six: 
					if (bIsUsed[Six]) return false;
					bIsUsed[Six] = true;
					break;
				case Seven: 
					if (bIsUsed[Seven]) return false;
					bIsUsed[Seven] = true;
					break;
				case Eight: 
					if (bIsUsed[Eight]) return false;
					bIsUsed[Eight] = true;
					break;
				case Nine: 
					if (bIsUsed[Nine]) return false;
					bIsUsed[Nine] = true;
					break;
				default:
					return false; // This element is duplicated (or blank) in this row.
					break;
				}
			}		
		}
	}
	return true; // All Rows Succeeded
}
bool bSolvedBlock(CellType gBlock[BLOCK_SIZE]) 
{
	bool bIsUsed[BLOCK_SIZE] = {false, false, false, false, false, false, false, false, false};
	for (int iIndexNo=0; iIndexNo<BLOCK_SIZE; iIndexNo++)
	{
		switch (gBlock[iIndexNo])
		{
		case One: 
			if (bIsUsed[One]) return false;
			bIsUsed[One] = true;
			break;
		case Two: 
			if (bIsUsed[Two]) return false;
			bIsUsed[Two] = true;
			break;
		case Three: 
			if (bIsUsed[Three]) return false;
			bIsUsed[Three] = true;
			break;
		case Four: //four
			if (bIsUsed[Four]) return false;
			bIsUsed[Four] = true;
			break;
		case Five: 
			if (bIsUsed[Five]) return false;
			bIsUsed[Five] = true;
			break;
		case Six: 
			if (bIsUsed[Six]) return false;
			bIsUsed[Six] = true;
			break;
		case Seven: 
			if (bIsUsed[Seven]) return false;
			bIsUsed[Seven] = true;
			break;
		case Eight: 
			if (bIsUsed[Eight]) return false;
			bIsUsed[Eight] = true;
			break;
		case Nine: 
			if (bIsUsed[Nine]) return false;
			bIsUsed[Nine] = true;
			break;
		default:
			return false;
			break;
		}
	}
	return true;
}
bool bAllBlocksSolved1(CellType gBlockOrientedPuzzle[BLOCK_SIZE][BLOCK_SIZE] )
{
	const int iDIM = (int)sqrt((double)BLOCK_SIZE);
	for (int iBlockNo=0; iBlockNo<BLOCK_SIZE; iBlockNo++)	// Itterate over all blocks
	{
		if(! bSolvedBlock(gBlockOrientedPuzzle[iBlockNo])) 
		{
			return false; // This block failed.
		}
	}
	return true; // All Blocks Succeeded
}
bool bIsSolution1(CellType gSudokuPuzzle[BLOCK_SIZE][BLOCK_SIZE]) 
{
	if (bAllRowsSolved1(gSudokuPuzzle) && 
		bAllColumnsSolved1(gSudokuPuzzle) && 
		bAllBlocksSolved1(gSudokuPuzzle)) // Test(s) of the current gSudokuPuzzle[][] goes here.
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool bIsSolution2(CellType gSudokuPuzzle[BLOCK_SIZE][BLOCK_SIZE]) 
{
	CellType gRowOrientedPuzzle[BLOCK_SIZE][BLOCK_SIZE];
	gConvertToRowCol(gSudokuPuzzle, gRowOrientedPuzzle);
	CellType gColOrientedPuzzle[BLOCK_SIZE][BLOCK_SIZE];
	gConvertToColRow(gSudokuPuzzle, gColOrientedPuzzle);
	for(int i=0; i<BLOCK_SIZE; i++)
	{
		if (! (bSolvedBlock(gSudokuPuzzle[i]) &&		// Check Block[i]
			   bSolvedBlock(gRowOrientedPuzzle[i])  &&	// Check Row[i]
			   bSolvedBlock(gColOrientedPuzzle[i])) )		// Check Column[i]
		{
			return false;		// One block, col or row failed.
		}
	}
	return true;
}


bool bIsSolution(CellType gSudokuPuzzle[BLOCK_SIZE][BLOCK_SIZE]) //STUB
{
	CellType gRowOrientedPuzzle[BLOCK_SIZE][BLOCK_SIZE];
	gConvertToRowCol(gSudokuPuzzle, gRowOrientedPuzzle);
	CellType gColOrientedPuzzle[BLOCK_SIZE][BLOCK_SIZE];
	gConvertToColRow(gSudokuPuzzle, gColOrientedPuzzle);

	if (bAllRowsSolved(gRowOrientedPuzzle) && 
		bAllColumnsSolved(gRowOrientedPuzzle) && 
		bAllBlocksSolved(gSudokuPuzzle)) // Test(s) of the current gSudokuPuzzle[][] goes here.
	{
		bool try2 = bIsSolution1(gSudokuPuzzle);
		bool try3 = bIsSolution2(gSudokuPuzzle);
		return true;
	}
	else
	{
		return false;
	}
}

