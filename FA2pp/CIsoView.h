#pragma once

#include "FA2PP.h"

#include <ddraw.h>

// Forward declarations
class CMyViewFrame;

class CIsoView : public FA2CView
{
public:
    static int GetCoordX(int nCoord) { return nCoord % 1000; }
    static int GetCoordY(int nCoord) { return nCoord / 1000; }
    static int GetCoord(int X, int Y) { return X * 1000 + Y; }

    void MoveToWP(UINT nWaypoint) { JMP_THIS(0x46E3B0); } //fs
    void MoveTo(int X, int Y) { JMP_THIS(0x46E100); } //fs
    void MoveToCoord(int X, int Y) 
    {
        // Main code from CIsoView::MoveToWP
        int nHW = *reinterpret_cast<DWORD*>(0x71BB10); // fs // CurrentMapWidthPlusHeight, we don't want too much headers included.
        int nParam = X + Y * nHW;
        RECT rect;
        this->GetWindowRect(&rect);
        int v6 = (48 * (nParam % nHW)) / 4
            + (24 * (nParam / nHW)) / 2
            - 24
            * *(unsigned __int8*)(((nParam % nHW
                + nParam / nHW * nHW) << 6)
                + *reinterpret_cast<DWORD*>(0x79BCC8) //fs
                + 51)
            / 2;
        this->MoveTo(
            24 * (nHW + (nParam / nHW)) - (rect.right - rect.left) / 2 - (24 * (nParam % nHW)) - rect.left,
            v6 - (rect.bottom - rect.top) / 2 - rect.top
        );
        this->RedrawWindow(nullptr, nullptr, RDW_INVALIDATE | RDW_UPDATENOW);
    }

    void DrawText(int X, int Y, LPCSTR lpString, COLORREF color) { JMP_THIS(0x4603A0); } //fs
    void Draw() { JMP_THIS(0x465A70); } //fs
    void PrimarySurfaceLost() { JMP_THIS(0x460E40); } //fs
    void BltToBackBuffer(LPDIRECTDRAWSURFACE7 lpSrcSurface, int X, int Y, int W, int H) { JMP_THIS(0x46CF30); } //fs
    
    void AfterUpdate(BOOL bSomeValidate) { JMP_THIS(0x44EAF0); } //fs

    void DrawCellOutline(int X, int Y,int someDeltaX,int someDeltaY,COLORREF color,BOOL bDot,BOOL bDrawOnPrimarySurface)
        { JMP_THIS(0x4618D0); } //fs

    void UpdateStatusBar(int X, int Y) { JMP_THIS(0x461AE0); } //fs
    void UpdateSurfaceLayer(int X, int Y, int unused) { JMP_THIS(0x4638F0); } //fs

    int MouseCellY; // Which cell does the mouse at now
    int MouseCellX; // Which cell does the mouse at now
    int Unknown_48;
    int Unknown_4C;
    int Unknown_50;
    int Unknown_54;
    int Unknown_58;
    CPoint ViewPosition; // where the view center at
    CPoint MoveCenterPosition; // where right button down
    int Unknown_6C;
    int Unknown_70;
    BOOL IsScrolling;
    int Unknown_78;
    int Unknown_7C;
    int Unknown_80;
    int Unknown_84;
    int Unknown_88;
    int Unknown_8C;
    int Unknown_90;
    int Unknown_94;
    CMyViewFrame* pParent;
    LPDIRECTDRAWSURFACE7 lpDDBackBufferSurface;
    LPDIRECTDRAWSURFACE7 lpDDTempBufferSurface;
    LPDIRECTDRAWSURFACE7 lpDDPrimarySurface;
    IDirectDraw7* lpDD7;
    LPDIRECTDRAW lpDirectDraw;
    int Unknown_B0;
    CMenu Menu;
    BOOL IsInitializing;
    RECT Rect_C0;
    int Unknown_CC;
    int Unknown_D0;
    int Unknown_D4;
    int Unknown_D8;
    int Unknown_DC;
    int Unknown_E0;
    int Unknown_E4;
    int Unknown_E8;
    int Unknown_EC;
};