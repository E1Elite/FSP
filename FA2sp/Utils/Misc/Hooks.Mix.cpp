#include <Helpers/Macro.h>

DEFINE_HOOK(51A0E5, MixFile_Open_CheckTD, 7) //fs
{
    return 0x51A10B; //fs
}

DEFINE_HOOK(51A33E, MixFile_Open_CheckRAUnencrypted, 5) //fs
{
    return 0x51A38E; //fs
}

DEFINE_HOOK(51A0E5, MixFile_Open_CheckRAEncrypted, 6) //fs same address 2 hooks!
{
    return 0x51A274; //fs
}