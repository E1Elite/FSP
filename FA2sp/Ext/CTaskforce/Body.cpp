#include "Body.h"

void CTaskForceExt::ProgramStartupInit()
{
    RunTime::ResetMemoryContentAt(0x5869C8 + 0x4, &RunTime::Messages::EDIT_KILLFOCUS, 4); // name update //fs
    RunTime::ResetMemoryContentAt(0x5869B0 + 0x4, &RunTime::Messages::EDIT_KILLFOCUS, 4); // member count update //fs
    RunTime::ResetMemoryContentAt(0x586A58 + 0x4, &RunTime::Messages::EDIT_KILLFOCUS, 4); // group update //fs
    RunTime::ResetMemoryContentAt(0x5869E0 + 0x4, &RunTime::Messages::COMBOBOX_KILLFOCUS, 4); // member type update //fs

    RunTime::ResetMemoryContentAt(0x586B18, &CTaskForceExt::PreTranslateMessageExt); //fs
}

BOOL CTaskForceExt::PreTranslateMessageExt(MSG* pMsg)
{
    switch (pMsg->message)
    {
        case WM_KEYDOWN:
        {
            switch (pMsg->wParam)
            {
            case VK_RETURN:
            {
                if (pMsg->hwnd == this->CCBMemberType.GetWindow(GW_CHILD)->m_hWnd)
                    this->OnCBMemberTypeEditChanged();

                switch (::GetDlgCtrlID(pMsg->hwnd)) {
                case 1010: {this->OnETCurrentTaskforceEditChanged(); break; }
                case 1148: {this->OnETMemberCountEditChanged(); break; }
                case 1149: {this->OnETGroupEditChanged(); break; }
                default: break;
                }
            }
            return TRUE;

            default:
                break;
            }
        }


    }

    return this->FA2CDialog::PreTranslateMessage(pMsg);
}
