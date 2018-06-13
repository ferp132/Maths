#include "SLERPFunctions.h"

void SLERPComputeABT(HWND hDlg)
{
	float QuatA[4], QuatB[4], QuatAInverse[4], QuatABI[4] , QuatPowerOfT[4], QuatSLERP[4];
	float t = ReadFromEditBox(hDlg, TSCALAR);

	for (int IJKR = 0; IJKR < 4; IJKR++)
	{
		QuatA[IJKR]			= ReadFromEditBox(hDlg, QUATA + IJKR);
		QuatB[IJKR]			= ReadFromEditBox(hDlg, QUATB + IJKR);
		QuatAInverse[IJKR]	= 0;
		QuatABI[IJKR]		= 0;
		QuatPowerOfT[IJKR]	= 0;
		QuatSLERP[IJKR]		= 0;
	}

	SLERPInverse(hDlg, QuatA, QuatAInverse);
	SLERPMultiply(hDlg, QuatB, QuatAInverse, QuatABI);

	for (int IJKR = 0; IJKR < 4; IJKR++)
	{
		QuatPowerOfT[IJKR] = QuatABI[IJKR];
	}

	for (int i = 1; i < t; i++)
	{
		SLERPMultiply(hDlg, QuatPowerOfT, QuatABI, QuatPowerOfT);
	}

	SLERPMultiply(hDlg, QuatPowerOfT, QuatA, QuatSLERP);

	for (int IJKR = 0; IJKR < 4; IJKR++)
	{
		WriteToEditBox(hDlg, QUATABT + IJKR, QuatSLERP[IJKR]);
	}
}

void SLERPConvertToMatrix(HWND hDlg, int QuatIndex)
{
	float Quat[4];

	for (int IJKR = 0; IJKR < 4; IJKR++)
	{
		Quat[IJKR] = ReadFromEditBox(hDlg, QuatIndex + IJKR);
	}

	WriteToEditBox(hDlg, MATRIXA, Quat[I]);
	WriteToEditBox(hDlg, MATRIXA + 1, 0);
	WriteToEditBox(hDlg, MATRIXA + 2, 0);
	WriteToEditBox(hDlg, MATRIXA + 3, 0);
	WriteToEditBox(hDlg, MATRIXA + 4, 0);
	WriteToEditBox(hDlg, MATRIXA + 5, Quat[J]);
	WriteToEditBox(hDlg, MATRIXA + 6, 0);
	WriteToEditBox(hDlg, MATRIXA + 7, 0);
	WriteToEditBox(hDlg, MATRIXA + 8, 0);
	WriteToEditBox(hDlg, MATRIXA + 9, 0);
	WriteToEditBox(hDlg, MATRIXA + 10,	Quat[K]);
	WriteToEditBox(hDlg, MATRIXA + 11, 0);
	WriteToEditBox(hDlg, MATRIXA + 12, 0);
	WriteToEditBox(hDlg, MATRIXA + 13, 0);
	WriteToEditBox(hDlg, MATRIXA + 14, 0);
	WriteToEditBox(hDlg, MATRIXA + 15, Quat[R]);
}

