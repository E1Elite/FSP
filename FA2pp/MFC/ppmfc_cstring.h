#pragma once

#include "ppmfc_forward.h"

_PPMFC_BEGIN

_PPMFC_STRUCT(CStringData)
{
    long nRefs;     // reference count
    int nDataLength;
    int nAllocLength;
    // TCHAR data[nAllocLength]

    TCHAR* data()
    {
        return (TCHAR*)(this + 1);
    }
};

_PPMFC_CLASS(CString)
{
public:
    CString() _PPMFC_THISCALL(0x406F60); //fs
    CString(LPCTSTR lpch, int nLength) _PPMFC_THISCALL(0x540578); //fs
    CString(const CString & stringSrc) _PPMFC_THISCALL(0x546CC8); //fs
    CString(LPCSTR lpsz) _PPMFC_THISCALL(0x546FC1); //fs
    CString(LPCWSTR lpsz) _PPMFC_THISCALL(0x547013); //fs
    ~CString() _PPMFC_THISCALL(0x546F53); //fs

    CStringData* CString::GetData() const
        { ASSERT(m_pchData != NULL); return ((CStringData*)m_pchData) - 1; }
    int CString::GetLength() const
        { return GetData()->nDataLength; }
    int CString::GetAllocLength() const
        { return GetData()->nAllocLength; }
    BOOL CString::IsEmpty() const
        { return GetData()->nDataLength == 0; }

    const CString& operator=(TCHAR ch)
        _PPMFC_THISCALL(0x5405AC); //fs

    int Delete(int at, int length)
        _PPMFC_THISCALL(0x5405C1); //fs

    int Insert(int at, LPCSTR lpsz)
        _PPMFC_THISCALL(0x540619); //fs

    int Replace(LPCSTR from, LPCSTR to)
        _PPMFC_THISCALL(0x5406CE); //fs

    CString* Right(CString * stringMem, int at)
        _PPMFC_THISCALL(0x540831); //fs

    CString Right(int at)
        { CString ret; Right(&ret, at); return ret; }

    CString* Left(CString* stringMem, int at)
        _PPMFC_THISCALL(0x5408AD); //fs

    CString Left(int at)
        { CString ret; Left(&ret, at); return ret; }

    int ReverseFind(TCHAR ch) const
        _PPMFC_THISCALL(0x540925); //fs

    int Find(LPCTSTR lpszSub) const
        _PPMFC_THISCALL(0x540947); //fs

    int Find(LPCTSTR lpszSub, int from) const
        _PPMFC_THISCALL(0x540955); //fs

    void TrimRight()
        _PPMFC_THISCALL(0x540980); //fs

    void TrimLeft()
        _PPMFC_THISCALL(0x5409CC); //fs

    void Trim()
        { TrimLeft(); TrimRight(); }

    void AllocBuffer(int nLen)
        _PPMFC_THISCALL(0x546DC0); //fs

    void FreeData()
        _PPMFC_THISCALL(0x546E42); //fs

    void Release()
        _PPMFC_THISCALL(0x546E8A); //fs

    static void _PPMFC_API Release(CStringData* pStringData)
        _PPMFC_STDCALL(0x546EBB); //fs

    void Empty()
        _PPMFC_THISCALL(0x546EDE); //fs

    void CopyBeforeWrite()
        _PPMFC_THISCALL(0x546EFC); //fs

    void AllocBeforeWrite(int nLen)
        _PPMFC_THISCALL(0x546F2A); //fs

    void AllocCopy(CString& dest, int nCopyLen, int nCopyIndex, int nExtraLen) const
        _PPMFC_THISCALL(0x546F7D); //fs

    void AssignCopy(int nSrcLen, LPCTSTR lpszSrcData)
        _PPMFC_THISCALL(0x54705F); //fs

    const CString& operator=(CString& str)
        _PPMFC_THISCALL(0x54708C); //fs

    const CString& operator=(LPCSTR lpsz)
        _PPMFC_THISCALL(0x5470DC); //fs

    const CString& operator=(LPCWSTR lpsz)
        _PPMFC_THISCALL(0x547103); //fs

    void ConcatCopy(int nSrc1Len, LPCTSTR lpszSrc1Data, int nSrc2Len, LPCTSTR lpszSrc2Data)
        _PPMFC_THISCALL(0x547144); //fs

    friend CString _PPMFC_API operator+(const CString& string1,
        const CString& string2)
        _PPMFC_STDCALL(0x547182); //fs

    friend CString _PPMFC_API operator+(const CString& string, LPCTSTR lpsz)
        _PPMFC_STDCALL(0x5471E8); //fs

    friend CString _PPMFC_API operator+(LPCTSTR lpsz, const CString& string)
        _PPMFC_STDCALL(0x54725C); //fs

    void ConcatInPlace(int nSrcLen, LPCTSTR lpszSrcData)
        _PPMFC_THISCALL(0x5472D0); //fs

    const CString& operator+=(LPCTSTR lpsz)
        _PPMFC_THISCALL(0x54732F); //fs

    const CString& operator+=(TCHAR ch)
        _PPMFC_THISCALL(0x547356); //fs

    const CString& operator+=(const CString& string)
        _PPMFC_THISCALL(0x54736B); //fs

    LPTSTR GetBuffer(int nMinBufLength)
        _PPMFC_THISCALL(0x547383); //fs

    void ReleaseBuffer(int nNewLength = -1)
        _PPMFC_THISCALL(0x5473D2); //fs

    LPTSTR GetBufferSetLength(int nNewLength)
        _PPMFC_THISCALL(0x5473FA); //fs

    int Find(TCHAR ch) const
        _PPMFC_THISCALL(0x54741A); //fs

    int Find(TCHAR ch, int from) const
        _PPMFC_THISCALL(0x547428); //fs

    void MakeUpper()
        _PPMFC_THISCALL(0x547455); //fs

    void MakeLower()
        _PPMFC_THISCALL(0x547467); //fs

    void SetAt(int nIndex, TCHAR ch) // FA2 should be 0x556435
        _PPMFC_THISCALL(0x547479); //fs 

    BOOL LoadString(UINT nID)          // load from string resource, 255 chars max
        _PPMFC_THISCALL(0x54754B); //fs

    operator const char*() const
        { return m_pchData; }

    operator LPTSTR () const
        { return m_pchData; }

    bool operator< (const CString& another) const
        { return strcmp(this->m_pchData, another) < 0; }

    LPTSTR m_pchData;   // pointer to ref counted string data
public:
    // Extra implements not contained in FA2

    CString CString::Mid(int nFirst) const
    {
        return Mid(nFirst, GetData()->nDataLength - nFirst);
    }

    CString CString::Mid(int nFirst, int nCount) const
    {
        // out-of-bounds requests return sensible things
        if (nFirst < 0)
            nFirst = 0;
        if (nCount < 0)
            nCount = 0;

        if (nFirst + nCount > GetData()->nDataLength)
            nCount = GetData()->nDataLength - nFirst;
        if (nFirst > GetData()->nDataLength)
            nCount = 0;

        CString dest;
        AllocCopy(dest, nCount, nFirst, 0);
        return dest;
    }

};

//BOOL _PPMFC_API AfxExtractSubString(CString& rString, LPCTSTR lpszFullString,
//    int iSubString, TCHAR chSep = '\n')
//    _PPMFC_STDCALL(0x5475F6); //fs
//
//void _PPMFC_API AfxFormatStrings(CString& rString, UINT nIDS,
//    LPCTSTR const* rglpsz, int nString)
//    _PPMFC_STDCALL(0x55100B); //fs
//
//void _PPMFC_API AfxFormatStrings(CString& rString, LPCTSTR lpszFormat,
//    LPCTSTR const* rglpsz, int nString)
//    _PPMFC_STDCALL(0x551045); //fs
//
//void _PPMFC_API AfxFormatString1(CString& rString, UINT nIDS, LPCTSTR lpsz1)
//    _PPMFC_STDCALL(0x551144); //fs
//
//void _PPMFC_API AfxFormatString2(CString& rString, UINT nIDS,
//    LPCTSTR lpsz1, LPCTSTR lpsz2)
//    _PPMFC_STDCALL(0x55115B); //fs

_PPMFC_END