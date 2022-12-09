#include "Body.h"

#include <CINI.h>
#include <GlobalVars.h>

#include "../../Helpers/STDHelpers.h"
#include "../../Helpers/Translations.h"

CPropertyInfantry* CPropertyInfantryExt::Instance = nullptr;

void CPropertyInfantryExt::ProgramStartupInit()
{
	//0x584054 sub_4496D0 OnInitDialog + UI populate + set current fields //fs
	RunTime::ResetMemoryContentAt(0x584028, &CPropertyInfantryExt::PreTranslateMessageExt); //fs
}

BOOL CPropertyInfantryExt::PreTranslateMessageExt(MSG* pMsg)
{
	switch (pMsg->message) {

	default:
		break;
	}
	return this->FA2CDialog::PreTranslateMessage(pMsg);
}