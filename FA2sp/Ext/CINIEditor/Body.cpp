#include "Body.h"

CINIEditor* CINIEditorExt::Instance = nullptr;

void CINIEditorExt::ProgramStartupInit()
{
	//RunTime::ResetMemoryContentAt(0x581E94, &CINIEditorExt::OnInitDialogExt); //fs
	RunTime::ResetMemoryContentAt(0x581E68, &CINIEditorExt::PreTranslateMessageExt); //fs
}

BOOL CINIEditorExt::PreTranslateMessageExt(MSG* pMsg)
{
	switch (pMsg->message) {

	default:
		break;
	}
	return this->FA2CDialog::PreTranslateMessage(pMsg);
}