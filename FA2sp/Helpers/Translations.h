#pragma once

#include <FA2PP.h>

// FinalAlert.ini
class FinalAlertConfig
{
public:
    static DWORD ReadString(const char* pSection, const char* pKey, const char* pDefault = "", char* pBuffer = nullptr);
    static void WriteString(const char* pSection, const char* pKey, const char* pContent);
    static char pLastRead[0x400];
    static CString lpPath;
};

class Translations
{
public:
    static bool GetTranslationItem(const char* pLabelName, CString& ret);
    static void TranslateItem(CWnd* pWnd, int nSubID, const char* lpKey);
    static void TranslateItem(CWnd* pWnd, const char* lpKey);
    static char pLanguage[4][0x400];
};

