#include "Body.h"

#include "../../FA2sp.h"

void CFinalSunDlgExt::ProgramStartupInit()
{
	auto addr = &CFinalSunDlgExt::PreTranslateMessageExt;
	RunTime::ResetMemoryContentAt(0x583818, &addr, 4); //fs

}

BOOL CFinalSunDlgExt::PreTranslateMessageExt(MSG* pMsg)
{
	switch (pMsg->message)
	{
	case WM_INITDIALOG:
		;
		///*SetWindowTheme(*this, L"DarkMode_Explorer", NULL);*/
	}
	return FA2CDialog::PreTranslateMessage(pMsg);
}