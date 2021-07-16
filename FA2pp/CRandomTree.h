#pragma once

#include "FA2PP.h"

class NOVTABLE CRandomTree : public FA2CDialog
{
public:
	CRandomTree() = default;

	void OnBNToUsedClicked()
	{
		JMP_THIS(0x4C8D70); //fs
	}
	void OnBNToAvailableClicked()
	{
		JMP_THIS(0x4C8E20); //fs
	}
	void OnLBAvailableSelectChanged()
	{
		JMP_THIS(0x4C9170); //fs
	}
	void OnLBAvailableDoubleClicked()
	{
		JMP_THIS(0x4C9240); //fs
	}
	void OnLBUsedSelectChanged()
	{
		JMP_THIS(0x4C92F0); //fs
	}
	void OnLBUsedDoubleClicked()
	{
		JMP_THIS(0x4C93C0); //fs
	}
	void OnPaint()
	{
		JMP_THIS(0x4C9470); //fs
	}
	//member properties
	CButton		CBNPreviewImage; // 92
	CListBox	CLBUsed; // 152
	CListBox	CLBAvailable; // 212
	CString		CString_Terrain; // 272

	virtual void __thiscall DoDataExchange(CDataExchange* pDX) override
	{
		JMP_STD(0x4C85C0); //fs
	}
};