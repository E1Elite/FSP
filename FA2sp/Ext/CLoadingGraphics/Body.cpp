#include "Body.h"

CLoadingGraphics* CLoadingGraphicsExt::Instance = nullptr;
// Dialog 232
void CLoadingGraphicsExt::ProgramStartupInit()
{
	RunTime::ResetMemoryContentAt(0x582940, &CLoadingGraphicsExt::PreTranslateMessageExt); //fs
}

BOOL CLoadingGraphicsExt::PreTranslateMessageExt(MSG* pMsg)
{
	switch (pMsg->message) {

	default:
		break;
	}
	return this->FA2CDialog::PreTranslateMessage(pMsg);
}