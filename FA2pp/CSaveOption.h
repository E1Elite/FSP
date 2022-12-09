#pragma once

#include "FA2PP.h"

class NOVTABLE CSaveOption : public FA2CDialog
{
public:
	CSaveOption() = default;

	//member properties
	BOOL		BOOL_CompressMap; // 92 , Useless
	INT			INT_CreateNewPreviewWithMinimap; // 96
	CString		CString_MapName; // 100

	virtual void __thiscall DoDataExchange(CDataExchange* pDX) override
	{
		JMP_STD(0x4C9BA0); //fs
	}
};