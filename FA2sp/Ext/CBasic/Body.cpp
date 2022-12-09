#include "Body.h"

CBasic* CBasicExt::Instance = nullptr;

void CBasicExt::ProgramStartupInit()
{
	//RunTime::ResetMemoryContentAt(0x5822E4, &CBasicExt::OnInitDialogExt); //fs
	RunTime::ResetMemoryContentAt(0x5822B8, &CBasicExt::PreTranslateMessageExt); //fs
}

BOOL CBasicExt::PreTranslateMessageExt(MSG* pMsg)
{
	switch (pMsg->message) {

	default:
		break;
	}
	return this->FA2CDialog::PreTranslateMessage(pMsg);
}