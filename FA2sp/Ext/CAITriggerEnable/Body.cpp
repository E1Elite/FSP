#include "Body.h"

AITriggerEnable* CAITriggerEnableExt::Instance = nullptr;

void CAITriggerEnableExt::ProgramStartupInit()
{
	//OnInit sub_401BB0
	RunTime::ResetMemoryContentAt(0x5817B8, &CAITriggerEnableExt::PreTranslateMessageExt); //fs
}

BOOL CAITriggerEnableExt::PreTranslateMessageExt(MSG* pMsg)
{
	switch (pMsg->message) {

	default:
		break;
	}
	return this->FA2CDialog::PreTranslateMessage(pMsg);
}