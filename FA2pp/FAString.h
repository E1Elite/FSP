#pragma once

#include "Helpers/ASMMacros.h"

// A Helper Class For CString
// For safer memory writing
class FAString
{
public:
    void AssignCopy(size_t size, const char* src)
    {
        JMP_THIS(0x54705F); //fs
    }

    static void Assignment(CString& des, const char* src)
    {
        FAString* ptr = (FAString*)&des;
        ptr->AssignCopy(strlen(src) + 1, src);
    }

    FAString(LPCWSTR lpWideCharStr)
    {
        JMP_THIS(0x547013); //fs
    }

    FAString(LPCSTR lpCharStr)
    {
        JMP_THIS(0x546FC1); //fs
    }

    void DTOR()
    {
        JMP_THIS(0x546F53); //fs
    }

    static int Format(char* buffer, const char* format, ...)
    {
        JMP_STD(0x525726); //fs
    }

    operator CString()
    {
        return real;
    }

    operator const char* ()
    {
        return real;
    }

private:
    CString real;
};