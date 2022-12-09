#include <Miscs/Miscs.LoadParams.h>
#include <Helpers/Macro.h>

#include <GlobalVars.h>

#include <unordered_set>

#include "../../FA2sp.h"
#include "../../Helpers/MultimapHelper.h"
#include "../../Helpers/STDHelpers.h"
#include "../../Helpers/ControlHelpers.h"

#include "../../Logger.h"

// Trigger action/event parameter dropdowns

auto AddString = [](HWND hComboBox, const char* lpString)
{
    SendMessage(hComboBox, CB_ADDSTRING, NULL, (LPARAM)lpString);
};

// 18
DEFINE_HOOK(438EE8, Miscs_LoadParams_CrateTypes, 6) //fs
{
    GET(HWND, hComboBox, EDX);
    while (SendMessage(hComboBox, CB_GETCOUNT, 0, NULL) > 0)
        SendMessage(hComboBox, CB_DELETESTRING, 0, 0);
    AddString(hComboBox, "0 - Money");
    AddString(hComboBox, "1 - Unit");
    AddString(hComboBox, "2 - HealBase");
    AddString(hComboBox, "3 - Cloak");
    AddString(hComboBox, "4 - Explosion");
    AddString(hComboBox, "5 - Napalm");
    AddString(hComboBox, "6 - Squad (not working)");
    AddString(hComboBox, "7 - Darkness");
    AddString(hComboBox, "8 - Reveal");
    AddString(hComboBox, "9 - Armor");
    AddString(hComboBox, "10 - Speed");
    AddString(hComboBox, "11 - Firepower");
    AddString(hComboBox, "12 - ICBM");
    AddString(hComboBox, "13 - Invulnerability (not working)");
    AddString(hComboBox, "14 - Veteran");
    AddString(hComboBox, "15 - IonStorm");
    AddString(hComboBox, "16 - Gas");
    AddString(hComboBox, "17 - Tiberium");
    AddString(hComboBox, "18 - Pod (not working)");
    return 0x438F6B; //fs
}

// 19
DEFINE_HOOK(438F18, Miscs_LoadParams_SpeechBubble, 6) //fs
{
    GET(HWND, hComboBox, ECX);
    while (SendMessage(hComboBox, CB_GETCOUNT, 0, NULL) > 0)
        SendMessage(hComboBox, CB_DELETESTRING, 0, 0);
    AddString(hComboBox, "0 - None");
    AddString(hComboBox, "1 - Asterisk(*)");
    AddString(hComboBox, "2 - Question mark(?)");
    AddString(hComboBox, "3 - Exclamation mark(!)");
    return 0x438F6B; //fs
}

// 11
DEFINE_HOOK(438E22, Miscs_LoadParams_Sounds, 6) //fs
{
    GET(HWND, hComboBox, EDX);
    while (SendMessage(hComboBox, CB_GETCOUNT, 0, NULL) > 0)
        SendMessage(hComboBox, CB_DELETESTRING, 0, 0);

    auto& sound = GlobalVars::INIFiles::Sound();
    auto& fsdata = GlobalVars::INIFiles::FAData();
    auto entities = sound.GetSection("SoundList");

    if (entities == NULL)
        entities = fsdata.GetSection("SoundList");

    if (entities != NULL)
    {
        CString text;
        CString soundid;
        for (auto& ent : entities->EntitiesDictionary)
        {
            if (!STDHelpers::IsNullOrEmpty(ent.second))
            {
                int id = atoi(ent.first);
                soundid.Format("%s", ent.second);
                STDHelpers::TrimString(soundid);
                text.Format("%d - %s", id, soundid);
                AddString(hComboBox, text);
            }
        }
    }
    return 0x438F6B; //fs
}

// 12
DEFINE_HOOK(438E59, Miscs_LoadParams_Themes, 6) //fs
{
    GET(HWND, hComboBox, ECX);
    while (SendMessage(hComboBox, CB_GETCOUNT, 0, NULL) > 0)
        SendMessage(hComboBox, CB_DELETESTRING, 0, 0);

    auto& theme = GlobalVars::INIFiles::Theme();
    if (auto entities = theme.GetSection("Themes"))
    {
        CString text;
        for (auto& ent : entities->EntitiesDictionary)
        {
            if (theme.SectionExists(ent.second) && !STDHelpers::IsNullOrEmpty(ent.second))
            {
                int id = atoi(ent.first);
                text.Format("%d - %s", id, ent.second);
                AddString(hComboBox, text);
            }
        }
    }
    return 0x438F6B; //fs
}

