#pragma once

#include "../FA2sp.h"
#include "../Logger.h"

#include <FA2PP.h>

// Load our own accelerators
// Notice, our accelerator's id need to be the same as FA2's

/*
DEFINE_HOOK(41F39D, LoadAccelerators_CFinalSunApp_InitInstance, 7) //fs
{
    const HINSTANCE hInstance = static_cast<HINSTANCE>(FA2sp::hInstance);
    R->EAX<HINSTANCE>(hInstance);
    return 0;
}
*/

// Replace the resources

DEFINE_HOOK(55781A, FetchResource_CToolBar_LoadBitmapA, 6) //fs
{
    GET_STACK(LPCSTR, lpName, STACK_OFFS(0xC, -4));
    const LPCSTR lpType = RT_BITMAP;
    const HMODULE hModule = static_cast<HMODULE>(FA2sp::hInstance);
    if (HRSRC hResInfo = FindResource(hModule, lpName, lpType)) {
        HBITMAP hBitmap = AfxLoadSysColorBitmap(hModule, hResInfo, 0);
        R->EBX(hResInfo);
        R->ESI(hModule);
        return 0x557836; //fs
    }
    return 0;
}

DEFINE_HOOK(542B4B, FetchResource_Cwnd_CreateDlg, 6) //fs
{
    GET_STACK(LPCSTR, lpName, STACK_OFFS(0xC, -4));
    const LPCSTR lpType = RT_DIALOG;
    const HMODULE hModule = static_cast<HMODULE>(FA2sp::hInstance);
    if (HRSRC hResInfo = FindResource(hModule, lpName, lpType)) {
        if (HGLOBAL hResData = LoadResource(hModule, hResInfo)) {
            LockResource(hResData);
            R->EAX(hResData);
            return 0x542B6B; //fs
        }
    }
    return 0;
}

DEFINE_HOOK(542AC6, FetchResource_CDialog_Create, 5) //fs
{
    GET(LPCSTR, lpName, EBX);
    const LPCSTR lpType = RT_DIALOG;
    const HMODULE hModule = static_cast<HMODULE>(FA2sp::hInstance);
    if (HRSRC hResInfo = FindResource(hModule, lpName, lpType)) {
        if (HGLOBAL hResData = LoadResource(hModule, hResInfo)) {
            R->ESI(hModule);
            R->EAX(hResData);
            return 0x542ADB; //fs
        }
    }
    return 0;
}

DEFINE_HOOK(54318B, FetchResource_CDialog_CheckAutoCenter, 5) //fs
{
    const LPCSTR lpName = *(LPCSTR*)(R->EDI() + 0x40);
    const LPCSTR lpType = RT_DIALOG;
    const HMODULE hModule = static_cast<HMODULE>(FA2sp::hInstance);
    if (HRSRC hResInfo = FindResource(hModule, lpName, lpType)) {
        if (HGLOBAL hResData = LoadResource(hModule, hResInfo)) {
            R->EAX(hResInfo);
            R->EBX(hModule);
            return 0x54319F; //fs
        }
    }
    return 0;
}

DEFINE_HOOK(55775A, FetchResource_CToolBar_LoadToolBar, 5) //fs
{
    GET_BASE(LPCSTR, lpName, 0x8);
    const LPCSTR lpType = (LPCSTR)(0xF1);
    const HMODULE hModule = static_cast<HMODULE>(FA2sp::hInstance);
    if (HRSRC hResInfo = FindResource(hModule, lpName, lpType)) {
        if (HGLOBAL hResData = LoadResource(hModule, hResInfo)) {
            LockResource(hResData);
            R->ESI(hResData);
            return 0x557780; //fs
        }
    }
    return 0;
}

DEFINE_HOOK(542E9B, FetchResource_CDialog_DoModal, 5) //fs
{
    const LPCSTR lpName = *(LPCSTR*)(R->ESI() + 0x40);
    const LPCSTR lpType = RT_DIALOG;
    const HMODULE hModule = static_cast<HMODULE>(FA2sp::hInstance);
    if (HRSRC hResInfo = FindResource(hModule, lpName, lpType)) {
        if (HGLOBAL hResData = LoadResource(hModule, hResInfo)) {
            R->EBX(hModule);
            R->EDI(hResData);
            return 0x542EB1; //fs
        }
    }
    return 0;
}

