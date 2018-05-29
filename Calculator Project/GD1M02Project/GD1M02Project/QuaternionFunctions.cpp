#include "QuaternionFunctions.h"

void QuatAddition	(HWND hDlg)
{
	for (int IJKR = 0; IJKR < 4; IJKR++)
	{
		WriteToEditBox(hDlg, QUAT_R + IJKR, ReadFromEditBox(hDlg, QUAT_A + IJKR) + ReadFromEditBox(hDlg, QUAT_B + IJKR));
	}
}
void QuatDot		(HWND hDlg)
{
}
void QuatSubtract	(HWND hDlg, int Quat1Index, int Quat2Index)
{
}
void QuatMultiply	(HWND hDlg, int Quat1Index, int Quat2Index)
{
}
void QuatConjugate	(HWND hDlg, int QuatIndex)
{
}
void QuatMagnitude	(HWND hDlg, int QuatIndex)
{
}
void QuatInverse	(HWND hDlg, int QuatIndex)
{
}
void QuatScale		(HWND hDlg, int QuatIndex)
{
}
