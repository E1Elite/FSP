#pragma once

#include <WinUser.h>

#include "ppmfc_ccmdtarget.h"

_PPMFC_BEGIN

// forward declarations
class COleDropTarget;
class CCreateContext;
class CString;
class CFrameWnd;
class CDC;
class COleControlSite;
class CHandleMap;

_PPMFC_CLASS(CWnd) _PPMFC_INHERIT(CCmdTarget)
{
public:
    CWnd() _PPMFC_THISCALL(0x543361); //fs
    CWnd(HWND hWnd) _PPMFC_THISCALL(0x54339F); //fs
    ~CWnd() _PPMFC_THISCALL(0x543E3C); //fs

    LRESULT PASCAL SendMessage(UINT Msg, WPARAM wParam, LPARAM lParam) const
        { return ::SendMessage(this->m_hWnd, Msg, wParam, lParam); }

    CWnd* GetOwner() const
        _PPMFC_THISCALL(0x524190); //fs

    BOOL EnableToolTips(BOOL bEnable = TRUE)
        _PPMFC_THISCALL(0x541AB5); //fs

    void FilterToolTipMessage(MSG * pMsg)
        _PPMFC_THISCALL(0x541B45); //fs

    BOOL CreateDlg(LPCTSTR lpszTemplateName, CWnd * pParentWnd)
        _PPMFC_THISCALL(0x542B3C); //fs

    BOOL CreateDlgIndirect(LPCDLGTEMPLATE lpDialogTemplate, CWnd * pParentWnd,
        HINSTANCE hInst)
        _PPMFC_THISCALL(0x542B80); //fs

    static BOOL PASCAL ModifyStyle(HWND hWnd, DWORD dwRemove, DWORD dwAdd,
        UINT nFlags)
        _PPMFC_STDCALL(0x54341A); //fs

    static BOOL PASCAL ModifyStyleEx(HWND hWnd, DWORD dwRemove, DWORD dwAdd,
        UINT nFlags)
        _PPMFC_STDCALL(0x543434); //fs

    static const MSG* PASCAL GetCurrentMessage()
        _PPMFC_STDCALL(0x5436B4); //fs

    LRESULT Default()
        _PPMFC_THISCALL(0x5436E9); //fs

    static CWnd* PASCAL FromHandle(HWND hWnd)
        _PPMFC_STDCALL(0x543782); //fs

    BOOL Attach(HWND hWndNew)
        _PPMFC_THISCALL(0x5437C7); //fs

    HWND Detach()
        _PPMFC_THISCALL(0x543800); //fs

    BOOL CreateEx(DWORD dwExStyle, LPCTSTR lpszClassName,
        LPCTSTR lpszWindowName, DWORD dwStyle,
        const RECT & rect,
        CWnd * pParentWnd, UINT nID,
        LPVOID lpParam = NULL)
        _PPMFC_THISCALL(0x543CC3); //fs

    BOOL CreateEx(DWORD dwExStyle, LPCTSTR lpszClassName,
        LPCTSTR lpszWindowName, DWORD dwStyle,
        int x, int y, int nWidth, int nHeight,
        HWND hWndParent, HMENU nIDorHMenu, LPVOID lpParam = NULL)
        _PPMFC_THISCALL(0x543D0A); //fs

    virtual BOOL PreCreateWindow(CREATESTRUCT & cs)
        _PPMFC_STDCALL(0x543DD0); //fs

    virtual BOOL Create(LPCTSTR lpszClassName,
        LPCTSTR lpszWindowName, DWORD dwStyle,
        const RECT & rect,
        CWnd * pParentWnd, UINT nID,
        CCreateContext * pContext = NULL)
        _PPMFC_THISCALL(0x543DF0); //fs

    void OnDestroy()
        _PPMFC_THISCALL(0x543EB8); //fs

    void OnNcDestroy()
        _PPMFC_THISCALL(0x543ED6); //fs

    virtual void OnFinalRelease()
        _PPMFC_THISCALL(0x543FE8); //fs

    virtual BOOL DestroyWindow()
        _PPMFC_THISCALL(0x543FF9); //fs

    virtual LRESULT DefWindowProc(UINT nMsg, WPARAM wParam, LPARAM lParam)
        _PPMFC_THISCALL(0x544046); //fs

    virtual BOOL PreTranslateMessage(MSG * pMsg)
        _PPMFC_THISCALL(0x544091); //fs

    static void PASCAL CancelToolTips(BOOL bKeys = FALSE)
        _PPMFC_STDCALL(0x5440B0); //fs

    virtual int OnToolHitTest(CPoint point, TOOLINFO * pTI) const
        _PPMFC_THISCALL(0x544107); //fs

    void GetWindowText(CString & rString) const
        _PPMFC_THISCALL(0x544178); //fs

    void OnDrawItem(int nIDCtl, LPDRAWITEMSTRUCT lpDrawItemStruct)
        _PPMFC_THISCALL(0x5441C0); //fs

    int OnCompareItem(int nIDCtl, LPCOMPAREITEMSTRUCT lpCompareItemStruct)
        _PPMFC_THISCALL(0x5441FD); //fs

    void OnDeleteItem(int nIDCtl, LPDELETEITEMSTRUCT lpDeleteItemStruct)
        _PPMFC_THISCALL(0x544227); //fs

    void OnMeasureItem(int nIDCtl, LPMEASUREITEMSTRUCT lpMeasureItemStruct)
        _PPMFC_THISCALL(0x5442D5); //fs

    LRESULT OnNTCtlColor(WPARAM wParam, LPARAM lParam)
        _PPMFC_THISCALL(0x5444A2); //fs

    virtual void WinHelp(DWORD dwData, UINT nCmd = HELP_CONTEXT)
        _PPMFC_THISCALL(0x5444E8); //fs

    virtual LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam)
        _PPMFC_THISCALL(0x544610); //fs

    virtual BOOL OnWndMsg(UINT message, WPARAM wParam, LPARAM lParam, LRESULT* pResult)
        _PPMFC_THISCALL(0x544654); //fs

    virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam)
        _PPMFC_THISCALL(0x544BF0); //fs

    virtual BOOL OnNotify(WPARAM wParam, LPARAM lParam, LRESULT* pResult)
        _PPMFC_THISCALL(0x544C7C); //fs

    CFrameWnd* GetParentFrame() const
        _PPMFC_THISCALL(0x544CF6); //fs

    CWnd* GetTopLevelParent() const
        _PPMFC_THISCALL(0x544D79); //fs

    CWnd* GetParentOwner()
        _PPMFC_THISCALL(0x544DA1); //fs

    BOOL IsTopParentActive() const
        _PPMFC_THISCALL(0x544DE5); //fs

    void ActivateTopParent()
        _PPMFC_THISCALL(0x544E19); //fs

    CFrameWnd* GetTopLevelFrame() const
        _PPMFC_THISCALL(0x544E56); //fs

    int MessageBox(LPCTSTR lpszText, LPCTSTR lpszCaption = NULL,
        UINT nType = MB_OK)
        _PPMFC_THISCALL(0x544E97); //fs

    static CWnd* PASCAL GetDescendantWindow(HWND hWnd, int nID,
        BOOL bOnlyPerm)
        _PPMFC_STDCALL(0x544EC9); //fs

    static void PASCAL SendMessageToDescendants(HWND hWnd, UINT message,
        WPARAM wParam, LPARAM lParam, BOOL bDeep, BOOL bOnlyPerm)
        _PPMFC_STDCALL(0x544F42); //fs

    int SetScrollPos(int nPos, BOOL bRedraw = TRUE)
        _PPMFC_THISCALL(0x544FBF); //fs

    int GetScrollPos(int nBar) const
        _PPMFC_THISCALL(0x544FEF); //fs

    void SetScrollRange(int nBar, int nMinPos, int nMaxPos,
        BOOL bRedraw = TRUE)
        _PPMFC_THISCALL(0x545017); //fs  FA2 should be 0x553FD3

    void GetScrollRange(int nBar, LPINT lpMinPos, LPINT lpMaxPos) const
        _PPMFC_THISCALL(0x54504A); //fs

    void EnableScrollBarCtrl(int nBar, BOOL bEnable = TRUE)
        _PPMFC_THISCALL(0x54507A); //fs

    BOOL SetScrollInfo(int nBar, LPSCROLLINFO lpScrollInfo,
        BOOL bRedraw = TRUE)
        _PPMFC_THISCALL(0x5450BD); //fs

    BOOL GetScrollInfo(int nBar, LPSCROLLINFO lpScrollInfo, UINT nMask = SIF_ALL)
        _PPMFC_THISCALL(0x54510A); //fs

    int GetScrollLimit(int nBar)
        _PPMFC_THISCALL(0x545157); //fs

    void ScrollWindow(int xAmount, int yAmount,
        LPCRECT lpRect = NULL,
        LPCRECT lpClipRect = NULL)
        _PPMFC_THISCALL(0x54519E); //fs

    enum RepositionFlags
        { reposDefault = 0, reposQuery = 1, reposExtra = 2 };
    void RepositionBars(UINT nIDFirst, UINT nIDLast, UINT nIDLeftOver,
        UINT nFlag = reposDefault, LPRECT lpRectParam = NULL,
        LPCRECT lpRectClient = NULL, BOOL bStretch = TRUE)
        _PPMFC_THISCALL(0x545244); //fs

    enum AdjustType { adjustBorder = 0, adjustOutside = 1 };
    virtual void CalcWindowRect(LPRECT lpClientRect,
        UINT nAdjustType = adjustBorder)
        _PPMFC_THISCALL(0x545418); //fs

    static BOOL PASCAL WalkPreTranslateTree(HWND hWndStop, MSG* pMsg)
        _PPMFC_STDCALL(0x545443); //fs

    BOOL SendChildNotifyLastMsg(LRESULT* pResult = NULL)
        _PPMFC_THISCALL(0x545485); //fs

    static BOOL PASCAL ReflectLastMsg(HWND hWndChild, LRESULT* pResult = NULL)
        _PPMFC_STDCALL(0x5454B2); //fs

    virtual BOOL OnChildNotify(UINT message, WPARAM wParam, LPARAM lParam, LRESULT* pResult)
        _PPMFC_THISCALL(0x545556); //fs

    BOOL ReflectChildNotify(UINT message, WPARAM wParam, LPARAM lParam, LRESULT* pResult)
        _PPMFC_THISCALL(0x5455B1); //fs

    void OnParentNotify(UINT message, LPARAM lParam)
        _PPMFC_THISCALL(0x545699); //fs

    LRESULT OnActivateTopLevel(WPARAM wParam, LPARAM lParam)
        _PPMFC_THISCALL(0x5456C6); //fs

    void OnSysColorChange()
        _PPMFC_THISCALL(0x5456E8); //fs

    void OnSettingChange(UINT uFlags, LPCTSTR lpszSection)
        _PPMFC_THISCALL(0x545765); //fs

    void OnDevModeChange(LPTSTR lpDeviceName)
        _PPMFC_THISCALL(0x5457B8); //fs

    BOOL OnHelpInfo(HELPINFO* lpHelpInfo)
        _PPMFC_THISCALL(0x545803); //fs

    LRESULT OnDisplayChange(WPARAM, LPARAM)
        _PPMFC_THISCALL(0x545867); //fs

    LRESULT OnDragList(WPARAM, LPARAM)
        _PPMFC_THISCALL(0x5458B0); //fs

    void OnEnterIdle(UINT nWhy, CWnd* pWho)
        _PPMFC_THISCALL(0x5458FB); //fs

    HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
        _PPMFC_THISCALL(0x545945); //fs

    HBRUSH OnGrayCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
        _PPMFC_THISCALL(0x54596C); //fs

    static BOOL PASCAL GrayCtlColor(HDC hDC, HWND hWnd, UINT nCtlColor,
        HBRUSH hbrGray, COLORREF clrText)
        _PPMFC_STDCALL(0x5459CF); //fs

    LRESULT OnQuery3dControls(WPARAM, LPARAM)
        _PPMFC_THISCALL(0x545A44); //fs

    BOOL UpdateData(BOOL bSaveAndValidate = TRUE)
        _PPMFC_THISCALL(0x545A4C); //fs

    void CenterWindow(CWnd* pAlternateOwner = NULL)
        _PPMFC_THISCALL(0x545B04); //fs

    BOOL ExecuteDlgInit(LPCTSTR lpszResourceName)
        _PPMFC_THISCALL(0x545CB9); //fs

    BOOL ExecuteDlgInit(LPVOID lpResource)
        _PPMFC_THISCALL(0x545D09); //fs

    void UpdateDialogControls(CCmdTarget* pTarget, BOOL bDisableIfNoHndler)
        _PPMFC_THISCALL(0x545DDB); //fs

    BOOL PreTranslateInput(LPMSG lpMsg)
        _PPMFC_THISCALL(0x545EE0); //fs

    int RunModalLoop(DWORD dwFlags = 0)
        _PPMFC_THISCALL(0x545F10); //fs

    virtual BOOL ContinueModal()
        _PPMFC_THISCALL(0x54606F); //fs

    virtual void EndModalLoop(int nResult)
        _PPMFC_THISCALL(0x546076); //fs

    BOOL SubclassWindow(HWND hWnd)
        _PPMFC_THISCALL(0x546428); //fs

    virtual BOOL OnAmbientProperty(COleControlSite* pSite, DISPID dispid,
        VARIANT* pvar)
        _PPMFC_THISCALL(0x546992); //fs

    CWnd* GetDlgItem(int nID) const
        _PPMFC_THISCALL(0x5469A9); //fs

    void GetDlgItem(int nID, HWND* phWnd) const
        _PPMFC_THISCALL(0x5469D3); //fs

    void SetDlgItemText(int nID, LPCTSTR lpszString)
        _PPMFC_THISCALL(0x546A01); //fs

    BOOL IsDialogMessage(LPMSG lpMsg)
        _PPMFC_THISCALL(0x546A30); //fs

    DWORD GetStyle() const
        _PPMFC_THISCALL(0x546A63); //fs

    DWORD GetExStyle() const
        _PPMFC_THISCALL(0x546A7D); //fs

    BOOL ModifyStyle(DWORD dwRemove, DWORD dwAdd, UINT nFlags = 0)
        _PPMFC_THISCALL(0x546A97); //fs

    BOOL ModifyStyleEx(DWORD dwRemove, DWORD dwAdd, UINT nFlags = 0)
        _PPMFC_THISCALL(0x546AC8); //fs

    void SetWindowText(LPCTSTR lpszString)
        _PPMFC_THISCALL(0x546AF9); //fs

    int GetWindowText(LPTSTR lpszStringBuf, int nMaxCount) const
        _PPMFC_THISCALL(0x546B20); //fs

    int GetDlgCtrlID() const
        _PPMFC_THISCALL(0x546B4F); //fs

    int SetDlgCtrlID(int nID)
        _PPMFC_THISCALL(0x546B6A); //fs

    BOOL SetWindowPos(const CWnd* pWndInsertAfter, int x, int y,
        int cx, int cy, UINT nFlags)
        _PPMFC_THISCALL(0x546B93); //fs

    BOOL ShowWindow(int nCmdShow)
        _PPMFC_THISCALL(0x546BE2); //fs

    BOOL IsWindowEnabled() const
        _PPMFC_THISCALL(0x546C09); //fs

    BOOL EnableWindow(BOOL bEnable = TRUE)
        _PPMFC_THISCALL(0x546C24); //fs

    CWnd* SetFocus()
        _PPMFC_THISCALL(0x546C4B); //fs

    void AttachControlSite(CHandleMap* pMap)
        _PPMFC_THISCALL(0x546C6C); //fs

    void AttachControlSite(CWnd* pWndParent)
        _PPMFC_THISCALL(0x546CA9); //fs

    void ScreenToClient(LPRECT lpRect) const
        _PPMFC_THISCALL(0x549E9E); //fs

    void ClientToScreen(LPRECT lpRect) const
        _PPMFC_THISCALL(0x549EDA); //fs

    static CWnd* PASCAL GetSafeOwner(CWnd* pParent = NULL, HWND* pWndTop = NULL)
        _PPMFC_STDCALL(0x54C079); //fs

    void OnHelp()
        _PPMFC_THISCALL(0x551181); //fs

    static CWnd* _PPMFC_API CreateObject()
        _PPMFC_STDCALL(0x55668F); //fs

    CWnd* GetWindow(UINT nCmd) const
        { ASSERT(::IsWindow(m_hWnd)); return CWnd::FromHandle(::GetWindow(m_hWnd, nCmd)); }

    int GetWindowTextLength() const
        { ASSERT(::IsWindow(m_hWnd)); return ::GetWindowTextLength(m_hWnd); }

    BOOL LockWindowUpdate()    // for backward compatibility
        { ASSERT(::IsWindow(m_hWnd)); return ::LockWindowUpdate(m_hWnd); }
    void UnlockWindowUpdate()
        { ASSERT(::IsWindow(m_hWnd)); ::LockWindowUpdate(NULL); }

public:
    HWND m_hWnd;
    HWND m_hWndOwner;
    UINT m_nFlags;
    WNDPROC m_pfnSuper;
    int m_nModalResult;
    COleDropTarget* m_pDropTarget;
    void* m_pCtrlCont;
    void* m_pCtrlSite;
};

_PPMFC_END