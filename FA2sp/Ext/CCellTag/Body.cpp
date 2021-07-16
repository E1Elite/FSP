#include "Body.h"

CCellTag* CCellTagExt::Instance = nullptr;

void CCellTagExt::ProgramStartupInit()
{
	Logger::Debug(__FUNCTION__"\n");
	auto iniEditorPreTranslateAddr = &CCellTagExt::PreTranslateMessageExt;

	RunTime::ResetMemoryContentAt(0x5824A8, &iniEditorPreTranslateAddr, sizeof(iniEditorPreTranslateAddr)); //fs
}

BOOL CCellTagExt::PreTranslateMessageExt(MSG* pMsg)
{
	switch (pMsg->message) {

	default:
		break;
	}
	return this->FA2CDialog::PreTranslateMessage(pMsg);
}