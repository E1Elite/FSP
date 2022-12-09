#include "Body.h"

CCreateMap3A* CCreateMap3AExt::Instance = nullptr;

void CCreateMap3AExt::ProgramStartupInit()
{
	//OnInit sub_4C76C0
	RunTime::ResetMemoryContentAt(0x5854C0, &CCreateMap3AExt::PreTranslateMessageExt); //fs
}

BOOL CCreateMap3AExt::PreTranslateMessageExt(MSG* pMsg)
{
	switch (pMsg->message) {

	default:
		break;
	}
	return this->FA2CDialog::PreTranslateMessage(pMsg);
}