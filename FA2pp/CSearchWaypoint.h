#pragma once

#include "FA2PP.h"

class NOVTABLE CSearchWaypoint : public FA2CDialog
{
public:
	CSearchWaypoint() = default;

	//member properties
	INT			INT_SelectedWaypoint; // 92
	CString		CString_Waypoint; // 96

	virtual void __thiscall DoDataExchange(CDataExchange* pDX) override
	{
		JMP_STD(0x4CD230); //fs
	}
};