void SLERPInverse(HWND hDlg, float Quat[4], float InverseQuat[4])
{
	//-----Arrays For Conjugate
	float QuatCon[4], QuatR[4];

	//-----Conjugate
	for (int IJKR = 0; IJKR < 4; IJKR++)
	{
		QuatCon[IJKR] = -Quat[IJKR];
	}
	//-----QuatMultiply
	//----Assign Values To Quat R
	for (int IJKR = 0; IJKR < 4; IJKR++)
	{
		QuatR[IJKR] = 0;
	}
	//----Do Multipication and assign to Quat R
	for (int Q1_IJKR = 0; Q1_IJKR < 4; Q1_IJKR++)
	{
		for (int Q2_IJKR = 0; Q2_IJKR < 4; Q2_IJKR++)
		{
			switch (Q1_IJKR + Q2_IJKR)
			{
			case 0:
			{
				QuatR[R] -= Quat[I] * Quat[I];	//-----I*I = -1
				break;
			}
			case 1:
			{
				if (Q1_IJKR == I)			QuatR[K] += Quat[I] * Quat[J];	//-----I*J = K
				else						QuatR[K] -= Quat[J] * Quat[I];	//-----J*I = -K
				break;
			}
			case 2:
			{
				if (Q1_IJKR == I)			QuatR[J] -= Quat[I] * Quat[K];	//-----I*K = -J
				else if (Q1_IJKR == J)		QuatR[R] -= Quat[J] * Quat[J];	//-----J*J = -1
				else						QuatR[J] += Quat[K] * Quat[I];	//-----K*I = J
				break;
			}
			case 3:
			{
				if (Q1_IJKR == I)			QuatR[I] += Quat[I] * Quat[R];	//-----I*R = I
				else if (Q1_IJKR == J)		QuatR[I] += Quat[J] * Quat[K];	//-----J*K = I
				else if (Q1_IJKR == K)		QuatR[I] -= Quat[K] * Quat[J];	//-----K*J = -I
				else						QuatR[I] += Quat[R] * Quat[I];	//-----R*I = I
				break;
			}
			case 4:
			{
				if (Q1_IJKR == J)			QuatR[J] += Quat[J] * Quat[R];	//-----J*R = J
				else if (Q1_IJKR == K)		QuatR[R] -= Quat[K] * Quat[K];	//-----K*K = -1
				else						QuatR[J] += Quat[R] * Quat[J];	//-----R*J = J
				break;
			}
			case 5:
			{
				if (Q1_IJKR == K)			QuatR[K] += Quat[K] * Quat[R];	//-----K*R = K
				else						QuatR[K] += Quat[R] * Quat[K];	//-----R*K = K
				break;
			}
			case 6:
			{
				QuatR[R] += Quat[R] * Quat[R];	//-----R*R = 1
				break;
			}
			default: MessageBox(hDlg, L"MULTIPICATION FAILED", L"ERROR", MB_OK);
			}
		}
	}

	for (int IJKR = 0; IJKR < 4; IJKR++)
	{
		InverseQuat[IJKR] = QuatCon[IJKR] / QuatR[IJKR];
	}
}

void SLERPMultiply(HWND hDlg, float Quat1[], float Quat2[] , float QuatR[])
{

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
				if (Q1_IJKR == I)		QuatR[K] += Quat1[I] * Quat2[J];	//-----I*J = K
				else						QuatR[K] -= Quat1[J] * Quat2[I];	//-----J*I = -K
				break;
			}
			case 2:
			{
				if (Q1_IJKR == I)		QuatR[J] -= Quat1[I] * Quat2[K];	//-----I*K = -J
				else if (Q1_IJKR == J)		QuatR[R] -= Quat1[J] * Quat2[J];	//-----J*J = -1
				else						QuatR[J] += Quat1[K] * Quat2[I];	//-----K*I = J
				break;
			}
			case 3:
			{
				if (Q1_IJKR == I)		QuatR[I] += Quat1[I] * Quat2[R];	//-----I*R = I
				else if (Q1_IJKR == J)		QuatR[I] += Quat1[J] * Quat2[K];	//-----J*K = I
				else if (Q1_IJKR == K)		QuatR[I] -= Quat1[K] * Quat2[J];	//-----K*J = -I
				else						QuatR[I] += Quat1[R] * Quat2[I];	//-----R*I = I
				break;
			}
			case 4:
			{
				if (Q1_IJKR == J)		QuatR[J] += Quat1[J] * Quat2[R];	//-----J*R = J
				else if (Q1_IJKR == K)		QuatR[R] -= Quat1[K] * Quat2[K];	//-----K*K = -1
				else						QuatR[J] += Quat1[R] * Quat2[J];	//-----R*J = J
				break;
			}
			case 5:
			{
				if (Q1_IJKR == K)		QuatR[K] += Quat1[K] * Quat2[R];	//-----K*R = K
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
}
