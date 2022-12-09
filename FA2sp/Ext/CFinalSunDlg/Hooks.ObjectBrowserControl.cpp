#include "Body.h"

#include <FA2PP.h>
#include <Helpers/Macro.h>
#include <GlobalVars.h>

#include "../../FA2sp.h"

DEFINE_HOOK(50FC00, ObjectBrowserControl_Redraw, 7) //fs
{
    if (ExtConfigs::BrowserRedraw)
    {
        GET(ObjectBrowserControlExt*, pThis, ECX);
        pThis->Redraw();
        return 0x5158BE; //fs
    }
    return 0;
}

// Add a house won't update indices, so there might be hidden risks if not reloading the map.
// That's why these hooks are not used.
/*
DEFINE_HOOK_AGAIN(40A59B, CINIEditor_Update, 6) //fs
DEFINE_HOOK_AGAIN(4466DC, CHouses_ONBNDeleteHouseClicked_UpdateTreeview, 7) //fs 
DEFINE_HOOK(445EE0, CHouses_ONBNAddHouseClicked_UpdateTreeview, 7) //fs
{
    GlobalVars::Dialogs::CFinalSunDlg->MyViewFrame.pObjectBrowserControl->Update();
    return 0;
}
*/

//DEFINE_HOOK(50DE98, ObjectBrowserControl_OnSelectedChanged, 6) //fs
//{
//    GET_STACK(ObjectBrowserControlExt*, pThis, 0x10);
//    GET(int, nData, ECX);
//    return pThis->UpdateEngine(nData);
//}

//void PrintNode(CTreeCtrl* pTree, HTREEITEM hNode)
//{
//    static int depth = 0;
//    if (pTree->ItemHasChildren(hNode))
//    {
//        HTREEITEM hNextItem;
//        HTREEITEM hChildItem = pTree->GetChildItem(hNode);
//
//        while (hChildItem != NULL)
//        {
//            CString spaces;
//            for (int i = 0; i < depth; ++i)
//                spaces += "    ";
//            Logger::Debug("%s%s %d\n", spaces, pTree->GetItemText(hChildItem), pTree->GetItemData(hChildItem));
//            if (pTree->ItemHasChildren(hChildItem))
//            {
//                ++depth;
//                PrintNode(pTree, hChildItem);
//                --depth;
//            }
//            hNextItem = pTree->GetNextItem(hChildItem, TVGN_NEXT);
//            hChildItem = hNextItem;
//        }
//    }
//}
//
//DEFINE_HOOK(515884, ObjectBrowserControl_Redraw_End, 5) //fs
//{
//    GET(CTreeCtrl*, pTree, ESI);
//    auto hRoot = pTree->GetSelectedItem();
//    
//    PrintNode(pTree, hRoot);
//    
//    return 0;
//}