#include "Body.h"

CCellTag* CCellTagExt::Instance = nullptr;

void CCellTagExt::ProgramStartupInit()
{
	// OnInit + data sub_41A660
	RunTime::ResetMemoryContentAt(0x5824A8, &CCellTagExt::PreTranslateMessageExt); //fs
}

BOOL CCellTagExt::PreTranslateMessageExt(MSG* pMsg)
{
	switch (pMsg->message) {

	default:
		break;
	}
	return this->FA2CDialog::PreTranslateMessage(pMsg);
}