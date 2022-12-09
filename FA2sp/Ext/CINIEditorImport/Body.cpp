#include "Body.h"

CINIEditorImport* CINIEditorImportExt::Instance = nullptr;

void CINIEditorImportExt::ProgramStartupInit()
{
	//OnInit sub_449070
	RunTime::ResetMemoryContentAt(0x583F38, &CINIEditorImportExt::PreTranslateMessageExt); //fs
}

BOOL CINIEditorImportExt::PreTranslateMessageExt(MSG* pMsg)
{
	switch (pMsg->message) {

	default:
		break;
	}
	return this->FA2CDialog::PreTranslateMessage(pMsg);
}