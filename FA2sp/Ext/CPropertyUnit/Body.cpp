#include "Body.h"

#include <CINI.h>
#include <GlobalVars.h>

#include "../../Helpers/STDHelpers.h"
#include "../../Helpers/Translations.h"

CPropertyUnit* CPropertyUnitExt::Instance = nullptr;

void CPropertyUnitExt::ProgramStartupInit()
{
	//0x58848C sub_501F00 OnInitDialog + UI populate + set current fields //fs
	RunTime::ResetMemoryContentAt(0x588460, &CPropertyUnitExt::PreTranslateMessageExt); //fs
}

BOOL CPropertyUnitExt::PreTranslateMessageExt(MSG* pMsg)
{
	switch (pMsg->message) {

	default:
		break;
	}
	return this->FA2CDialog::PreTranslateMessage(pMsg);
}