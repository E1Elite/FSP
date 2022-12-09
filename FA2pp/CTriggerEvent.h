#pragma once

#include "FA2PP.h"

class NOVTABLE CTriggerEvent : public FA2CDialog
{
public:
	CTriggerEvent() = default;

	//member properties
	CString		EventID; // 92
	CComboBox	CCBParameters; // 96
	CListBox	CLBParamList; // 156
	CComboBox	CCBEventType; // 216
	CEdit		CETDescription; // 276
	CComboBox	CCBCurrentEvent; // 336

	virtual void __thiscall DoDataExchange(CDataExchange* pDX) override
	{
		JMP_STD(0x4F0410); //fs
	}

	void OnBNNewEventClicked() { JMP_THIS(0x4F0530); } //fs
	void OnBNDelEventClicked() { JMP_THIS(0x4F0990); } //fs
	void OnCBCurrentEventSelChanged() { JMP_THIS(0x4F0E30); } //fs
	void OnCBEventTypeEditChanged() { JMP_THIS(0x4F1110); } //fs
	void OnLBParamsSelChanged() { JMP_THIS(0x4F25E0); } //fs
	void OnCBParamValueEditChanged() { JMP_THIS(0x4F2A90); } //fs
};