#include "Body.h"

CNewHouse* CNewHouseExt::Instance = nullptr;

void CNewHouseExt::ProgramStartupInit()
{
	RunTime::ResetMemoryContentAt(0x5857C8, &CNewHouseExt::PreTranslateMessageExt); //fs
}

BOOL CNewHouseExt::PreTranslateMessageExt(MSG* pMsg)
{
	switch (pMsg->message) {

	default:
		break;
	}
	return this->FA2CDialog::PreTranslateMessage(pMsg);
}