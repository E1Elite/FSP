#pragma once

#include "FA2PP.h"

class NOVTABLE CINIEditorImport : public FA2CDialog
{
public:
	CINIEditorImport() = default;

	//member properties
	INT			Unknown_92; // Fill 92 - 96
	CListBox	CLBAvailableSections; // 96

	virtual void __thiscall DoDataExchange(CDataExchange* pDX) override
	{
		JMP_STD(0x449020); //fs
	}
};