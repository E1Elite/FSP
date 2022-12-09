#include "Body.h"

CAITriggerTypesEnable* CAITriggerTypesEnableExt::Instance = nullptr;

void CAITriggerTypesEnableExt::ProgramStartupInit()
{
	//RunTime::ResetMemoryContentAt(0x581CCC, &CAITriggerTypesEnableExt::OnInitDialogExt); //fs
	RunTime::ResetMemoryContentAt(0x581CA0, &CAITriggerTypesEnableExt::PreTranslateMessageExt); //fs
}

BOOL CAITriggerTypesEnableExt::PreTranslateMessageExt(MSG* pMsg)
{
	switch (pMsg->message) {

	default:
		break;
	}
	return this->FA2CDialog::PreTranslateMessage(pMsg);
}