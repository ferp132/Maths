#pragma once

#if !defined(__SLERPFUNCTIONS_H__)
#define __SLERPFUNCTIONS_H__

//-----Library Includes
#include "utils.h"
#include "QuaternionFunctions.h"

enum SLERPIndexes
{
	QUATA		= 2304,
	QUATB		= 2308,
	QUATABT		= 2313,
	MATRIXA = 2318,
	TSCALAR		= 2312,

};

void SLERPComputeABT		(HWND hDlg);
void SLERPConvertToMatrix	(HWND hDlg, int QuatIndex);
void SLERPInverse			(HWND hDlg, float Quat[], float InverseQuat[]);
void SLERPMultiply			(HWND hDlg, float Quat1[], float Quat2[], float QuatR[]);

#endif    // __SLERPFUNCTIONS_H__