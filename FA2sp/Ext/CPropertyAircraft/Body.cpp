#include "Body.h"

#include <CINI.h>
#include <GlobalVars.h>

#include "../../Helpers/STDHelpers.h"
#include "../../Helpers/Translations.h"
#include "../../Helpers/ControlHelpers.h"

CPropertyAircraft* CPropertyAircraftExt::Instance = nullptr;

void CPropertyAircraftExt::ProgramStartupInit()
{
	// 0x5816F4 sub_4014D0 OnInitDialog + UI populate + set current fields //fs
	RunTime::ResetMemoryContentAt(0x5816C8, &CPropertyAircraftExt::PreTranslateMessageExt); //fs
}

BOOL CPropertyAircraftExt::PreTranslateMessageExt(MSG* pMsg)
{
	switch (pMsg->message) {

	default:
		break;
	}
	return this->FA2CDialog::PreTranslateMessage(pMsg);
}