// 13
DEFINE_HOOK(438E90, Miscs_LoadParams_Speeches, 6) //fs
{
    GET(HWND, hComboBox, EAX);
    while (SendMessage(hComboBox, CB_GETCOUNT, 0, NULL) > 0)
        SendMessage(hComboBox, CB_DELETESTRING, 0, 0);

    auto& fsdata = GlobalVars::INIFiles::FAData();
    if (auto entities = fsdata.GetSection("DialogList"))
    {
        CString text;
        CString speechid;
        for (auto& ent : entities->EntitiesDictionary)
        {
            if (!STDHelpers::IsNullOrEmpty(ent.second))
            {
                int id = atoi(ent.first);
                speechid.Format("%s", ent.second);
                STDHelpers::TrimString(speechid);
                text.Format("%d - %s", id, speechid);
                AddString(hComboBox, text);
            }
        }
    }
    return 0x438F6B; //fs
}

// 17 Only 2nd parameter
DEFINE_HOOK(438DA0, Miscs_LoadParams_Waypoint, 6) //fs
{
    HWND hComboBox = *(HWND*)(R->ESI() + 0x1C);

    while (SendMessage(hComboBox, CB_GETCOUNT, 0, NULL) > 0)
        SendMessage(hComboBox, CB_DELETESTRING, 0, 0);

    auto& doc = GlobalVars::INIFiles::CurrentDocument();
    int waypoints[101];
    memset(waypoints, -1, sizeof waypoints);
    if (auto entries = doc.GetSection("Waypoints"))
        for (auto& x : entries->EntitiesDictionary)
            if (x.first != "Name" && !STDHelpers::IsNullOrEmpty(x.second))
            {
                int l = atoi(x.first);
                if (l < 101 && l >= 0)
                    waypoints[l] = atoi(x.second);
            }
    char buffer[0x20];
    for (int i = 0; i < 101; ++i)
    {
        if (waypoints[i] >= 0)
        {
            sprintf_s(buffer, "%u - (%u, %u)",
                i, waypoints[i] % 1000, waypoints[i] / 1000);
            AddString(hComboBox, buffer);
        }
    }
    return 0x438F6B; //fs
}

