#include "Body.h"

CBasic* CBasicExt::Instance = nullptr;

void CBasicExt::ProgramStartupInit()
{
    Logger::Debug(__FUNCTION__"\n");
    auto basicPreTranslateAddr = &CBasicExt::PreTranslateMessageExt;

    RunTime::ResetMemoryContentAt(0x5822B8, &basicPreTranslateAddr, sizeof(basicPreTranslateAddr)); //fs#?
}

BOOL CBasicExt::PreTranslateMessageExt(MSG* pMsg)
{
    switch (pMsg->message) {

    default:
        break;
    }
    return this->FA2CDialog::PreTranslateMessage(pMsg);
}