#pragma once

#if !defined(__GAUSSFUNCTIONS_H__)
#define __GAUSSFUNCTIONS_H__

//-----Library Includes
#include "utils.h"

enum GAUSSINDEXES
{
	MROW	= 1313,
	MSCALAR = 1314,

	SROWA	= 1315,
	SROWB	= 1316,

	ASCALAR = 1317,
	AROWA	= 1318,
	AROWB	= 1319,

	R1		= 1301,
	R2		= 1305,
	R3		= 1309
};

void GaussMultiply		(HWND hDlg, int RowIndex);					//-----Multiply one row with a Scalar
void GaussSwap			(HWND hDlg, int RowIndex1, int RowIndex2);	//-----swap the values of two rows.
void GaussAdd			(HWND hDlg, int RowIndex1, int RowIndex2);	//-----Multiply a Row By a number and add it to another row
void GaussEchelonCheck	(HWND hDlg);

#endif    // __GAUSSFUNCTIONS_H__