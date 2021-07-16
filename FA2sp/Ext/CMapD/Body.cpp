#include "Body.h"

CMapD* CMapDExt::Instance = nullptr;

void CMapDExt::ProgramStartupInit()
{
    Logger::Debug(__FUNCTION__"\n");
    auto mapdPreTranslateAddr = &CMapDExt::PreTranslateMessageExt;

    RunTime::ResetMemoryContentAt(0x584A70, &mapdPreTranslateAddr, sizeof(mapdPreTranslateAddr)); //fs
}

BOOL CMapDExt::PreTranslateMessageExt(MSG* pMsg)
{
    switch (pMsg->message) {

    default:
        break;
    }
    return this->FA2CDialog::PreTranslateMessage(pMsg);
}