#pragma once

#include "FA2PP.h"

class NOVTABLE CUpdateProgress : public FA2CDialog
{
public:
	CUpdateProgress() = default;

	//member properties
	int Unknown_92;
	CProgressCtrl ProgressBar;
	CString CString_Title;
	CString CString_Buffer;

	virtual void __thiscall DoDataExchange(CDataExchange* pDX) override
	{
		JMP_STD(0x4C80A0); //fs
	}
};