#pragma once

#include <CLighting.h>
#include "../FA2Expand.h"

class NOVTABLE CLightingExt : public CLighting
{
public:
	typedef BOOL(*FuncT_PTM)(MSG* pMsg);

	static CLighting* Instance;

	//hook function to replace in virtual function map
	BOOL PreTranslateMessageExt(MSG* pMsg);

	static void ProgramStartupInit();

	CLightingExt() {};
	~CLightingExt() {};

private:

};