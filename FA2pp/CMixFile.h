#pragma once

#include "FA2PP.h"

#include "XCC/mix_file.h"

class CMixFile
{
public:
    static int __cdecl Open(const char* pName, int nParentMix) { JMP_STD(0x5178A0); } //fs
    static bool __cdecl HasFile(const char* pName, int nMix) { JMP_STD(0x517AA0); } //fs
/*
	static bool __cdecl ExtractFile(const char* pName, const char* pPath, int nMix) { JMP_STD(0x5257D0) }
    static bool __cdecl LoadSHP(const char* pName, int nMix) { JMP_STD(0x525C50); }

    static Cmix_file* ID2File(int nMix) { return (Cmix_file*)((char*)(0x8204F0 + 72 * nMix)); }
*/
};