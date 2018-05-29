#pragma once

#if !defined(__QUATERNIONFUNCTIONS_H__)
#define __QUATERNIONFUNCTIONS_H__

//-----Library Includes
#include "utils.h"

enum QUATS
{
	QUAT_A		= 2201,
	QUAT_B		= 2205,
	QUAT_R		= 2224,
	QUAT_SCALAR = 2220,
};

void QuatAddition	(HWND hDlg);
void QuatDot		(HWND hDlg);
void QuatSubtract	(HWND hDlg, int Quat1Index, int Quat2Index);
void QuatMultiply	(HWND hDlg, int Quat1Index, int Quat2Index);
void QuatConjugate	(HWND hDlg, int QuatIndex);
void QuatMagnitude	(HWND hDlg, int QuatIndex);
void QuatInverse	(HWND hDlg, int QuatIndex);
void QuatScale		(HWND hDlg, int QuatIndex);

#endif    // __QUATERNIONFUNCTIONS_H__