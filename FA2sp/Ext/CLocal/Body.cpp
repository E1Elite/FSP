#include "Body.h"

CLocal* CLocalExt::Instance = nullptr;

void CLocalExt::ProgramStartupInit()
{
	RunTime::ResetMemoryContentAt(0x583B48, &CLocalExt::PreTranslateMessageExt); //fs
}

BOOL CLocalExt::PreTranslateMessageExt(MSG* pMsg)
{
	switch (pMsg->message) {

	default:
		break;
	}
	return this->FA2CDialog::PreTranslateMessage(pMsg);
}