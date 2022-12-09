#include <Helpers/Macro.h>
#include <GlobalVars.h>
#include <FAMemory.h>

#include <FA2PPCore.h>

#include <CLoading.h>

#include "../Logger.h"
#include "../FA2sp.h"
#include "../Helpers/STDHelpers.h"

DEFINE_HOOK(4744A5, FileNames_SoundIni, 7) //fs
{
    GET(CLoading*, pThis, EBP);

    INIClass* pFAData = &GlobalVars::INIFiles::FAData.get();
    CString pFile;
    if (*reinterpret_cast<bool*>(0x5BD408)) //Firestorm AddOn
        pFile = pFAData->GetString("Filenames", "SoundFS", "INI\\SOUND01.INI");
	else
        pFile = pFAData->GetString("Filenames", "Sound", "INI\\SOUND.INI");
    pThis->LoadTSINI(pFile, &GlobalVars::INIFiles::Sound(), FALSE);
    return 0x4744B8; //fs
}

/*
DEFINE_HOOK(472308, FileNames_RulesIni, 7) //fs
{
    GET(CLoading*, pThis, EBP);

    INIClass* pFAData = &GlobalVars::INIFiles::FAData.get();
    CString pFile;
    pFile = pFAData->GetString("Filenames", "Rules", "rules.ini");
    pThis->LoadTSINI(pFile, &GlobalVars::INIFiles::Rules(), FALSE);
    return 0x47231B; //fs
}

DEFINE_HOOK(47A450, FileNames_ThemeIni, 7)
{
    GET(CLoading*, pThis, EBP);

    INIClass* pFAData = &GlobalVars::INIFiles::FAData.get();
    CString pFile;
    if (*reinterpret_cast<bool*>(0x5CE3B8)) //Map [Basic] RequiredAddOn=1
        pFile = pFAData->GetString("Filenames", "ThemeFS", "theme01.ini");
    else
        pFile = pFAData->GetString("Filenames", "Theme", "theme.ini");

    pThis->LoadTSINI(pFile, &GlobalVars::INIFiles::Theme(), FALSE);
    return 0x47A463;
}


DEFINE_HOOK(47A57D, FileNames_TemperateIni, 7)
{
    GET(CLoading*, pThis, EBP);

    INIClass* pFAData = &GlobalVars::INIFiles::FAData.get();
    CString pFile;
    if (
        *reinterpret_cast<bool*>(0x5CE3B8) // bLoadYRFiles
        &&
        *reinterpret_cast<bool*>(0x5D32AC) // bSupportYR
        )
    {
        pFile = pFAData->GetString("Filenames", "TemperateYR", "TemperatMd.ini");
    }
    else
        pFile = pFAData->GetString("Filenames", "Temperate", "Temperat.ini");
    pThis->LoadTSINI(pFile, &GlobalVars::INIFiles::Temperate(), FALSE);
    return 0x47A5AC;
}

DEFINE_HOOK(47A61D, FileNames_SnowIni, 7)
{
    GET(CLoading*, pThis, EBP);

    INIClass* pFAData = &GlobalVars::INIFiles::FAData.get();
    CString pFile;
    if (
        *reinterpret_cast<bool*>(0x5CE3B8) // bLoadYRFiles
        &&
        *reinterpret_cast<bool*>(0x5D32AC) // bSupportYR
        )
    {
        pFile = pFAData->GetString("Filenames", "SnowYR", "SnowMd.ini");
    }
    else
        pFile = pFAData->GetString("Filenames", "Snow", "Snow.ini");
    pThis->LoadTSINI(pFile, &GlobalVars::INIFiles::Snow(), FALSE);
    return 0x47A64C;
}

DEFINE_HOOK(48768B, FileNames_MixExtension, 5)
{
    REF_STACK(CString, name, 40);
    INIClass* pFAData = &GlobalVars::INIFiles::FAData();
    name += pFAData->GetString("Filenames", "MixExtension", "md");
    R->ECX<const char*>(name);
    return 0x487699;
}
*/