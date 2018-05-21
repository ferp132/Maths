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

float Determinant(HWND hDlg, int Index)
{
	float I[4][4];		// Array representing our matrix
	float Det4;			// The determinant for the matrix
	float Det3[4];		// Determinants of 3x3 matrices derived from the 4x4 matrix
	float Det2[12];		// Determinants of 2x2 matrices derived from the 3x3 matrices

	for (int LeftIndex = 0; LeftIndex < 4; LeftIndex++)
	{
		for (int RightIndex = 0; RightIndex < 4; RightIndex++)
		{
			I[LeftIndex][RightIndex] = Index + LeftIndex + RightIndex;
		}
	}

	Det2[1] = I[1][1] * (I[2][2] * I[3][3] - I[2][3] * I[3][2]);


}


#endif    // __MATRICESFUNCTIONS_H__