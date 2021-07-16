#include "Body.h"

#include <GlobalVars.h>

#include "../../FA2sp.h"

DEFINE_HOOK(4E4EAB, CTileSetBrowserFrame_ReloadComboboxes_OverlayFilter, 11) //fs
{
    GET_STACK(int, overlayIdx, 0x10); //fs
    GET(CComboBox*, pComboBox, EBP); //fs
    GET(CString, name, ECX);
    if (overlayIdx < 255) // overlay >= 255 crashes FA2, so keep it safe.
    {
        name.Format("%03d (%s)", overlayIdx, name);
        int idx = pComboBox->AddString(name);
        pComboBox->SetItemData(idx, overlayIdx);
    }
    return 0x4E4EC7; //fs
}