// For overwriting or implementing new ones.
DEFINE_HOOK(438D3D, Miscs_LoadParams_SwitchCase, 9) //fs
{
    GET(int, pCaseNumber, EAX);
    HWND hComboBox = *(HWND*)(R->ESI() + 0x1C);

    auto& rules = GlobalVars::INIFiles::Rules();
    auto& fsdata = GlobalVars::INIFiles::FAData();
    std::map<ppmfc::CString, ppmfc::CString> collector;
    auto const pINI = INIClass::GetMapDocument(true);
    auto& doc = GlobalVars::INIFiles::CurrentDocument();
    int i = 0;

    switch (pCaseNumber)
    {
    case 1:
        while (SendMessage(hComboBox, CB_GETCOUNT, 0, NULL) > 0)
            SendMessage(hComboBox, CB_DELETESTRING, 0, 0);

        {
            MultimapHelper mmh;
            bool bMultiOnly = doc.GetBool("Basic", "MultiplayerOnly");
            if (bMultiOnly)
                mmh.AddINI(&GlobalVars::INIFiles::Rules());
            else
                mmh.AddINI(&doc);
            auto& entries = mmh.ParseIndicies("Houses", true);
            CString buffer;
            for (size_t x = 0, sz = entries.size(); x < sz; ++x)
            {
                buffer.Format("%u - %s", x, entries[x]);
                AddString(hComboBox, buffer);
            }

            if (bMultiOnly && ExtConfigs::UseMPSpawnHouses)
            {
                CString spawn;
                for (int j = 0; j < 8 ; j++)
                {
                    spawn.Format("%u - Multiplayer %u", ExtConfigs::MPSpawnStartIndex + j, j + 1);
                    AddString(hComboBox, spawn);
                }
            }
        }
        return 0x438F6B;

    case 21:
        while (SendMessage(hComboBox, CB_GETCOUNT, 0, NULL) > 0)
            SendMessage(hComboBox, CB_DELETESTRING, 0, 0);

        if (auto entities = rules.GetSection("VoxelAnims"))
        {
            CString combotext;
            i = 0;
            for (auto& voxelanim : entities->EntitiesDictionary)
                if (!STDHelpers::IsNullOrEmpty(voxelanim.second))
                {
                    combotext.Format("%u - %s", i, voxelanim.second);
                    AddString(hComboBox, combotext);
                    ++i;
                }
        }
        return 0x438F6B;

    case 22:
        while (SendMessage(hComboBox, CB_GETCOUNT, 0, NULL) > 0)
            SendMessage(hComboBox, CB_DELETESTRING, 0, 0);

        collector.clear();
        if (auto const pSection = pINI->GetSection("Tags"))
            for (auto pair : pSection->EntitiesDictionary)
            {
                ppmfc::CString key(STDHelpers::SplitString((CString)pair.second)[1]);
                ppmfc::CString buffer(pair.first);
                buffer += " (";
                buffer += key;
                buffer += ")";
                collector.insert(std::make_pair(key, buffer));
            }
        for (auto pair : collector)
            AddString(hComboBox, pair.second);
        collector.clear();
        return 0x438F6B;

    case 23:
        while (SendMessage(hComboBox, CB_GETCOUNT, 0, NULL) > 0)
            SendMessage(hComboBox, CB_DELETESTRING, 0, 0);
        AddString(hComboBox, "0 - Slowest");
        AddString(hComboBox, "1 - Slow");
        AddString(hComboBox, "2 - Medium");
        AddString(hComboBox, "3 - Fast");
        AddString(hComboBox, "4 - Fastest");
        return 0x438F6B;

    case 24:
        while (SendMessage(hComboBox, CB_GETCOUNT, 0, NULL) > 0)
            SendMessage(hComboBox, CB_DELETESTRING, 0, 0);

        if (auto entities = rules.GetSection("Weapons"))
        {
            CString text;
            i = 0;
            for (auto& ent : entities->EntitiesDictionary)
                if (!STDHelpers::IsNullOrEmpty(ent.second))
                {
                    text.Format("%u - %s", i, ent.second);
                    AddString(hComboBox, text);
                    ++i;
                }
        }
        return 0x438F6B;

    case 25:
        while (SendMessage(hComboBox, CB_GETCOUNT, 0, NULL) > 0)
            SendMessage(hComboBox, CB_DELETESTRING, 0, 0);
        AddString(hComboBox, "0 - No spotlight");
        AddString(hComboBox, "1 - Obey rules.ini setting");
        AddString(hComboBox, "2 - Circle");
        AddString(hComboBox, "3 - Follow");
        return 0x438F6B;

    case 26:
        while (SendMessage(hComboBox, CB_GETCOUNT, 0, NULL) > 0)
            SendMessage(hComboBox, CB_DELETESTRING, 0, 0);
        AddString(hComboBox, "0 - Very small");
        AddString(hComboBox, "1 - Small");
        AddString(hComboBox, "2 - Medium");
        AddString(hComboBox, "3 - Large");
        return 0x438F6B;

    case 30:
        while (SendMessage(hComboBox, CB_GETCOUNT, 0, NULL) > 0)
            SendMessage(hComboBox, CB_DELETESTRING, 0, 0);
        AddString(hComboBox, "0 - Generic Combat Event");
        AddString(hComboBox, "1 - Generic Noncombat Event");
        AddString(hComboBox, "2 - Dropzone Event");
        AddString(hComboBox, "3 - Base Under Attack Event");
        AddString(hComboBox, "4 - Harvester Under Attack Event");
        AddString(hComboBox, "5 - Enemy Object Sensed Event");
        return 0x438F6B;

    }

    if (pCaseNumber > 30)
        return 0x438F6B;
    else
        return 0x438D46;
}

