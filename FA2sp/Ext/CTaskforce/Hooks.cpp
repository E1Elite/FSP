#include <Helpers/Macro.h>
#include "Body.h"

DEFINE_HOOK(4D8390, CTaskforce_OnCBMemberTypeEditChanged, 6) //fs
{
    GET(CTaskForce*, pThis, ECX);

    return pThis->CCBMemberType.GetWindowTextLength() ? 0 : 0x4D8729; //fs
}