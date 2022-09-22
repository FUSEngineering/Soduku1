//#include "StdAfx.h"
#include "Row.h"


Row::Row(void)
{
}


Row::~Row(void)
{
}

Row::Row(char sBlockString[])
{
	convertToCellType(sBlockString, _row);
}

bool Row::convertToCellType(char sBlockString[],CellType gTestBlock[])//Puts numbers into cells of Block.
																 //Determines if all chars are 1,..,9 or '_'.
{
	for (int iCharNo = 0; iCharNo< BLOCK_SIZE; iCharNo++)
	{
		switch (sBlockString[iCharNo])
		{
		case '_':  
			gTestBlock[iCharNo] = Blank;
			break;
		case '1': 
			gTestBlock[iCharNo] = One;
			break;
		case '2': 
			gTestBlock[iCharNo] = Two;
			break;
		case '3': 
			gTestBlock[iCharNo] = Three;
			break;
		case '4': 
			gTestBlock[iCharNo] = Four;
			break;
		case '5': 
			gTestBlock[iCharNo] = Five;
			break;
		case '6': 
			gTestBlock[iCharNo] = Six;
			break;
		case '7': 
			gTestBlock[iCharNo] = Seven;
			break;
		case '8': 
			gTestBlock[iCharNo] = Eight;
			break;
		case '9': 
			gTestBlock[iCharNo] = Nine;
			break;
		default:
			return false;
			break;
		}
	}
	return true;
}
