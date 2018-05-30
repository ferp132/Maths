#pragma once

#if !defined(__MATRICESFUNCTIONS_H__)
#define __MATRICESFUNCTIONS_H__

// Library Includes
#include "utils.h"

void MatrixTranspose(HWND hDlg, int FirstIndex, int SecondIndex)
{
	float Matrix[4][4];
	int ResultMatrixIndex = 1063;
	float Result = 0;

	for (int LeftIndex = 0; LeftIndex < 4; LeftIndex++)
	{
		for (int RightIndex = 0; RightIndex < 4; RightIndex++)
		{
			Matrix[LeftIndex][RightIndex] = ReadFromEditBox(hDlg, FirstIndex);
			FirstIndex++;
		}
	}

	for (int i = 0; i < 4; i++)
	{
		for (int LeftIndex = 0; LeftIndex < 4; LeftIndex++)
		{
			for (int RightIndex = 0; RightIndex < 4; RightIndex++)
			{
				Result += Matrix[RightIndex][LeftIndex];
				WriteToEditBox(hDlg, ResultMatrixIndex, Result);
				ResultMatrixIndex++;
				Result = 0;
			}

		}
	}
}

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

	
	return Det4;
}

void Scale(HWND hDlg, int Index, float Scalar)
{
	for (int i = 0; i < 16; i++)				//1063 = UINT for Resultant matrix 11 position
	{
		WriteToEditBox(hDlg, 1063 + i, Scalar * ReadFromEditBox(hDlg, 1031 + i));
	}

	return;
}

void MatrixMultiply(HWND hDlg, int FirstIndex, int SecondIndex)
{
	float FirstMatrix[4][4];
	float SecondMatrix[4][4];
	int ResultMatrixIndex = 1063;
	float Result = 0;

	for (int LeftIndex = 0; LeftIndex < 4; LeftIndex++)
	{
		for (int RightIndex = 0; RightIndex < 4; RightIndex++)
		{
			FirstMatrix[LeftIndex][RightIndex] = ReadFromEditBox(hDlg, FirstIndex);
			FirstIndex++;
		}
	}
	for (int LeftIndex = 0; LeftIndex < 4; LeftIndex++)
	{
		for (int RightIndex = 0; RightIndex < 4; RightIndex++)
		{
			SecondMatrix[LeftIndex][RightIndex] = ReadFromEditBox(hDlg, SecondIndex);
			SecondIndex++;
		}
	}

	for (int i = 0; i < 4; i++)
	{
		for (int LeftIndex = 0; LeftIndex < 4; LeftIndex++)
		{
			for (int RightIndex = 0; RightIndex < 4; RightIndex++)
			{
				Result += FirstMatrix[LeftIndex][RightIndex] * SecondMatrix[RightIndex][LeftIndex];
			}
			WriteToEditBox(hDlg, ResultMatrixIndex, Result);
			ResultMatrixIndex++;
			Result = 0;
		}
	}
}

void MatrixAdd(HWND hDlg, int FirstIndex, int SecondIndex)
{
	float FirstMatrix[4][4];
	float SecondMatrix[4][4];
	int ResultMatrixIndex = 1063;
	float Result = 0;

	for (int LeftIndex = 0; LeftIndex < 4; LeftIndex++)
	{
		for (int RightIndex = 0; RightIndex < 4; RightIndex++)
		{
			FirstMatrix[LeftIndex][RightIndex] = ReadFromEditBox(hDlg, FirstIndex);
			FirstIndex++;
		}
	}
	for (int LeftIndex = 0; LeftIndex < 4; LeftIndex++)
	{
		for (int RightIndex = 0; RightIndex < 4; RightIndex++)
		{
			SecondMatrix[LeftIndex][RightIndex] = ReadFromEditBox(hDlg, SecondIndex);
			SecondIndex++;
		}
	}

	for (int i = 0; i < 4; i++)
	{
		for (int LeftIndex = 0; LeftIndex < 4; LeftIndex++)
		{
			for (int RightIndex = 0; RightIndex < 4; RightIndex++)
			{
				Result += FirstMatrix[LeftIndex][RightIndex] + SecondMatrix[RightIndex][LeftIndex];
				WriteToEditBox(hDlg, ResultMatrixIndex, Result);
				ResultMatrixIndex++;
				Result = 0;
			}
			
		}
	}
}

