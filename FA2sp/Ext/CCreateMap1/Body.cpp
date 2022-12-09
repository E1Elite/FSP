#include "Body.h"

CCreateMap1* CCreateMap1Ext::Instance = nullptr;

void CCreateMap1Ext::ProgramStartupInit()
{
	RunTime::ResetMemoryContentAt(0x5857C0, &CCreateMap1Ext::PreTranslateMessageExt); //fs
}

BOOL CCreateMap1Ext::PreTranslateMessageExt(MSG* pMsg)
{
	switch (pMsg->message) {

	default:
		break;
	}
	return this->FA2CDialog::PreTranslateMessage(pMsg);
}