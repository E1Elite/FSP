#include "Body.h"

CCreateMap4* CCreateMap4Ext::Instance = nullptr;

void CCreateMap4Ext::ProgramStartupInit()
{
	//OnInit sub_4C7BD0
	RunTime::ResetMemoryContentAt(0x5856D0, &CCreateMap4Ext::PreTranslateMessageExt); //fs
}

BOOL CCreateMap4Ext::PreTranslateMessageExt(MSG* pMsg)
{
	switch (pMsg->message) {

	default:
		break;
	}
	return this->FA2CDialog::PreTranslateMessage(pMsg);
}