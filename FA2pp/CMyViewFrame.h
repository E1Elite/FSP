#pragma once

#include "FA2PP.h"

#include "CWndView.h"
#include "CIsoView.h"

class ObjectBrowserControl : public CTreeCtrl
{
public:
    void Update() { JMP_THIS(0x50FC00); } //fs
};

// Don't know what it should be called.
class CMyRightView : public FA2CWnd
{
    char gap[128];
    CSplitterWnd CSplitter;
};

class CMyViewFrame : public FA2CFrameWnd
{
public:
    CWndView Minimap;
    CStatusBar StatusBar;
    ObjectBrowserControl* pObjectBrowserControl;
    CIsoView* pIsoView;
    CSplitterWnd SplitterWnd;
    CTileSetBrowserView* pTileSetBrowserView;
    CMyRightView* pMyRightView;

    BOOL OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext)
    {
        JMP_THIS(0x4C6EF0); //fs
    }
};