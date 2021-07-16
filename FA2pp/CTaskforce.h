#pragma once

#include "FA2PP.h"

class NOVTABLE CTaskForce : public FA2CDialog
{
public:
	void OnCBCurrentTaskforceEditChanged()
	{
		JMP_THIS(0x4CD470); //fs ?? just return?
	}
	void OnCBCurrentTaskforceSelectChanged()
	{
		JMP_THIS(0x4D6F90); //fs
	}
	void OnLBMembersSelectChanged()
	{
		JMP_THIS(0x4D7460); //fs
	}
	void OnBNDeleteMemberClicked()
	{
		JMP_THIS(0x4D7880); //fs
	}
	void OnETMemberCountEditChanged()
	{
		JMP_THIS(0x4D7CF0); //fs
	}
	void OnETCurrentTaskforceEditChanged()
	{
		JMP_THIS(0x4D80F0); //fs
	}
	void OnCBMemberTypeEditChanged()
	{
		JMP_THIS(0x4D8390); //fs
	}
	void OnCBMemberTypeSelectChanged()
	{
		JMP_THIS(0x4D8730); //fs
	}
	void OnBNAddMemberClicked()
	{
		JMP_THIS(0x4D8A90); //fs
	}
	void OnBNDeleteTaskforceClicked()
	{
		JMP_THIS(0x4D8E50); //fs
	}
	void OnBNAddTaskforce()
	{
		JMP_THIS(0x4D92A0); //fs
	}
	void OnETGroupEditChanged()
	{
		JMP_THIS(0x4D9740); //fs
	}

	//member properties
	CComboBox		CCBMemberType;
	CListBox		CLBMembers;
	CComboBox		CCBCurrentTaskforce;
	CString			CString_Group;
	CString			CString_Name;
	CString			CString_Num;
};