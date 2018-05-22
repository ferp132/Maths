//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2018 Media Design School
//
// File Name	: 
// Description	: 
// Author		: Your Name
// Mail			: your.name@mediadesign.school.nz
//

#pragma once

#if !defined(__MATRICESFUNCTIONS_H__)
#define __MATRICESFUNCTIONS_H__

// Library Includes
#include "utils.h"

void SetIdentity(HWND hDlg, int Index)
{
	int Begin = Index;
	int End = Index + 16;

	while (Index != End)
	{
		if (Index == Begin || Index == Begin + 5 || Index == Begin + 10 || Index == Begin + 15)		WriteToEditBox(hDlg, Index, 1);
		else																						WriteToEditBox(hDlg, Index, 0);
		Index++;
	}

	return;
}

void Determinant(HWND hDlg, int Index)
{
	int SignI[4][4];
	int sign = 1;
	float I[4][4];		// Array representing our matrix
	float Det4;			// The determinant for the matrix
	float Det3[4];		// Determinants of 3x3 matrices derived from the 4x4 matrix
	float Det2[12];		// Determinants of 2x2 matrices derived from the 3x3 matrices

	for (int LeftIndex = 0; LeftIndex < 4; LeftIndex++)
	{
		for (int RightIndex = 0; RightIndex < 4; RightIndex++)
		{
			SignI[LeftIndex][RightIndex] = sign;
			if (sign > 0) sign = -1;
			else if (sign < 0) sign = 1;
		}
	}

	for (int LeftIndex = 0; LeftIndex < 4; LeftIndex++)
	{
		for (int RightIndex = 0; RightIndex < 4; RightIndex++)
		{
			I[LeftIndex][RightIndex] = ReadFromEditBox(hDlg, Index);
			Index++;

		}
	}

	//Sub Determinants for Det3[0]
	Det2[0] = I[1][1] * (I[2][2] * I[3][3] - I[3][2] * I[2][3]);
	Det2[1] = I[2][1] * (I[1][2] * I[3][3] - I[1][3] * I[3][2]);
	Det2[2] = I[3][1] * (I[1][2] * I[2][3] - I[2][2] * I[1][3]);

	//Sub Determinants for Det3[1]
	Det2[3] = I[0][1] * (I[2][2] * I[3][3] - I[3][2] * I[2][3]);
	Det2[4] = I[2][1] * (I[0][2] * I[3][3] - I[3][2] * I[0][3]);
	Det2[5] = I[3][1] * (I[0][2] * I[2][3] - I[2][2] * I[0][3]);

	//Sub Determinants for Det3[2]
	Det2[6] = I[0][1] * (I[1][2] * I[3][3] - I[3][2] * I[1][3]);
	Det2[7] = I[1][1] * (I[0][2] * I[3][3] - I[3][2] * I[0][3]);
	Det2[8] = I[3][1] * (I[0][2] * I[1][3] - I[1][2] * I[0][3]);

	//Sub Determinants for Det3[3]
	Det2[9] = I[0][1] * (I[1][2] * I[2][3] - I[2][2] * I[1][3]);
	Det2[10] = I[1][1] * (I[0][2] * I[2][3] - I[2][2] * I[0][3]);
	Det2[11] = I[2][1] * (I[0][2] * I[1][3] - I[1][2] * I[0][3]);

	//Sub Determinants for Det4
	Det3[0] = I[0][0] *	(Det2[0] - Det2[1] + Det2[2]);
	Det3[1] = I[1][0] * (Det2[3] - Det2[4] + Det2[5]);
	Det3[2] = I[2][0] * (Det2[6] - Det2[7] + Det2[8]);
	Det3[3] = I[3][0] * (Det2[9] - Det2[10] + Det2[11]);

	//Final Determinant
	Det4 = Det3[0] - Det3[1] + Det3[2] - Det3[3];

	WriteToEditBox(hDlg, MATRIX_A_DETERMINANT_INPUT, Det4);
	return;
}

void Scale(HWND hDlg, int Index, float Scalar)
{
	for (int i = 0; i < 16; i++)				//1063 = UINT for Resultant matrix 11 position
	{
		WriteToEditBox(hDlg, 1063 + i, Scalar * ReadFromEditBox(hDlg, 1031 + i));
	}

	return;
}


#endif    // __MATRICESFUNCTIONS_H__