#include "Body.h"

CAITriggerTypesEnable* CAITriggerTypesEnableExt::Instance = nullptr;

void CAITriggerTypesEnableExt::ProgramStartupInit()
{
    Logger::Debug(__FUNCTION__"\n");
    auto aiTriggerTypesEnablePreTranslateAddr = &CAITriggerTypesEnableExt::PreTranslateMessageExt;

    RunTime::ResetMemoryContentAt(0x581CA0, &aiTriggerTypesEnablePreTranslateAddr, sizeof(aiTriggerTypesEnablePreTranslateAddr)); //fs#?
}

BOOL CAITriggerTypesEnableExt::PreTranslateMessageExt(MSG* pMsg)
{
    switch (pMsg->message) {

    default:
        break;
    }
    return this->FA2CDialog::PreTranslateMessage(pMsg);
}