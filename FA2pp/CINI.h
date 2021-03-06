#pragma once

#include "FA2PP.h"
#include "FAString.h"
#include "Structures/FAMap.h"

#include "MFC/ppmfc_cstring.h"

#include <vector>
#include <map>

// We can only use C++14 standard for now since our FATree & FAMap
// was a mess, and higher standards are more strict and we cannot
// pass the complie for some reason.
// secsome - 2020/11/3

// Remember that we cannot call CTOR or DTOR for any FAMap/FATree
// cause nil & nilrefs haven't been analysed yet.
// Consider to use : auto& iRules = GlobalVars::INIFiles::Rules();

// Forward Definations
class INISection;
class INIClass;

class INISectionEntriesComparator
{
public:
	static bool __stdcall __compare(CString* a1, CString* a2) { JMP_STD(0x449E90); }  //fs

	bool operator()(const CString& s1, const CString& s2) const
	{
		return __compare((CString*)&s1, (CString*)&s2);
	}
};

// type definations
using INIDict = FAMap<CString, INISection, 0x5C7BD4, 0>; //fs
using INIStringDict = FAMap<const char*, const char*, 0x5C7BD0, 0x5C7BCC, INISectionEntriesComparator>; //fs
using INIIndiceDict = FAMap<const char*, unsigned int, 0x5C7BC8, 0x5C7BC4, INISectionEntriesComparator>; //fs

struct FAINIMap
{
public:
	std::pair<INIDict::iterator, bool>*
		insert(std::pair<INIDict::iterator, bool>* ret, std::pair<CString, INISection>* section)
	{
		JMP_THIS(0x4026E0); //fs
	}
};
struct FAINIEntriesMap
{
public:
	std::pair<INIStringDict::iterator, bool>*
		insert(std::pair<INIStringDict::iterator, bool>* ret, std::pair<const char*, const char*>* pair)
	{
		JMP_THIS(0x409FE0); //fs
	}
};

class CSFQuery 
{
private:
	static constexpr DWORD _H = 0x71BB08; //fs
	struct _S
	{
		const wchar_t* QueryUIName(const char* pRegName) {
			JMP_THIS(0x4A9EF0); //fs
		}
	};

public:
	static CString GetUIName(const char* pRegName)
	{
		_S* _X = (_S*)_H;
		auto wstr = _X->QueryUIName(pRegName);
		char* value = nullptr;
		auto len = wcslen(wstr);
		int valueBufferSize = WideCharToMultiByte(CP_ACP, NULL, wstr, len, value, 0, NULL, NULL) + 1;
		value = new char[valueBufferSize];
		WideCharToMultiByte(CP_ACP, NULL, wstr, len, value, valueBufferSize, NULL, NULL);
		value[valueBufferSize - 1] = '\0';
		CString ret = value;
		delete[] value;
		return ret;
	}
};

class INIMapFieldUpdate
{
private:
	static constexpr DWORD _H = 0x71BB08; //fs
	struct _S
	{
		static void UpdateMapFieldData(int flag)
			{ JMP_THIS(0x493B80); } //fs
	};
	
public:
	static INIClass* UpdateMapFieldData(int flag)
	{
		_S* _X = (_S*)_H;
		_X->UpdateMapFieldData(flag);
		return reinterpret_cast<INIClass*>(0x79BB90); //fs
	}
};

class INISection {
public:
	INISection() { JMP_THIS(0x44A4E0); } //fs
	INISection(INISection& another) { JMP_THIS(0x4021D0); } //fs
	~INISection() { JMP_THIS(0x44A780); } //fs

private:
	void* vftable_align; // for align
public:
	INIStringDict EntitiesDictionary;
	INIIndiceDict IndicesDictionary;
};

class INIClass
{
private:
	// ~INIClass() { JMP_THIS(0x44A440); } //fs

private:
	void* vftable_align; // for align
public:
	INIDict Dict; // no idea about the nilrefs
	char Path[MAX_PATH];

	static ppmfc::CString* GetAvailableIndex(ppmfc::CString* ret)
		{ JMP_STD(0x441040); } //fs

	static ppmfc::CString* GetAvailableKey(ppmfc::CString* ret,const char* pSection)
		{ JMP_STD(0x4917B0); } //fs

public:
	std::pair<INIDict::iterator, bool> InsertSection(CString pSection, INISection& section)
	{
		std::pair<CString, INISection> ins = std::make_pair(pSection, section);
		std::pair<INIDict::iterator, bool> ret;
		FAINIMap* mapptr = reinterpret_cast<FAINIMap*>(&Dict);
		mapptr->insert(&ret, &ins);
		return ret;
	}

	std::pair<INIStringDict::iterator, bool> InsertPair(INIStringDict& dict, const char* pKey, const char* pValue)
	{
		FAINIEntriesMap* ptrmap = reinterpret_cast<FAINIEntriesMap*>(&dict);
		std::pair<ppmfc::CString, ppmfc::CString> ins = std::make_pair(pKey, pValue);
		std::pair<INIStringDict::iterator, bool> ret;
		ptrmap->insert(&ret, reinterpret_cast<std::pair<const char*, const char*>*>(&ins));
		return ret;
	}

