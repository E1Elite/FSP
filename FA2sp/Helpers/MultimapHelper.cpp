/*
* NOTICE
* Implement of this class could be really composite and
* hard to understand. Not only to other users, but for me
* as well, so why not just use it as it's easy to call 
* rather than understand how it works, isn't it?
* 
* UPDATE ON 3/31/2021
* "I cannot understand this one either now." - secsome
*/

#include "MultimapHelper.h"
#include "STDHelpers.h"

#include <set>

MultimapHelper::MultimapHelper(std::initializer_list<INIClass*> list)
{
    for (auto pINI : list)
        data.push_back(pINI);
}

void MultimapHelper::AddINI(INIClass* pINI)
{
    data.push_back(pINI);
}

INIClass* MultimapHelper::GetINIAt(int idx)
{
    return data.at(idx);
}

CString MultimapHelper::GetString(const char* pSection, const char* pKey, const char* pDefault)
{
    for (auto& ini : data)
    {
        if (!ini->KeyExists(pSection, pKey))
            continue;
        return ini->GetString(pSection, pKey, pDefault);
    }
    return pDefault;
}

int MultimapHelper::GetInteger(const char* pSection, const char* pKey, int nDefault) {
    CString& pStr = this->GetString(pSection, pKey, "");
    int ret = 0;
    if (sscanf_s(pStr, "%d", &ret) == 1)
        return ret;
    return nDefault;
}

bool MultimapHelper::GetBool(const char* pSection, const char* pKey, bool nDefault) {
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

std::vector<CString> MultimapHelper::ParseIndicies(const char* pSection, bool bParseIntoValue)
{
    std::vector<CString> ret;
    std::map<unsigned int, CString> tmp;
    std::map<CString, unsigned int> tmp2;
    std::map<CString, CString> tmp3; // Value - Key
    std::map<unsigned int, INIClass*> belonging;

    for (auto& pINI : data)
    {
        if (pINI)
        {
            auto& cur = pINI->ParseIndiciesData(pSection);
            for (auto& pair : cur)
            {
                CString value = pINI->GetString(pSection, pair.second, pair.second);
                auto& unitr = tmp2.find(value);
                if (unitr == tmp2.end())
                {
                    belonging[tmp2.size()] = pINI;
                    tmp2[value] = tmp2.size();
                }
                else
                {
                    belonging[unitr->second] = pINI;
                }
                tmp3[value] = pair.second;
            }
        }
    }
    
    for (auto& pair : tmp2)
        tmp[pair.second] = pair.first;

    ret.resize(tmp.size());
    size_t idx = 0;
    for (auto& x : tmp)
        ret[idx++] = x.second;

    if (!bParseIntoValue)
        for (size_t i = 0, sz = ret.size(); i < sz; ++i)
            ret[i] = tmp3[ret[i]];

    return ret;
}

std::map<CString, CString, INISectionEntriesComparator> MultimapHelper::GetSection(const char* pSection)
{
    std::map<CString, CString, INISectionEntriesComparator> ret;
    int index = 0;
    CString tmp;
    for (auto& pINI : data)
        if (pINI)
            if (auto section = pINI->GetSection(pSection))
            {
                for (auto& pair : section->EntitiesDictionary)
                {
                    if (STDHelpers::IsNullOrEmpty(pair.first) ||
                        STDHelpers::IsNullOrEmpty(pair.second) ||
                        pair.first == "Name")
                    {
                        ++index;
                        continue;
                    }
                    tmp.Format("%d", index++);
                    ret[tmp] = pair.second;
                }
            }         
    return ret;
}