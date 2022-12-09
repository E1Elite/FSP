#pragma once

// #include "Helpers/CompileTime.h"
#include "FA2PP.h"

// #include "CMixFile.h"

// Forward Definations
class INIClass;
class Palette;
/* // Not used currently, needs FS mapping
struct ExpandMixStruct
{
	int Parent;
	int Ecache01;
	int Conquer;
	int Local;
	int IsoSnowmd;
	int IsoTempmd;
	int IsoUrbmd;
	int IsoGen;
	int IsoLun;
	int IsoDes;
	int IsoUbn;
	int IsoGenmd;
	int IsoLunmd;
	int IsoDesmd;
	int IsoUbnmd;
	int Temperatmd;
	int Snowmd;
	int Urbanmd;
	int Lunarmd;
	int Urbannmd;
	int Desertmd;
	int Genericmd;
	int Temmd;
	int Snomd;
	int Urbmd;
	int Ubn;
	int Lun;
	int Des;
	int Unknown;
	int Marblemd;
};
*/
class NOVTABLE CLoading : public FA2CDialog
{
public:
	CLoading() = default;

	// static constexpr constant_ptr<CLoading, 0x7DCF40> Instance{}; //fs

	CLoading(CWnd* pParentWnd) { JMP_THIS(0x471DC0); } //fs

	//Returns : The index of mixfile in the global array, 0 for not found.
	//pTheaterType:
	// 0 : Not a specific theater
	// 1 - 6 : TEM SNO URB UBN LUN DES
	int SearchFile(const char* pName, char* pTheaterType = nullptr) { JMP_THIS(0x4846C0); } //fs
	void LoadTSINI(const char* pFile, INIClass* pINI, BOOL bMerge) { JMP_THIS(0x47A1C0); } //fs
	void GetSHPValidRange(unsigned char* pData, int Width, int Height, int* OutBegin, 
		int* OutEnd, BOOL bUnknown = FALSE, int* pUnknown = nullptr) // Last one is realtived to tmp drawing
		{ JMP_THIS(0x48EF70); } //fs

	void Release() { JMP_THIS(0x48BE00); } //fs

/* // Not used currently, needs FS mapping
	int GetPaletteISO()
	{
		switch (this->TheaterIdentifier)
		{
		case 'A':
			return this->PAL_ISOSNO;
		case 'T':
		default:
			return this->PAL_ISOTEM;
		}
	}
	int GetPaletteUnit()
	{
		switch (this->TheaterIdentifier)
		{
		case 'A':
			return this->PAL_UNITSNO;
		case 'T':
		default:
			return this->PAL_UNITTEM;
		}
	}
	int GetPaletteTheater()
	{
		switch (this->TheaterIdentifier)
		{
		case 'A':
			return this->PAL_SNOW;
		case 'T':
		default:
			return this->PAL_TEMPERAT;
		}
	}
	CString GetFileExtension()
	{
		switch (this->TheaterIdentifier)
		{
		case 'A':
			return ".sno";
		case 'T':
		default:
			return ".tem";
		}
	}
	Palette* GetPalette(int id)
	{
		if (id == PAL_UNITTEM || id == PAL_UNITSNO)
			return (Palette*)(0x71A3D4); //fs
		if (id == PAL_ISOTEM || id == PAL_ISOSNO)
			return (Palette*)(0x71A7D4); //fs
		if (id == PAL_TEMPERAT || id == PAL_SNOW)
			return (Palette*)(0x719BD4); //fs
		return nullptr;
	}
	void* ReadWholeFile(const char* filename, DWORD* pDwSize = nullptr);
	bool HasFile(CString filename);
	void SetTheaterLetter(CString& string)
	{
		if (this->TheaterIdentifier != 0)
		{
			char f = string[0], s = string[1];
			if (f >= 'A' && f <= 'Z')	f += ' ';
			if (s >= 'A' && s <= 'Z')	s += ' ';
			if ((f == 'g' || f == 'n' || f == 'c') && (s == 'a' || s == 't'))
				string.SetAt(1, this->TheaterIdentifier);
		}
	}
	void SetGenericTheaterLetter(ppmfc::CString& string)
	{
		string.SetAt(1, 'A');
	}

	//member properties
	char TheaterIdentifier; // T, A(SNOW), U, N, D, L
	//align 3 bytes
	CStatic CSCVersion;
	CStatic CSCBuiltby;
	CStatic CSCLoading;
	CProgressCtrl CPCProgress;
	int Unknown_150;
	int Unknown_154;
	int PAL_ISOTEM; // index in the array at 0x7DCCE4 //fs BytePalette[]
	int PAL_ISOSNO;
	int PAL_ISOURB;
	int PAL_UNITTEM;
	int PAL_UNITSNO;
	int PAL_UNITURB;
	int PAL_TEMPERAT;
	int PAL_SNOW;
	int PAL_URBAN;
	int PAL_LIB_ID2124019542;
	int PAL_LUNAR;
	int PAL_DESERT;
	int PAL_URBANN;
	int PAL_ISOLUN;
	int PAL_ISODES;
	int PAL_ISOUBN;
	int PAL_UNITLUN;
	int PAL_UNITDES;
	int PAL_UNITUBN;
	int MIX_LOCAL;
	int MIX_SNO;
	int MIX_TEM;
	int MIX_URB;
	int MIX_LUN;
	int MIX_DES;
	int MIX_UBN;
	int MIX_RA2;
	int MIX_GENERIC;
	ExpandMixStruct ExpandMixes[101];
	int ECacheMixes[100];
	int MIX_ISOTEM;
	int MIX_ISOSNO;
	int MIX_ISOURB;
	int MIX_ISOGEN;
	int MIX_ISOLUN;
	int MIX_ISODES;
	int MIX_ISOUBN;
	int MIX_TEMPRAT;
	int MIX_SNOW;
	int MIX_URBAN;
	int MIX_URBANN;
	int MIX_LUNAR;
	int MIX_DESERT;
	int MIX_CACHE;
	int MIX_CONQUER;
	int MIX_LANGUAGE;
	int MIX_LANGMD;
	int MIX_MARBLE;
	int Unknown_32F8;
*/
	virtual void __thiscall DoDataExchange(CDataExchange* pDX) override
	{
		JMP_STD(0x471FF0); //fs
	}
};