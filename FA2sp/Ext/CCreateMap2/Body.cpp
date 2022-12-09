#include "Body.h"

CCreateMap2* CCreateMap2Ext::Instance = nullptr;

void CCreateMap2Ext::ProgramStartupInit()
{
	// OnInit sub_4C75F0
	RunTime::ResetMemoryContentAt(0x5853D0, &CCreateMap2Ext::PreTranslateMessageExt); //fs
}

BOOL CCreateMap2Ext::PreTranslateMessageExt(MSG* pMsg)
{
	switch (pMsg->message) {

	default:
		break;
	}
	return this->FA2CDialog::PreTranslateMessage(pMsg);
}