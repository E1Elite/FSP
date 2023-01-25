#pragma once

#include "Body.h"

#include <GlobalVars.h>

#include <unordered_set>

#include "../../Helpers/STDHelpers.h"
#include "../../Helpers/ControlHelpers.h"

class CScriptTypesFunctions
{
public:

// 1
static void CScriptTypes_LoadParams_Target(CComboBox& comboBox)
{
    while (comboBox.DeleteString(0) != -1);

    comboBox.SetItemData(comboBox.AddString("0 - Not specified"), 0);
    comboBox.SetItemData(comboBox.AddString("1 - Anything"), 1);
    comboBox.SetItemData(comboBox.AddString("2 - Buildings"), 2);
    comboBox.SetItemData(comboBox.AddString("3 - Harvesters"), 3);
    comboBox.SetItemData(comboBox.AddString("4 - Infantry"), 4);
    comboBox.SetItemData(comboBox.AddString("5 - Vehicles"), 5);
    comboBox.SetItemData(comboBox.AddString("6 - Factories"), 6);
    comboBox.SetItemData(comboBox.AddString("7 - Base defenses"), 7);
    comboBox.SetItemData(comboBox.AddString("9 - Power plants"), 9);
}

// 2
static void CScriptTypes_LoadParams_Waypoint(CComboBox& comboBox)
{
    while (comboBox.DeleteString(0) != -1);

    auto& doc = GlobalVars::INIFiles::CurrentDocument();
    int waypoints[702];
    memset(waypoints, -1, sizeof waypoints);
    if (auto entries = doc.GetSection("Waypoints"))
        for (auto& x : entries->EntitiesDictionary)
            if (x.first != "Name" && !STDHelpers::IsNullOrEmpty(x.second))
            {
                int l = atoi(x.first);
                if (l < 702 && l >= 0)
                    waypoints[l] = atoi(x.second);
            }
    char buffer[0x20];
    for (int i = 0; i < 702; ++i)
    {
        if (waypoints[i] >= 0)
        {
            sprintf_s(buffer, "%u - (%u, %u)", 
                i, waypoints[i] % 1000, waypoints[i] / 1000);
            int idx = comboBox.AddString(buffer);
            comboBox.SetItemData(idx, i);
        }
    }
}

// 3
static void CScriptTypes_LoadParams_ScriptLine(CComboBox& comboBox, CComboBox& currentScript, CListBox& listBox)
{
    int cnt = listBox.GetCount();
    // up to 53
    if (cnt > 53)
        cnt = 53;

    while (comboBox.DeleteString(0) != -1);

    auto& doc = GlobalVars::INIFiles::CurrentDocument();

    CString buffer, scriptName, parambuf;
    currentScript.GetLBText(currentScript.GetCurSel(), scriptName);
    STDHelpers::TrimIndex(scriptName);

    for (int i = 0; i < cnt; ++i)
    {
        buffer.Format("%d", i);
        buffer = doc.GetString(scriptName, buffer, "0,0");
        int actionIndex = buffer.Find(',');
        if (actionIndex == CB_ERR)
            actionIndex = -1;
        else
            actionIndex = atoi(buffer.Mid(0, actionIndex));
        buffer.Format("%d - %s", i + 1, CScriptTypesExt::ExtActions[actionIndex].Name_);
        int idx = comboBox.AddString(buffer);
        comboBox.SetItemData(idx, i);
    }
}

// 4
static void CScriptTypes_LoadParams_SplitGroup(CComboBox& comboBox)
{
    while (comboBox.DeleteString(0) != -1);
    
    comboBox.SetItemData(comboBox.AddString("0 - Keep Transports, Keep Units"), 0);
    comboBox.SetItemData(comboBox.AddString("1 - Keep Transports, Lose Units"), 1);
    comboBox.SetItemData(comboBox.AddString("2 - Lose Transports, Keep Units"), 2);
    comboBox.SetItemData(comboBox.AddString("3 - Lose Transports, Lose Units"), 3);
}

// 5
static void CScriptTypes_LoadParams_GlobalVariables(CComboBox& comboBox)
{
    while (comboBox.DeleteString(0) != -1);

    auto& rules = GlobalVars::INIFiles::Rules();
    if (auto entities = rules.GetSection("VariableNames"))
    {
        CString text;
        for (auto& x : entities->EntitiesDictionary)
        {
            if (x.first != "Name" && !STDHelpers::IsNullOrEmpty(x.first))
            {
                int l = atoi(x.first);
                text.Format("%d - %s", l, x.second);
                comboBox.SetItemData(comboBox.AddString(text), l);
            }
        }
    }
}

// 6
static void CScriptTypes_LoadParams_ScriptTypes(CComboBox& comboBox)
{
    while (comboBox.DeleteString(0) != -1);

    auto& doc = GlobalVars::INIFiles::CurrentDocument();
    if (auto entities = doc.GetSection("ScriptTypes"))
    {
        CString text, finaltext = "";
        for (auto& ent : entities->EntitiesDictionary)
        {
            if (doc.SectionExists(ent.second) && !STDHelpers::IsNullOrEmpty(ent.second))
            {
                int id = atoi(ent.first);
                text = doc.GetString(ent.second, "Name");
                finaltext.Format("%d - %s - %s", id, ent.second, text);
                comboBox.SetItemData(comboBox.AddString(finaltext), id);
            }
        }
    }

}

// 7
static void CScriptTypes_LoadParams_TeamTypes(CComboBox& comboBox)
{
    while (comboBox.DeleteString(0) != -1);

    auto& doc = GlobalVars::INIFiles::CurrentDocument();
    if (auto entities = doc.GetSection("TeamTypes"))
    {
        CString text, finaltext = "";
        for (auto& ent : entities->EntitiesDictionary)
        {
            if (doc.SectionExists(ent.second) && !STDHelpers::IsNullOrEmpty(ent.second))
            {
                int id = atoi(ent.first);
                text = doc.GetString(ent.second, "Name");
                finaltext.Format("%d - %s - %s", id, ent.second, text);
                comboBox.SetItemData(comboBox.AddString(finaltext), id);
            }
        }
    }

}

// 8
static void CScriptTypes_LoadParams_Houses(CComboBox& comboBox)
{
    ControlHelpers::ComboBox::LoadHouses(comboBox, true);
}

// 9
static void CScriptTypes_LoadParams_Speeches(CComboBox& comboBox)
{
    while (comboBox.DeleteString(0) != -1);

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
				comboBox.SetItemData(comboBox.AddString(text), id);
			}
		}
	}
}

