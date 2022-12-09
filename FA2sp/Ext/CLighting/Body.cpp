#include "Body.h"

CLighting* CLightingExt::Instance = nullptr;

void CLightingExt::ProgramStartupInit()
{
	RunTime::ResetMemoryContentAt(0x5847B8, &CLightingExt::PreTranslateMessageExt); //fs
}

BOOL CLightingExt::PreTranslateMessageExt(MSG* pMsg)
{
	switch (pMsg->message) {

	default:
		break;
	}
	return this->FA2CDialog::PreTranslateMessage(pMsg);
}