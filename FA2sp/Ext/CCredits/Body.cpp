#include "Body.h"

CCredits* CCreditsExt::Instance = nullptr;

void CCreditsExt::ProgramStartupInit()
{
	//RunTime::ResetMemoryContentAt(0x58286C, &CCreditsExt::OnInitDialogExt); //fs
	RunTime::ResetMemoryContentAt(0x582840, &CCreditsExt::PreTranslateMessageExt); //fs
}

BOOL CCreditsExt::PreTranslateMessageExt(MSG* pMsg)
{
	switch (pMsg->message) {

	default:
		break;
	}
	return this->FA2CDialog::PreTranslateMessage(pMsg);
}