void MatrixMinus(HWND hDlg, int FirstIndex, int SecondIndex)
{
	float FirstMatrix[4][4];
	float SecondMatrix[4][4];
	int ResultMatrixIndex = 1063;
	float Result = 0;

	for (int LeftIndex = 0; LeftIndex < 4; LeftIndex++)
	{
		for (int RightIndex = 0; RightIndex < 4; RightIndex++)
		{
			FirstMatrix[LeftIndex][RightIndex] = ReadFromEditBox(hDlg, FirstIndex);
			FirstIndex++;
		}
	}
	for (int LeftIndex = 0; LeftIndex < 4; LeftIndex++)
	{
		for (int RightIndex = 0; RightIndex < 4; RightIndex++)
		{
			SecondMatrix[LeftIndex][RightIndex] = ReadFromEditBox(hDlg, SecondIndex);
			SecondIndex++;
		}
	}

	for (int i = 0; i < 4; i++)
	{
		for (int LeftIndex = 0; LeftIndex < 4; LeftIndex++)
		{
			for (int RightIndex = 0; RightIndex < 4; RightIndex++)
			{
				Result += FirstMatrix[LeftIndex][RightIndex] - SecondMatrix[RightIndex][LeftIndex];
				WriteToEditBox(hDlg, ResultMatrixIndex, Result);
				ResultMatrixIndex++;
				Result = 0;
			}

		}
	}
}

void MatrixMinors(float Matrix[][4], float Minor[][4]) {

	int Collumns3x3Index = 0;
	int Rows3x3Index = 0;
	float TempMatrix[3][3];
	float Det1, Det2, Det3, TempMatrixDet = 0;


	for (int LeftIndex = 0; LeftIndex < 4; LeftIndex++)
	{
		for (int RightIndex = 0; RightIndex < 4; RightIndex++)
		{
			// Create a 3x3 matrix to take the determinant of
			for (int Collumns = 0; Collumns < 4; Collumns++)
			{
				for (int Rows = 0; Rows < 4; Rows++)
				{
					if (!(Collumns == LeftIndex || Rows == RightIndex))
					{
						TempMatrix[Collumns3x3Index][Rows3x3Index] = Matrix[LeftIndex][RightIndex];

						Rows3x3Index++;
						if (Rows3x3Index == 2) {
							Rows3x3Index = 0;
							Collumns3x3Index++;
							if (Collumns3x3Index == 3) Collumns3x3Index = 0;
						}
					}
				}
			}
		
	

			Det1 = TempMatrix[0][0]		* (TempMatrix[1][1] * TempMatrix[2][2] - TempMatrix[1][2] * TempMatrix[2][1]);
			Det2 = -TempMatrix[0][1]	* (TempMatrix[0][1] * TempMatrix[2][2] - TempMatrix[2][1] * TempMatrix[0][2]);
			Det3 = TempMatrix[0][2]		* (TempMatrix[0][1] * TempMatrix[1][2] - TempMatrix[1][1] * TempMatrix[0][2]);

			TempMatrixDet = (Det1 + Det2 + Det3);
			Minor[LeftIndex][RightIndex] = TempMatrixDet;
		}
	}
}

void FindCofactor(float Minor[][4], float Cofactor[][4]) {
	float sign[4][4] = {{1, -1, 1, -1},
						{-1, 1, -1, 1},
						{1, -1, 1, -1},
						{-1, 1, -1, 1} };

	for (int LeftIndex = 0; LeftIndex < 4; LeftIndex++)
	{
		for (int RightIndex = 0; RightIndex < 4; RightIndex++)
		{
			Cofactor[LeftIndex][RightIndex] = Minor[LeftIndex][RightIndex] * sign[LeftIndex][RightIndex];
			
		}
	}
}

void Inverse(HWND hDlg, int OriginalIndex)
{
	float Matrix[4][4], Minor[4][4], Cofactor[4][4], Transpose[4][4], Inverse[4][4];
	int Index = OriginalIndex;

	float Det = Determinant(hDlg, Index);
	if (Det == 0) {
		MessageBox(hDlg, L"Determinant is 0, No inverse", L"Error", MB_OK);
		return;
	}

	
	for (int LeftIndex = 0; LeftIndex < 4; LeftIndex++)
	{
		for (int RightIndex = 0; RightIndex < 4; RightIndex++)
		{
			Matrix[LeftIndex][RightIndex] = ReadFromEditBox(hDlg, Index);
			Index++;
		}
	}
	Index = OriginalIndex;

	MatrixMinors(Matrix, Minor);
	FindCofactor(Minor, Cofactor);
	

	//Transpose
	for (int LeftIndex = 0; LeftIndex < 4; LeftIndex++)
	{
		for (int RightIndex = 0; RightIndex < 4; RightIndex++)
		{
			Transpose[RightIndex][LeftIndex] = Cofactor[LeftIndex][RightIndex];
		}
	}

	
	for (int LeftIndex = 0; LeftIndex < 4; LeftIndex++)
	{
		for (int RightIndex = 0; RightIndex < 4; RightIndex++)
		{

			Inverse[LeftIndex][RightIndex] = 1/Det * Transpose[LeftIndex][RightIndex];
			
		}
	}

	

	Index = 1063;
	for (int LeftIndex = 0; LeftIndex < 4; LeftIndex++)
	{
		for (int RightIndex = 0; RightIndex < 4; RightIndex++)
		{
			 WriteToEditBox(hDlg, Index, Cofactor[LeftIndex][RightIndex]);
			Index++;
		}
	}



}


#endif    // __MATRICESFUNCTIONS_H__