	static ppmfc::CString GetAvailableIndex()
	{
		ppmfc::CString ret;
		GetAvailableIndex(&ret);
		return ret;
	}

	static ppmfc::CString GetAvailableKey(const char* pSection)
	{
		ppmfc::CString ret;
		GetAvailableKey(&ret, pSection);
		return ret;
	}

	static INIClass* GetMapDocument(bool bUpdateMapField = false)
	{
		if(bUpdateMapField)
			INIMapFieldUpdate::UpdateMapFieldData(1);
		return reinterpret_cast<INIClass*>(0x79BB90); //fs
	}

	int GetKeyCount(const char* pSection)
	{
		auto itr = Dict.find(pSection);
		if (itr != Dict.end())
			return itr->second.EntitiesDictionary.size();
		return 0;
	}

	CString GetKeyName(const char* pSection, int nIndex)
	{
		auto itr = Dict.find(pSection);
		if (itr != Dict.end())
		{
			auto& EntriesMap = itr->second.EntitiesDictionary;
			auto result = EntriesMap.begin();
			int idx = 0;
			while (result != EntriesMap.end())
			{
				if (idx == nIndex)
					return result->first;
				++idx;
				++result;
			}
		}
		return "";
	}

	bool SectionExists(const char* pSection)
	{
		return Dict.find(pSection) != Dict.end();
	}
	
	bool KeyExists(const char* pSection, const char* pKey)
	{
		if (auto section = GetSection(pSection))
			return section->EntitiesDictionary.find(pKey) != section->EntitiesDictionary.end();
		return false;
	}

	// Something is wrong.
	// Might blow FA2 up (for most times kek)
	// I might remake it some times later
	bool WriteString(const char* pSection, const char* pKey, const char* pValue)
	{
		auto itr = Dict.find(pSection);
		if (itr == Dict.end())	return false;
		auto& dict = itr->second.EntitiesDictionary;
		auto pair = InsertPair(dict, pKey, pValue);
		if (!pair.second)
			((ppmfc::CString*) & pair.first->second)->AssignCopy(strlen(pValue), pValue);
		return true;
	}

	INISection* GetSection(const char* pSection)
	{
		auto itr = Dict.find(pSection);
		if (itr != Dict.end())
			return &itr->second;
		return nullptr;
	}

	CString GetString(const char* pSection, const char* pKey, const char* pDefault = "") {
		auto itrSection = Dict.find(pSection);
		if (itrSection != Dict.end()) {
			auto pEntries = &itrSection->second.EntitiesDictionary;
			auto itrKey = pEntries->find(pKey);
			if (itrKey != pEntries->end())
				return itrKey->second;
		}
		return pDefault;
	}

	int GetInteger(const char* pSection, const char* pKey, int nDefault = 0) {
		CString& pStr = this->GetString(pSection, pKey, "");
		int ret = 0;
		if (sscanf_s(pStr, "%d", &ret) == 1)
			return ret;
		return nDefault;
	}

	float GetSingle(const char* pSection, const char* pKey, float nDefault = 0) {
		CString& pStr = this->GetString(pSection, pKey, "");
		float ret = 0;
		if (sscanf_s(pStr, "%f", &ret) == 1)
			return ret;
		return nDefault;
	}

	double GetDouble(const char* pSection, const char* pKey, double nDefault = 0) {
		CString& pStr = this->GetString(pSection, pKey, "");
		double ret = 0;
		if (sscanf_s(pStr, "%lf", &ret) == 1)
			return ret;
		return nDefault;
	}

	bool GetBool(const char* pSection, const char* pKey, bool nDefault = false) {
		CString& pStr = this->GetString(pSection, pKey, "");
		switch (toupper(static_cast<unsigned char>(*pStr)))
		{
		case '1':
		case 'T':
		case 'Y':
			return true;
		case '0':
		case 'F':
		case 'N':
			return false;
		default:
			return nDefault;
		}
	}

	COLORREF GetColor(const char* pSection, const char* pKey, COLORREF nDefault = 0xFFFFFF) {
		CString& pStr = this->GetString(pSection, pKey, "");
		struct { byte R, G, B, Zero; } ret;
		ret.Zero = 0;
		if (sscanf_s(pStr, "%hhu,%hhu,%hhu", &ret.R, &ret.G, &ret.B) == 3)
			return *reinterpret_cast<COLORREF*>(&ret);
		return nDefault;
	}

	std::map<unsigned int, CString> ParseIndiciesData(const char* pSection)
	{
		std::map<unsigned int, CString> ret;
		auto& section = Dict.find(pSection);
		if (section == Dict.end())
			return ret;
		std::map<unsigned int, CString> tmp;
		for (auto& ent : section->second.EntitiesDictionary)
		{
			auto& indexDict = section->second.IndicesDictionary;
			auto& idxitr = indexDict.find(ent.first);
			if (idxitr != indexDict.end())
				tmp[idxitr->second] = idxitr->first;
		}
		size_t idx = 0;
		for (auto& x : tmp)
			ret[idx++] = x.second;

		return ret;
	}
};