// 10
static void CScriptTypes_LoadParams_Sounds(CComboBox& comboBox)
{
    while (comboBox.DeleteString(0) != -1);

    auto& sound = GlobalVars::INIFiles::Sound();
    auto& fsdata = GlobalVars::INIFiles::FAData();

	auto entities = sound.GetSection("SoundList");
	if (entities == NULL)
	{
		entities = fsdata.GetSection("SoundList");
	}

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
                comboBox.SetItemData(comboBox.AddString(text), id);
            }
        }
    }
}

// 11
static void CScriptTypes_LoadParams_Movies(CComboBox& comboBox)
{
    while (comboBox.DeleteString(0) != -1);

    auto& art = GlobalVars::INIFiles::Art();
    if (auto entities = art.GetSection("Movies"))
    {
        CString text;
        for (auto& ent : entities->EntitiesDictionary)
        {
            if (ent.first != "Name")
            {
                int id = atoi(ent.first);
                text.Format("%d - %s", id, ent.second);
                comboBox.SetItemData(comboBox.AddString(text), id);
            }
        }
    }
}

// 12
static void CScriptTypes_LoadParams_Themes(CComboBox& comboBox)
{
    while (comboBox.DeleteString(0) != -1);

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
                comboBox.SetItemData(comboBox.AddString(text), id);
            }
        }
    }
}

// 13
static void CScriptTypes_LoadParams_Countries(CComboBox& comboBox)
{
    ControlHelpers::ComboBox::LoadHouses(comboBox, true);
//    ControlHelpers::ComboBox::LoadCountries(comboBox, true);
}

