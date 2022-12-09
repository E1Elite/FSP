#include "Replacement.h"
#include "../FA2sp.Constants.h"

// should be fixed by hooks but using this to just make it works for now.
void Replacement::HexFixes() {
	
	auto UndoRedoExtend = [](unsigned char extendNum)
	{
		RunTime::ResetMemoryContentAt(0x4B33D0, &extendNum, sizeof extendNum); //fs
		RunTime::ResetMemoryContentAt(0x4B33E9, &extendNum, sizeof extendNum); //fs
		--extendNum;
		RunTime::ResetMemoryContentAt(0x4B33F3, &extendNum, sizeof extendNum); //fs
	};

	auto NoEasyMode = []()
	{
		unsigned char code[] = { 0x90,0x90,0xB0,0x00 };
		RunTime::ResetMemoryContentAt(0x42146E, code, sizeof code); //fs
	};
	
	UndoRedoExtend(128);
	NoEasyMode();

	return;
}