#pragma once

#include "FA2PP.h"

class NOVTABLE CCredits : public FA2CDialog
{
public:
	CCredits() = default;

	//member properties
	BYTE		Unknown_92[8]; // Fill 92 - 100
	CStatic	CSCEasterEgg; // 100


	virtual void __thiscall DoDataExchange(CDataExchange* pDX) override
	{
		JMP_STD(0x41D8D0); //fs
	}
};