#include "FA2sp.h"

#include <CINI.h>

//
//DEFINE_HOOK(4943BE, Hook_494350, 5)
//{
//    struct CSFThingA
//    {
//        CString Source;
//        wchar_t* WideString;
//        int Unknown;
//        int Length;
//    };
//
//
//    GET(CSFThingA*, pThis, ESI);
//    GET_STACK(char*, lpString, STACK_OFFS(0x1C, -0x4));
//
//    Logger::Debug("%s\n", lpString);
//    
//
//    return 0;
//}

//DEFINE_HOOK(526020, ShapeFileClass_Draw, 8)
//{
//    GET_STACK(int, nFrame, 0x4);
//    GET_STACK(UINT, nFlags, 0x8);
//    GET_STACK(int, what, 0xC);
//
//    Logger::Debug(__FUNCTION__" nFrame = %d, nFlag = %d, what = %08X\n", nFrame, nFlags, what);
//
//    return 0;
//}

//DEFINE_HOOK(4B5D98, Debug_4AE910_Begin, 5)
//{
//    GET(const char*, pRegName, EAX);
//    if(pRegName)
//        Logger::Debug(__FUNCTION__" pRegName = %s\n", pRegName);
//    return 0;
//}
//
//DEFINE_HOOK(4B5DA3, Debug_4AE910_End, 8)
//{
//    GET(int, nResult, EAX);
//    Logger::Debug(__FUNCTION__" nResult = %d\n", nResult);
//    return 0;
//}
//
//DEFINE_HOOK(483669, Building_SHPTurret_SectionNameFix, 5)
//{
//    //GET_STACK(const char**, pSectionName, STACK_OFFS(0x86C, 0x90));
//    GET(const char**, pSectionName, ECX);
//    Logger::Debug(__FUNCTION__" DEBUGGING %s\n", *pSectionName);
//    return 0;
//}
//DEFINE_HOOK(531D33, Debug_531D33_FileName, 8)
//{
//    GET(const char*, pFileName, EAX);
//    Logger::Debug(__FUNCTION__" Filename = %s\n", pFileName);
//    return 0;
//}


/*
* The SHPDict is used for two different places.
* First one is the smudges. Which will be called during the map initialization.
* Then the x.second means the order of the smudge loading
* 
* The second one is for the Technotypes.
* 
* [Debug] sub_4767B0 pStr = KNIGHT
* [Debug] Current map details:
* [Debug] ADOG - 1
* [Debug] BPLN - 1
* [Debug] E1 - 1
* [Debug] ETNK - 0
* [Debug] GACNST - 0
* [Debug] GAPILE - 0
* [Debug] GGI - 1
* [Debug] KNIGHT - 0
* [Debug] NACNST - 0
* [Debug] NAHAND - 0
* [Debug] NAWEAP - 0
* [Debug] ORCA - 1
* [Debug] PDPLANEUS - 1
* [Debug] TENGU - 0
* 
* I cannot find out wtf it is though currently.
* 
 */
//DEFINE_HOOK(4767F8, sub_4767B0, 8)
//{
//    using SHPDict = FAMap<ppmfc::CString, DWORD, 0x5D8CD0, 0x5D8CCC>;
//
//    GET(SHPDict*, pDict, ESI);
//    GET_STACK(CString*, pStr, 0x20 + 0x4);
//
//    Logger::Debug(__FUNCTION__" pStr = %s\n", *pStr);
//    Logger::Debug("Current map details:\n");
//    for (auto& x : *pDict)
//        Logger::Debug("%s - %d\n", x.first, x.second);
//    Logger::Debug("\n");
//
//    return 0;
//}

