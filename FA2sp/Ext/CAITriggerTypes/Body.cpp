#include "Body.h"

CAITriggerTypes* CAITriggerTypesExt::Instance = nullptr;

void CAITriggerTypesExt::ProgramStartupInit()
{
	auto aiTriggerTypesPreTranslateAddr = &CAITriggerTypesExt::PreTranslateMessageExt;

	RunTime::ResetMemoryContentAt(0x581B38, &aiTriggerTypesPreTranslateAddr, sizeof(aiTriggerTypesPreTranslateAddr)); //fs
}

BOOL CAITriggerTypesExt::PreTranslateMessageExt(MSG* pMsg)
{
	switch (pMsg->message) {

	default:
		break;
	}
	return this->FA2CDialog::PreTranslateMessage(pMsg);
}