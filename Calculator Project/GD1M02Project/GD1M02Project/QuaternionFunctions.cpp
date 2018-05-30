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
	for (int IJKR = 0; IJKR < 4; IJKR++)
	{
		WriteToEditBox(hDlg, QUAT_R + IJKR, ReadFromEditBox(hDlg, Quat1Index + IJKR) - ReadFromEditBox(hDlg, Quat2Index + IJKR));
	}
}
void QuatMultiply	(HWND hDlg, int Quat1Index, int Quat2Index)
{
	float Quat1[4], Quat2[4], QuatR[4];

	//-----Assign Values To Quat 1 and Quat 2
	for (int IJKR = 0; IJKR < 4; IJKR++)
	{
		Quat1[IJKR] = ReadFromEditBox(hDlg, Quat1Index + IJKR);
		Quat2[IJKR] = ReadFromEditBox(hDlg, Quat2Index + IJKR);
		QuatR[IJKR] = 0;
	}
	//-----Do Multipication and assign to Quat R
	for (int Q1_IJKR = 0; Q1_IJKR < 4; Q1_IJKR++)
	{
		for (int Q2_IJKR = 0; Q2_IJKR < 4; Q2_IJKR++)
		{
			switch (Q1_IJKR + Q2_IJKR)
			{
			case 0:													
			{
											QuatR[R] -= Quat1[I] * Quat2[I];	//-----I*I = -1
				break;
			}
			case 1:									  
			{
				if		(Q1_IJKR == I)		QuatR[K] += Quat1[I] * Quat2[J];	//-----I*J = K
				else						QuatR[K] -= Quat1[J] * Quat2[I];	//-----J*I = -K
				break;
			}
			case 2: 
			{
				if		(Q1_IJKR == I)		QuatR[J] -= Quat1[I] * Quat2[K];	//-----I*K = -J
				else if (Q1_IJKR == J)		QuatR[R] -= Quat1[J] * Quat2[J];	//-----J*J = -1
				else						QuatR[J] += Quat1[K] * Quat2[I];	//-----K*I = J
				break;
			}
			case 3:
			{
				if		(Q1_IJKR == I)		QuatR[I] += Quat1[I] * Quat2[R];	//-----I*R = I
				else if (Q1_IJKR == J)		QuatR[I] += Quat1[J] * Quat2[K];	//-----J*K = I
				else if (Q1_IJKR == K)		QuatR[I] -= Quat1[K] * Quat2[J];	//-----K*J = -I
				else						QuatR[I] += Quat1[R] * Quat2[I];	//-----R*I = I
				break;
			}
			case 4:
			{
				if		(Q1_IJKR == J)		QuatR[J] += Quat1[J] * Quat2[R];	//-----J*R = J
				else if (Q1_IJKR == K)		QuatR[R] -= Quat1[K] * Quat2[K];	//-----K*K = -1
				else						QuatR[J] += Quat1[R] * Quat2[J];	//-----R*J = J
				break;
			}
			case 5:
			{
				if		(Q1_IJKR == K)		QuatR[K] += Quat1[K] * Quat2[R];	//-----K*R = K
				else						QuatR[K] += Quat1[R] * Quat2[K];	//-----R*K = K
				break;
			}
			case 6:
			{
											QuatR[R] += Quat1[R] * Quat2[R];	//-----R*R = 1
				break;
			}
			default: MessageBox(hDlg, L"MULTIPICATION FAILED", L"ERROR", MB_OK);
			}
			}
	}
	//-----Print Quat R to Dialog
	for (int IJKR = 0; IJKR < 4; IJKR++)
	{
		WriteToEditBox(hDlg, QUAT_R + IJKR, QuatR[IJKR]);
	}
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
