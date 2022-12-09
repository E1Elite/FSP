#include "Body.h"

CDialog289* CDialog289Ext::Instance = nullptr;

void CDialog289Ext::ProgramStartupInit()
{
	//OnInit sub_41D600
	RunTime::ResetMemoryContentAt(582718, &CDialog289Ext::PreTranslateMessageExt); //fs
}

BOOL CDialog289Ext::PreTranslateMessageExt(MSG* pMsg)
{
	switch (pMsg->message) {
	case WM_CREATE:
		Logger::Debug(__FUNCTION__"\n");
		break;
	default:
		break;
	}
	return this->FA2CDialog::PreTranslateMessage(pMsg);
}