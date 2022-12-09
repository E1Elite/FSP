#include "Body.h"

CCreateMap3B* CCreateMap3BExt::Instance = nullptr;

void CCreateMap3BExt::ProgramStartupInit()
{
	// OnInit sub_4C79E0
	RunTime::ResetMemoryContentAt(0x5855C8, &CCreateMap3BExt::PreTranslateMessageExt); //fs
}

BOOL CCreateMap3BExt::PreTranslateMessageExt(MSG* pMsg)
{
	switch (pMsg->message) {

	default:
		break;
	}
	return this->FA2CDialog::PreTranslateMessage(pMsg);
}