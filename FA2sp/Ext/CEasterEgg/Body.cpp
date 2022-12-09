#include "Body.h"

CEasterEgg* CEasterEggExt::Instance = nullptr;

void CEasterEggExt::ProgramStartupInit()
{
	//RunTime::ResetMemoryContentAt(0x582A74, &CEasterEggExt::OnInitDialogExt); //fs
	RunTime::ResetMemoryContentAt(0x582A48, &CEasterEggExt::PreTranslateMessageExt); //fs
}

BOOL CEasterEggExt::PreTranslateMessageExt(MSG* pMsg)
{
	switch (pMsg->message) {

	default:
		break;
	}
	return this->FA2CDialog::PreTranslateMessage(pMsg);
}