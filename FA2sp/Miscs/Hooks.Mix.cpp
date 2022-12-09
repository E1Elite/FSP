#include <Helpers/Macro.h>

DEFINE_HOOK(51A0E5, MixFile_Open_CheckTD, 7) //fs
{
    return 0x51A10B; //fs
}

DEFINE_HOOK(51A33E, MixFile_Open_CheckRAUnencrypted, 5) //fs
{
    return 0x51A38E; //fs
}

DEFINE_HOOK(51A0E5, MixFile_Open_CheckRAEncrypted, 6) //fs same address 2 hooks!
{
    return 0x51A274; //fs
}

#include <GlobalVars.h>
#include <CMixFile.h>
#include <set>

std::vector<int> ExtraMixes;

DEFINE_HOOK(48421A, CLoading_InitMixFiles_ExtraMix, 7) //fs
{
	ExtraMixes.clear();
	CString path = GlobalVars::ExePath();
	path += "\\mix\\extra";
	CString fullname;

	for (int i = 99; i >= 0; --i)
	{
		fullname.Format("%s%02d.mix", path, i);
		if (auto id = CMixFile::Open(fullname, 0))
		{
			ExtraMixes.push_back(id);
		}
	}
	
	return 0;
}

DEFINE_HOOK(4846C0, CLoading_SearchFile_ExtraMix, 6) //fs
{
	GET_STACK(const char*, pName, 0x4);

	for (auto& id : ExtraMixes)
	{
		if (CMixFile::HasFile(pName, id))
		{
			R->EAX(id);
			return 0x484C48; //fs
		}
	}

	return 0;
}

