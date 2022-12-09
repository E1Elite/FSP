#pragma once

#include "FA2PP.h"

class NOVTABLE CTriggerAction : public FA2CDialog
{
public:
	CTriggerAction() = default;

	//member properties
	CString		ActionID; // 92
	CComboBox	CCBParameters; // 96
	CListBox	CLBParamList; // 156
	CComboBox	CCBActionType; // 216
	CEdit		CETDescription; // 276
	CComboBox	CCBCurrentAction; // 336

	virtual void __thiscall DoDataExchange(CDataExchange* pDX) override
	{
		JMP_STD(0x4E9770); //fs
	}

	void OnBNNewActionClicked() { JMP_THIS(0x4EC490); } //fs
	void OnBNDelActionClicked() { JMP_THIS(0x4EC850); } //fs
	void OnCBCurrentActionSelChanged() { JMP_THIS(0x4E97F0); } //fs
	void OnCBActionTypeEditChanged() { JMP_THIS(0x4E9AD0); } //fs
	void OnLBParamsSelChanged() { JMP_THIS(0x4EB5A0); } //fs
	void OnCBParamValueEditChanged() { JMP_THIS(0x4EBC50); } //fs
};