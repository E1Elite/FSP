#pragma once

#include "FA2PP.h"

class NOVTABLE CCreateMap3B : public FA2CDialog // Import map
{
public:
	CCreateMap3B() = default;

	//member properties
	CString			CString_FilePath; // 92
	BOOL			BOOL_ImportOverlay; // 96
	BOOL			BOOL_ImportTrees; // 100
	BOOL			BOOL_ImportUnitsAndBuildings; // 104

	virtual void __thiscall DoDataExchange(CDataExchange* pDX) override
	{
		JMP_STD(0x4C7860); //fs
	}
};