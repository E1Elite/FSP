#include <Helpers/Macro.h>
#include <GlobalVars.h>

#include "../../Logger.h"

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
