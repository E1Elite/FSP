#include "Body.h"

CMapD* CMapDExt::Instance = nullptr;

void CMapDExt::ProgramStartupInit()
{
	RunTime::ResetMemoryContentAt(0x584A70, &CMapDExt::PreTranslateMessageExt); //fs
}

BOOL CMapDExt::PreTranslateMessageExt(MSG* pMsg)
{
	switch (pMsg->message) {

	default:
		break;
	}
	return this->FA2CDialog::PreTranslateMessage(pMsg);
}