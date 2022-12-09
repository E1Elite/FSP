#include "Body.h"

#include <CINI.h>
#include <GlobalVars.h>

#include "../../Helpers/STDHelpers.h"
#include "../../Helpers/Translations.h"
#include "../../Helpers/ControlHelpers.h"

CPropertyBuilding* CPropertyBuildingExt::Instance = nullptr;

void CPropertyBuildingExt::ProgramStartupInit()
{
	// 0x5823E4 sub_417780 OnInitDialog + UI populate + set current fields //fs
	RunTime::ResetMemoryContentAt(0x5823B8, &CPropertyBuildingExt::PreTranslateMessageExt); //fs
}

BOOL CPropertyBuildingExt::PreTranslateMessageExt(MSG* pMsg)
{
	switch (pMsg->message) {

	default:
		break;
	}
	return this->FA2CDialog::PreTranslateMessage(pMsg);
}

/*
DEFINE_HOOK(417780, CPropertyBuilding_OnInitDialog, 7) //fs
{
	GET(CPropertyBuildingExt*, pThis, ECX);
	R->EAX(pThis->CPropertyBuildingExt::OnInitDialogExt());
}
*/
// TODO
// CACO TRY THIS, IT'S EASY
// Hook/Rewrite OnInitDialog
// 
// Powerups stupid error
// Houses Reader
//
// You can have a look on CScriptTypesExt as a reference
//
//BOOL CPropertyBuildingExt::OnInitDialogExt()
//{
//	if (!this->FA2CDialog::OnInitDialog())
//		return FALSE;
//
//	// INITIALIZE WORKS
//
//	return TRUE;
//}
//
//DEFINE_HOOK(417F40, CPropertyBuilding_OnInitDialog, 7)
//{
//	GET(CPropertyBuildingExt*, pThis, ECX);
//	R->EAX(pThis->CPropertyBuildingExt::OnInitDialogExt());
//
//	return 0x41A4AE;
//}