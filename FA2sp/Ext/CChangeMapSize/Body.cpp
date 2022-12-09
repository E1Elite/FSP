#include "Body.h"

CChangeMapSize* CChangeMapSizeExt::Instance = nullptr;

void CChangeMapSizeExt::ProgramStartupInit()
{
	//RunTime::ResetMemoryContentAt(0x5825F4, &CChangeMapSizeExt::OnInitDialogExt); //fs
	RunTime::ResetMemoryContentAt(0x5825C8, &CChangeMapSizeExt::PreTranslateMessageExt); //fs
}

BOOL CChangeMapSizeExt::PreTranslateMessageExt(MSG* pMsg)
{
	switch (pMsg->message) {

	default:
		break;
	}
	return this->FA2CDialog::PreTranslateMessage(pMsg);
}