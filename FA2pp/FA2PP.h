#pragma once

#include <AFXWIN.H>
#include <AFXCMN.H>
#include <AFXEXT.H>
#include "FA2PPCore.h"

#include "MFC/ppmfc_include.h"

class LEPTON
{
public:
	LEPTON(int value) : Value{ value } {}
	int Value;
};

inline int Lepton_To_Pixel(LEPTON lepton)
{
	return (((int)(signed short)lepton.Value * 48) + (256 / 2) - ((lepton.Value < 0) ? (256 - 1) : 0)) / 256;
}

inline LEPTON Pixel_To_Lepton(int pixel)
{
	return (LEPTON)(((pixel * 256) + (48 / 2) - ((pixel < 0) ? (48 - 1) : 0)) / 48);
}

class NOVTABLE FA2PP
{
public:
	int UpdateDialogs(void* pThis)
	{
		return UpdateDialogs(pThis, 0, 0);
	}
	
private:
	int __thiscall UpdateDialogs(void* pThis, int a2, int a3)
	{
		JMP_THIS(0x425B00) //fs
	}
};

class NOVTABLE FA2CWnd : public CWnd
{
public:
	virtual BOOL PreTransateMessage(MSG* pMsg)
	{
		JMP_STD(0x544091); //fs
	}
};

class NOVTABLE FA2CDialog : public CDialog
{
public:
	//CWnd
	virtual BOOL DestroyWindow() override
	{
		JMP_THIS(0x543FF9); //fs
	}

	virtual BOOL UpdateData(BOOL bSaveAndValidate = TRUE)
	{
		JMP_THIS(0x545A4C); //fs
	}

	//CDialog
	virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam) override
	{
		JMP_THIS(0x544BF0); //fs
	}

	virtual BOOL OnInitDialog() override
	{
		JMP_THIS(0x5430EC); //fs
	}

	virtual BOOL PreTranslateMessage(MSG* pMsg) override
	{
		JMP_THIS(0x542927); //fs
	}

	virtual LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam) override
	{
		JMP_THIS(0x544610); //fs
	}

};

class NOVTABLE FA2CWinApp : public CWinApp
{

};

class NOVTABLE FA2CScrollView : public CScrollView
{
public:
	// Cwnd
	
};

class NOVTABLE FA2CView : public CView
{
public:
	// Cwnd
	virtual BOOL PreTransateMessage(MSG* pMsg)
	{
		JMP_STD(0x544091); //fs
	}
};

class NOVTABLE FA2CFrameWnd : public CFrameWnd
{
	virtual BOOL PreTransateMessage(MSG* pMsg)
	{
		JMP_STD(0x552D48); //fs
	}
};