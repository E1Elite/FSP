#include "Body.h"

#include <GlobalVars.h>

#include "../../Helpers/STDHelpers.h"

void CHousesExt::ProgramStartupInit()
{
	// OnInit + data 0x583E44 sub_444070
	//	RunTime::ResetMemoryContentAt(0x583E18, &CHousesExt::PreTranslateMessageExt); //fs
    RunTime::ResetMemoryContentAt(0x583CB0 + 0x4, &RunTime::Messages::COMBOBOX_KILLFOCUS, 4); //fs
}

void CHousesExt::UpdateComboboxContents()
{
	while (this->CCBColor.DeleteString(0) != -1);
	while (this->CCBCountry.DeleteString(0) != -1);
	while (this->CCBHouses.DeleteString(0) != -1);
	while (this->CCBHumanHouse.DeleteString(0) != -1);

	auto& doc = GlobalVars::INIFiles::CurrentDocument();
	
}

BOOL CHousesExt::PreTranslateMessageExt(MSG* pMsg)
{
    switch (pMsg->message) {
    default:
        break;
    }
    return this->FA2CDialog::PreTranslateMessage(pMsg);
}
