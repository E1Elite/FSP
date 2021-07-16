#pragma once

#include "FA2PP.h"

class NOVTABLE CScriptTypes : public FA2CDialog
{
public:
	CScriptTypes() = default;

	//member properties
	CEdit				CETDescription; // 92
	CStatic			CSTParameterOfSection; // 152
	CComboBox	CCBCurrentAction; // 212
	CComboBox	CCBCurrentScript; // 272
	CComboBox	CCBScriptParameter; // 332
	CListBox		CLBScriptActions; // 392
	CString			CString_ScriptName; // 452

public:

	BOOL OnInitDialog() override
	{
		JMP_THIS(0x4CD090); //fs
	}

	void DoDataExchange(CDataExchange* pDX)
	{
		JMP_THIS(0x4C9F50); //fs
	}

	void UpdateDialog()
	{
		JMP_THIS(0x425BD6); //fs
	}

	//
	// Controls
	//

	void OnCBCurrentScriptSelectChanged()
	{
		JMP_THIS(0x4CA520); //fs
	}

	void OnLBScriptActionsSelectChanged()
	{
		JMP_THIS(0x4CA870); //fs
	}

	void OnETScriptNameChanged()
	{
		JMP_THIS(0x4CAAE0); //fs
	}

	void OnCBCurrentActionEditChanged()
	{
		JMP_THIS(0x4CAD80); //fs
	}

	void OnCBCurrentActionSelectChanged()
	{
		JMP_THIS(0x4CB940); //fs
	}

	void OnCBScriptParameterEditChanged()
	{
		JMP_THIS(0x4CB9E0); //fs
	}

	void OnCBScriptParameterSelectChanged()
	{
		JMP_THIS(0x4CBDC0); //fs
	}

	void OnBNAddActionClicked()
	{
		JMP_THIS(0x4CBE30); //fs
	}

	void OnBNDeleteActionClicked()
	{
		JMP_THIS(0x4CC140); //fs
	}

	void OnBNAddScriptClicked()
	{
		JMP_THIS(0x4CC700); //fs
	}

	void OnBNDeleteScriptClicked()
	{
		JMP_THIS(0x4CCAA0); //fs
	}
};
