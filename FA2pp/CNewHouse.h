#pragma once

#include "FA2PP.h"

class NOVTABLE CNewHouse : public FA2CDialog
{
public:
	CNewHouse() = default;

	//member properties
	CString		CString_House; // 92

	virtual void __thiscall DoDataExchange(CDataExchange* pDX) override
	{
		JMP_STD(0x4C7B40); //fs
	}
};