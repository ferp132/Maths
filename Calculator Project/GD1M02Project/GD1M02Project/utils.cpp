#include "utils.h"

float ReadFromEditBox(HWND hDlg, int iResourceID)
{
		wchar_t Input[10];
		ZeroMemory(Input, 10);
		GetDlgItemText(hDlg, iResourceID, Input, 10);
		if (Input[0] == 0)
		{
			return 0.0f;
		}
		else
		{
			return static_cast<float>(_wtof(Input));
		}
}

void WriteToEditBox(HWND hDlg, int MatrixElementID, float NewValue)
{
	std::wstring _strValue = ToWideString(NewValue);
	SetDlgItemText(hDlg, MatrixElementID, _strValue.c_str());
}
