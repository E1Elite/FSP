#include "CObjectSearch.h"

#include <GlobalVars.h>

#include "../../Helpers/STDHelpers.h"
#include "../../FA2sp.h"

HWND CObjectSearch::m_hwnd;
CFinalSunDlg* CObjectSearch::m_parent;

BOOL CObjectSearch::JumpToCoord(CWnd* pWnd, int X, int Y)
{
    struct HelperView : public CView
    {
    public:
        int sub_465178(int a2, int a3) //fs
            { JMP_THIS(0x465178); } //fs
    };

    if (pWnd)
    {
        //HelperView* pIsoView = reinterpret_cast<HelperView*>(m_parent + 0x2158);
        HelperView* pIsoView = reinterpret_cast<HelperView*>(pWnd);
        int nHW = GlobalVars::CurrentMapWidthPlusHeight();
        int nParam = X + Y * nHW;
        RECT rect;
        ::GetWindowRect(pIsoView->GetSafeHwnd(), &rect);
        int v6 = (60 * (nParam % nHW)) / 4
            + (30 * (nParam / nHW)) / 2
            - 30
            * *(unsigned __int8*)(((nParam % nHW
                + nParam / nHW * nHW) << 6)
                + *reinterpret_cast<DWORD*>(0x79BCC8) //fs
                + 51)
            / 2;
        pIsoView->sub_465178( //fs
            30 * (nHW + (nParam / nHW)) - (rect.right - rect.left) / 2 - (30 * (nParam % nHW)) - rect.left,
            v6 - (rect.bottom - rect.top) / 2 - rect.top
        );
        return ::RedrawWindow(pIsoView->GetSafeHwnd(), 0, 0, 0x101);
    }
    return FALSE;
}

//DEFINE_HOOK(46E3B0, sub_46E3B0, 6) //fs
//{
//    GET(CWnd*, pWnd, ECX);
//    GET(int, nWP, EAX);
//    auto& doc = GlobalVars::INIFiles::CurrentDocument();
//    CString lpWaypoint;
//    lpWaypoint.Format("%d", nWP);
//    int nCoord = doc.GetInteger("Waypoints", lpWaypoint, -1);
//    if (lpWaypoint == -1)
//        return 0;
//    R->EAX(CObjectSearch::JumpToCoord(pWnd, GET_COORD_X(nCoord), GET_COORD_Y(nCoord)));
//
//    return 0x46E4A9; //fs
//}