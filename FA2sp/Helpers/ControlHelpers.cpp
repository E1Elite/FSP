#include "../FA2sp.h"

#include "ControlHelpers.h"
#include "Translations.h"
#include "STDHelpers.h"
#include "MultimapHelper.h"

#include <GlobalVars.h>
#include <CMapData.h>

namespace ControlHelpers
{
    void ComboBox::Clear(CComboBox& combobox)
    {
        while (combobox.DeleteString(0) != -1);
    }

    void ComboBox::LoadHouses(CComboBox& combobox, bool bShowIndex)
    {
        ComboBox::Clear(combobox);

        auto& doc = GlobalVars::INIFiles::CurrentDocument();
        MultimapHelper mmh;
        bool bMultiOnly = doc.GetBool("Basic", "MultiplayerOnly");
        if (bMultiOnly)
            mmh.AddINI(&GlobalVars::INIFiles::Rules());
        else
            mmh.AddINI(&doc);
        auto& entries = mmh.ParseIndicies("Houses", true);
        CString buffer;
        for (size_t i = 0, sz = entries.size(); i < sz; ++i)
        {
            if (bShowIndex)
                buffer.Format("%u - %s", i, entries[i]);
            else
                buffer = entries[i];
            combobox.SetItemData(combobox.AddString(buffer), i);
        }

        if (bMultiOnly && ExtConfigs::UseMPSpawnHouses)
        {
            CString spawn;
            for (int j = 0; j < 8 ; j++)
            {
                if (bShowIndex)
                    spawn.Format("%u - Multiplayer %u", ExtConfigs::MPSpawnStartIndex + j, j + 1);
                else
                    spawn.Format("Multiplayer %u", j + 1);
                combobox.SetItemData(combobox.AddString(spawn), ExtConfigs::MPSpawnStartIndex + j);
            }
        }
    }

    void ComboBox::LoadCountries(CComboBox& combobox, bool bShowIndex)
    {
        ComboBox::Clear(combobox);
    }

    void ComboBox::LoadGenericList(CComboBox& combobox, const char* pSection, bool bShowRegName, bool bShowName, bool bShowIndex)
    {
        ComboBox::Clear(combobox);

        MultimapHelper mmh;
        mmh.AddINI(&GlobalVars::INIFiles::Rules());
        mmh.AddINI(&GlobalVars::INIFiles::CurrentDocument());

        auto& entries = mmh.ParseIndicies(pSection, true);
        CString buffer;
        for (size_t i = 0, sz = entries.size(); i < sz; ++i)
        {
            if (bShowIndex)
                buffer.Format("%u", i);
            if (bShowName)
                buffer +=  (" - " + CSFQuery::GetUIName(entries[i]));
            if (bShowRegName)
                buffer += (" - " + entries[i]);
            combobox.SetItemData(combobox.AddString(buffer), i);
        }
    }
}