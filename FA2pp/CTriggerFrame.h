#pragma once

#include "FA2PP.h"

#include "CTriggerOption.h"
#include "CTriggerEvent.h"
#include "CTriggerAction.h"

class NOVTABLE CTriggerFrame : public FA2CDialog
{
public:
	CTriggerFrame() = default;

	//member properties
	CTriggerAction TriggerAction;
	CTriggerEvent TriggerEvent;
	CTriggerOption TriggerOption;
	char gap[60];
	CTabCtrl TabCtrl;

	BOOL OnInitDialog() override
	{
		JMP_THIS(0x4ED5B0); //fs
	}

	virtual void __thiscall DoDataExchange(CDataExchange* pDX) override
	{
		JMP_STD(0x4ED550 ); //fs
	}
};