// 14
static void CScriptTypes_LoadParams_LocalVariables(CComboBox& comboBox)
{
    while (comboBox.DeleteString(0) != -1);

    auto& doc = GlobalVars::INIFiles::CurrentDocument();
    if (auto entities = doc.GetSection("VariableNames"))
    {
        CString text;
        for (auto& x : entities->EntitiesDictionary)
        {
            if (STDHelpers::IsNullOrEmpty(x.first) || x.first == "Name")
                continue;
            int l = atoi(x.first);
            text.Format("%d - %s", l, x.second);
            comboBox.SetItemData(comboBox.AddString(text), l);
        }
    }
}

// 15
static void CScriptTypes_LoadParams_Facing(CComboBox& comboBox)
{
    while (comboBox.DeleteString(0) != -1);

    comboBox.SetItemData(comboBox.AddString("0 - NE"), 0);
    comboBox.SetItemData(comboBox.AddString("1 - E"), 1);
    comboBox.SetItemData(comboBox.AddString("2 - SE"), 2);
    comboBox.SetItemData(comboBox.AddString("3 - S"), 3);
    comboBox.SetItemData(comboBox.AddString("4 - SW"), 4);
    comboBox.SetItemData(comboBox.AddString("5 - W"), 5);
    comboBox.SetItemData(comboBox.AddString("6 - NW"), 6);
    comboBox.SetItemData(comboBox.AddString("7 - N"), 7);
}

// 16
static void CScriptTypes_LoadParams_BuildingTypes(CComboBox& comboBox)
{
    ControlHelpers::ComboBox::LoadGenericList(comboBox, "BuildingTypes", true, true, true);
}

// 17
static void CScriptTypes_LoadParams_Animations(CComboBox& comboBox)
{
    ControlHelpers::ComboBox::LoadGenericList(comboBox, "Animations", true, false, true);
}

// 18
static void CScriptTypes_LoadParams_TalkBubble(CComboBox& comboBox)
{
    while (comboBox.DeleteString(0) != -1);

    comboBox.SetItemData(comboBox.AddString("0 - None"), 0);
    comboBox.SetItemData(comboBox.AddString("1 - Asterisk(*)"), 1);
    comboBox.SetItemData(comboBox.AddString("2 - Question mark(?)"), 2);
    comboBox.SetItemData(comboBox.AddString("3 - Exclamation mark(!)"), 3);
}

// 19
static void CScriptTypes_LoadParams_Status(CComboBox& comboBox)
{
    while (comboBox.DeleteString(0) != -1);

    const char* pStatus[] =
    {
        "Sleep",
        "Attack nearest enemy",
        "Move",
        "QMove",
        "Retreat home for R&R",
        "Guard",
        "Sticky (never recruit)",
        "Enter object",
        "Capture object",
        "Harvest",
        "Area Guard",
        "Return (to refinery)",
        "Stop",
        "Ambush (wait until discovered)",
        "Hunt",
        "Unload",
        "Sabotage (move in & destroy)",
        "Construction",
        "Deconstruction",
        "Repair",
        "Rescue",
        "Missile",
        "Harmless",
        "Open",
        "Patrol"
    };

    for (int i = 0; i < 25; ++i)
    {
        char buffer[0x40];
        sprintf_s(buffer, "%u - %s", i, pStatus[i]);
        int idx = comboBox.AddString(buffer);
        if (idx >= 0)
            comboBox.SetItemData(idx, i);
    }
}

// 20
static void CScriptTypes_LoadParams_Boolean(CComboBox& comboBox)
{
    while (comboBox.DeleteString(0) != -1);

    comboBox.SetItemData(comboBox.AddString("0 - FALSE"), 0);
    comboBox.SetItemData(comboBox.AddString("1 - TRUE"), 1);
}

// 21
static void CScriptTypes_LoadParams_CameraSpeed(CComboBox& comboBox)
{
    while (comboBox.DeleteString(0) != -1);

    comboBox.SetItemData(comboBox.AddString("0 - Slowest"), 0);
    comboBox.SetItemData(comboBox.AddString("1 - Slow"), 1);
    comboBox.SetItemData(comboBox.AddString("2 - Medium"), 2);
    comboBox.SetItemData(comboBox.AddString("3 - Fast"), 3);
    comboBox.SetItemData(comboBox.AddString("4 - Fastest"), 4);
}

};