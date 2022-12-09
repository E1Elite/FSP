#include <Helpers/Macro.h>
#include <GlobalVars.h>

#include "../FA2sp.h"
#include "../Logger.h"

// FA2 will no longer automatically change the extension of map
/*
DEFINE_HOOK(42703A, CFinalSunDlg_SaveMap_Extension, 9)
{
    return 0x42708D;
}
*/

// Make FA2 use path stored in FinalAlert.ini instead of Reg
DEFINE_HOOK(41F62A, CFinalSunDlg_GetFilePath_1, 6) //fs
{
    return 0x41F630; //fs
}

DEFINE_HOOK(41F67B, CFinalSunDlg_GetFilePath_2, 6) //fs
{
    return 0x41F689; //fs
}

// Disable Spawn House support in case 
// UseMPSpawnHouses is set to no for dropdowns
// in Aircraft, Unit, Infantry, Building and TeamTypes.
DEFINE_HOOK(43FAF6, HouseCombo_YRCheck_1, 8) //fs
{
	if (!ExtConfigs::UseMPSpawnHouses)
	    return 0x43FC3F; //fs
    return 0x43FAFE; //fs
}

DEFINE_HOOK(4401F3, HouseCombo_YRCheck_2, 8) //fs
{
	if (!ExtConfigs::UseMPSpawnHouses)
	    return 0x44029F; //fs
    return 0x4401FB; //fs
}

DEFINE_HOOK(440341, HouseCombo_YRCheck_3, 8) //fs
{
	if (!ExtConfigs::UseMPSpawnHouses)
	    return 0x4403E8; //fs
    return 0x440349; //fs
}

