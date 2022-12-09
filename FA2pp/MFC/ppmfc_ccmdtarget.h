#pragma once

#include "ppmfc_forward.h"

_PPMFC_BEGIN

// forward declarations
class AFX_CMDHANDLERINFO;
class AFX_DISPMAP;
class AFX_EVENTSINKMAP;
class AFX_INTERFACEMAP;
class AFX_CONNECTIONMAP;
class AFX_OLECMDMAP;

_PPMFC_CLASS(CCmdTarget) _PPMFC_INHERIT(CObject)
{
public:
    CCmdTarget() _PPMFC_THISCALL(0x54647A); //fs
    ~CCmdTarget() _PPMFC_THISCALL(0x546494); //fs

    virtual BOOL OnCmdMsg(UINT nID, int nCode, void* pExtra,
        AFX_CMDHANDLERINFO * pHandlerInfo)
        _PPMFC_THISCALL(0x5465C6); //fs

    virtual HRESULT GetTypeLib(LCID lcid, LPTYPELIB * ppTypeLib)
        _PPMFC_THISCALL(0x5466DB); //fs

    static void BeginWaitCursor()
        _PPMFC_STDCALL(0x5466E3); //fs

    static void EndWaitCursor()
        _PPMFC_STDCALL(0x5466F8); //fs

    virtual const AFX_DISPMAP* GetDispatchMap() const
        _PPMFC_STDCALL(0x546713); //fs

    virtual const AFX_EVENTSINKMAP* GetEventSinkMap() const
        _PPMFC_STDCALL(0x546719); //fs

    virtual const AFX_INTERFACEMAP* GetInterfaceMap() const
        _PPMFC_STDCALL(0x54671F); //fs

    virtual void OnFinalRelease()
        _PPMFC_THISCALL(0x546725); //fs

    virtual const AFX_CONNECTIONMAP* GetConnectionMap() const
        _PPMFC_STDCALL(0x54675B); //fs

    virtual const AFX_OLECMDMAP* GetCommandMap()
        _PPMFC_STDCALL(0x546766); //fs

public:
    int m_dwRef;
    LPUNKNOWN m_pOuterUnknown;
    DWORD m_xInnerUnknown;
    XDispatch m_xDispatch;
    BOOL m_bResultExpected;
    XConnPtContainer m_xConnPtContainer;
};

_PPMFC_END