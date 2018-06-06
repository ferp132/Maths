#include "GaussFunctions.h"

void GaussMultiply(HWND hDlg, int RowIndex)
{
	float Row[4];
	float Scalar = ReadFromEditBox(hDlg, MSCALAR);

	for (int Col = 0; Col < 4; Col++)
	{
		Row[Col] = ReadFromEditBox(hDlg, RowIndex + Col) * Scalar;
		WriteToEditBox(hDlg, RowIndex + Col, Row[Col]);
	}

	GaussEchelonCheck(hDlg);
}

void GaussSwap(HWND hDlg, int RowIndex1, int RowIndex2)
{
	
	float TempRow[4];

	for (int Col = 0; Col < 4; Col++)
	{
		TempRow[Col] = ReadFromEditBox(hDlg, RowIndex1 + Col);
		WriteToEditBox(hDlg, RowIndex1 + Col, ReadFromEditBox(hDlg, RowIndex2 + Col));
		WriteToEditBox(hDlg, RowIndex2 + Col, TempRow[Col]);
	}

	GaussEchelonCheck(hDlg);
}

void GaussAdd(HWND hDlg, int RowIndex1, int RowIndex2)
{
	float RowScaled[4], RowTemp[4];
	float Scalar = ReadFromEditBox(hDlg, ASCALAR);

	for (int Col = 0; Col < 4; Col++)
	{
		RowScaled[Col]	= ReadFromEditBox(hDlg, RowIndex1 + Col) * Scalar;
		RowTemp[Col]	= RowScaled[Col] + ReadFromEditBox(hDlg, RowIndex2 + Col);
		WriteToEditBox(hDlg, RowIndex2 + Col, RowTemp[Col]);
	}

	GaussEchelonCheck(hDlg);
}

void GaussEchelonCheck(HWND hDlg)
{

}

int RowCheck(HWND hDlg, int RowBox)
{
	int RowIndex = ReadFromEditBox(hDlg, RowBox);

	if		(RowIndex == 1 || RowIndex == R1)	RowIndex = R1;
	else if (RowIndex == 2 || RowIndex == R2)	RowIndex = R2;
	else										RowIndex = R3;

	return RowIndex;
}
