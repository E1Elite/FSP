#pragma once

#include "FA2PP.h"

class NOVTABLE CCreateMap2 : public FA2CDialog
{
public:
	CCreateMap2() = default;

	//member properties
	BOOL		BOOL_CompletelyNew; // 92
	BOOL		BOOL_EnableGlobalAITriggers; // 96

	virtual void __thiscall DoDataExchange(CDataExchange* pDX) override
	{
		JMP_STD(0x4C75B0); //fs
	}
};