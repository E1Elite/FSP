#include "Body.h"

CLoading* CLoadingExt::Instance = nullptr;
// Dialog 181
void CLoadingExt::ProgramStartupInit()
{
	RunTime::ResetMemoryContentAt(0x5848D8, &CLoadingExt::PreTranslateMessageExt); //fs
}

BOOL CLoadingExt::PreTranslateMessageExt(MSG* pMsg)
{
	switch (pMsg->message) {

	default:
		break;
	}
	return this->FA2CDialog::PreTranslateMessage(pMsg);
}