DEFINE_HOOK(545CCE, FetchResource_Cwnd_ExecuteDlgInit, 5) //fs
{
    GET_STACK(LPCSTR, lpName, STACK_OFFS(0xC, -4));
    const LPCSTR lpType = (LPCSTR)(0xF0);
    const HMODULE hModule = static_cast<HMODULE>(FA2sp::hInstance);
    if (HRSRC hResInfo = FindResource(hModule, lpName, lpType)) {
        if (HGLOBAL hResData = LoadResource(hModule, hResInfo)) {
            LockResource(hResData);
            R->EDI(hResData);
            return 0x545CEE; //fs
        }
    }
    return 0;
}
/*
DEFINE_HOOK(42E641, FetchResource_CFrameWnd_Menu, 5) //fs
{
	if (HMENU hMenu = LoadMenu(static_cast<HINSTANCE>(FA2sp::hInstance), (LPCSTR)(0x81)))
	{
		R->EAX(hMenu);
		return 0x42E655; //fs
	}
	else
		return 0;
}
*/
//DEFINE_HOOK(5431EE, CDialog_OnCtlColor, 8) //fs
//{
//  GET(CDialog*, pThis, ECX);
//  GET_STACK(CDC*, pDC, 0x4);
//  GET_STACK(CWnd*, pWnd, 0x8);
//  GET_STACK(UINT, nCtlColor, 0xC);
//
//  switch (nCtlColor)
//  {
//  case CTLCOLOR_BTN:
//  case CTLCOLOR_EDIT:
//  case CTLCOLOR_LISTBOX:
//  case CTLCOLOR_MSGBOX:
//  case CTLCOLOR_SCROLLBAR:
//  case CTLCOLOR_MAX:
//      return 0;
//  case CTLCOLOR_STATIC:
//  {
//      return 0;
//      /*Logger::Debug("LINEED! res = %d\n", pDC->LineTo(5, 5));
//      RECT rect;
//      pWnd->GetClientRect(&rect);
//      Logger::Debug("Client Rect = %d %d %d %d\n", rect.left, rect.top, rect.right, rect.bottom);
//      pWnd->GetWindowRect(&rect);
//      Logger::Debug("Window Rect = %d %d %d %d\n", rect.left, rect.top, rect.right, rect.bottom);
//      Logger::Debug("HDC = %p\n", pDC->GetSafeHdc());
//      R->EAX<HBRUSH>((HBRUSH)GetStockObject(HOLLOW_BRUSH));
//      return 0x5431FF;*/ //fs
//  }
//  case CTLCOLOR_DLG:
//      pDC->MoveTo(0, 0);
//      pDC->SetBkMode(TRANSPARENT);
//      pDC->SetBkColor(RGB(124, 0, 0));
//      RECT rect;
//      pWnd->GetWindowRect(&rect);
//      pDC->LineTo(100, 100);
//      pDC->DrawText("NMSLLLL", &rect, DT_CALCRECT);
//      R->EAX<HBRUSH>((HBRUSH)GetStockObject(HOLLOW_BRUSH));
//      //R->EAX(CreateSolidBrush(RGB(0, 0, 0)));
//      return 0x5431FF; //fs
//  default:
//      return 0;
//  }
//}

// Customize Control Background Colors
/*
HBRUSH FA2sp::hBrush = NULL;
DEFINE_HOOK(545945, CWnd_OnCtlColor, 6) //fs
{
    GET(CWnd*, pThis, ECX);
    GET_STACK(CDC*, pDC, 0x4);
    GET_STACK(CWnd*, pWnd, 0x8);
    GET_STACK(UINT, nCtlColor, 0xC);

    switch (nCtlColor)
    {
    case CTLCOLOR_DLG:
    case CTLCOLOR_BTN:
    case CTLCOLOR_EDIT:
    case CTLCOLOR_LISTBOX:
    case CTLCOLOR_MSGBOX:
    case CTLCOLOR_SCROLLBAR:
    case CTLCOLOR_MAX:
    case CTLCOLOR_STATIC:

        //return 0x545969; //fs
    default:
        return 0;
    }
}

DEFINE_HOOK(5431EE, CDialog_OnCtlColor, 8) //fs dup above
{
    GET(CDialog*, pThis, ECX);
    GET_STACK(CDC*, pDC, 0x4);
    GET_STACK(CWnd*, pWnd, 0x8);
    GET_STACK(UINT, nCtlColor, 0xC);

    switch (nCtlColor)
    {
    case CTLCOLOR_DLG:
    case CTLCOLOR_BTN:
    case CTLCOLOR_EDIT:
    case CTLCOLOR_LISTBOX:
    case CTLCOLOR_MSGBOX:
    case CTLCOLOR_SCROLLBAR:
    case CTLCOLOR_MAX:
    case CTLCOLOR_STATIC:

        //return 0x5431FF; //fs
    default:
        return 0;
    }
}

DEFINE_HOOK(5504E2, CControlBar_OnCtlColor, 7) //fs
{
    GET(CControlBar*, pThis, ECX);
    GET_STACK(CDC*, pDC, 0x4);
    GET_STACK(CWnd*, pWnd, 0x8);
    GET_STACK(UINT, nCtlColor, 0xC);

    switch (nCtlColor)
    {
    case CTLCOLOR_DLG:
    case CTLCOLOR_BTN:
    case CTLCOLOR_EDIT:
    case CTLCOLOR_LISTBOX:
    case CTLCOLOR_MSGBOX:
    case CTLCOLOR_SCROLLBAR:
    case CTLCOLOR_MAX:
    case CTLCOLOR_STATIC:

        //return 0x550537; //fs
    default:
        return 0;
    }
}
*/