// Sudoku1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "SudokuUtilities.h"
#include <iostream>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{	
	char sBlockString[BLOCK_SIZE+20] = {0};
	
    // Use the libraries provided. Asks the user to specify a puzzle.
    // Use the global gSudokuPuzzle structure in the library to communicate what was provided.
	while( ) //Continues normal flow if strings do not contain q or Q.
	{
        // Check if the gSudokuPuzzle is or is not a solution.
			if ( )
			{
				// Print the solution
				cout << endl << "Valid Solution!!" << endl;
			}
			else 
			{
				// Print what they provided
				cout << endl << "Invalid Solution." << endl;
			}
	}
    // See if you should quit the program (quit on 's' input).
	char cStallForExitMessage = 's';
	cin >> cStallForExitMessage;

	return 0;
	
}
