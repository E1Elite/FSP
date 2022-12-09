#include "Body.h"
#include "../../FA2sp.h"

#include <GlobalVars.h>
#include <CINI.h>

#include <Windows.h>

//DEFINE_HOOK(470A66, DEBUGGGGASD, 7)
//{
//	// DEBUG USE
//
//	auto dbgmap = reinterpret_cast<FAMap<CString, CString, 0x5D8CD0, 0>*>(0x72A870);
//	Logger::Debug("dbgmap size = %d\n", dbgmap->size());
//	for (auto& x : *dbgmap)
//	{
//		Logger::Debug("%s\n", x.first);
//	}
//	return 0;
//}
/*
DEFINE_HOOK(452DC6, CIsoView_StatusBar_YXTOXY_YToX_1, 7) //fs
{
	GET_STACK(int, nPointX, 0x30);
	R->EDI(nPointX);
	R->ECX(R->lea_Stack<DWORD>(0x458));
	return 0x452DCD; //fs
}

DEFINE_HOOK(452DE4, CIsoView_StatusBar_YXTOXY_YToX_2, 7) //fs
{
	GET_STACK(int, nPointY, 0x38);
	R->EDI(nPointY);
	return 0;
}

DEFINE_HOOK(452E07, CIsoView_StatusBar_YXTOXY_XToY_1, 7) //fs
{
	GET_STACK(int, nPointY, 0x38);
	R->EBX(nPointY);
	R->EAX(R->lea_Stack<DWORD>(0x458));
	return 0x452E0E; //fs
}

DEFINE_HOOK(452E1A, CIsoView_StatusBar_YXTOXY_XToY_2, 7) //fs
{
	GET_STACK(int, nPointX, 0x30);
	R->EBX(nPointX);
	return 0;
}

// Fix on wrong infantry facing
DEFINE_HOOK(473E46, CIsoView_UpdatePaint_InfantryFacing, 9)
{
	GET(int, Facing, EAX);
	R->EAX(7 - Facing / 32);
	R->ECX(R->lea_Stack<DWORD>(0x590));
	return 0x473E52;
}
*/
DEFINE_HOOK(464806, CIsoView_UpdateOverlay_AutoConnect_1, 5) //fs
{
	// static int __stdcall sub_461790(int Y, int X); //fs
	int X = R->EBX();
	int Y = R->EBP();
	PUSH_VAR32(X);
	PUSH_VAR32(Y);
	CALL(0x461790); //fs
	return 0x464843; //fs
}

DEFINE_HOOK(4616D9, CIsoView_UpdateOverlay_AutoConnect_2, 8) //fs
{
	GET(unsigned char, nOverlayIndex, ESI);
	GET(bool, bConnectAsWall, ECX);
	if (bConnectAsWall)
		return 0x4616E1; //fs
	if (nOverlayIndex >= 0 && nOverlayIndex < 255)
	{
		auto& rules = GlobalVars::INIFiles::Rules();
		CString key;
		key.Format("%d", nOverlayIndex);
		auto pRegName = rules.GetString("OverlayTypes", key, "");
		bool bWall = rules.GetBool(pRegName, "Wall", false);
		if (bWall)
			return 0x4616E1; //fs
	}
	return 0x461777; //fs
}

DEFINE_HOOK(451E36, CIsoView_Draw_CopySelectionBoundColor, 6) //fs
{
	R->Stack<COLORREF>(0x0, ExtConfigs::CopySelectionBound_Color);
	return 0;
}

DEFINE_HOOK(452C47, CIsoView_Draw_CursorSelectionBoundColor, 5) //fs
{
	R->Stack<COLORREF>(0x0, ExtConfigs::CursorSelectionBound_Color);
	return 0;
}

DEFINE_HOOK(452C96, CIsoView_Draw_CursorSelectionBoundHeightColor, 6) //fs
{
	R->Stack<COLORREF>(0x8, ExtConfigs::CursorSelectionBound_HeightColor);
	return 0;
}

DEFINE_HOOK(46CAAC, CIsoView_Draw_WaypointColor, 5) //fs
{
	GET(CIsoView*, pThis, EBX); //fs
	GET(int, X, ESI);
	GET(int, Y, EDI);
	GET_STACK(CString, s, STACK_OFFS(0xD30, 0xCE0)); //fs

	pThis->DrawText(X + 12, Y + 6, s, ExtConfigs::Waypoint_Color); //fs

	return 0x46CACA; //fs
}

DEFINE_HOOK(4603CA, CIsoView_DrawText, 9) //fs
{
	if (ExtConfigs::Waypoint_Background)
	{
		GET(HDC, hdc, EDX);

		SetBkColor(hdc, ExtConfigs::Waypoint_Background_Color);
		SetBkMode(hdc, OPAQUE);

		return 0x4603D3; //fs
	}
	return 0;
}

