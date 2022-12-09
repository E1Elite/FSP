#include <Helpers/Macro.h>
#include <GlobalVars.h>

#include <MFC/ppmfc_include.h>
#include "../Helpers/STDHelpers.h"

struct ColorTuple
{
	unsigned char a, b, c;
};

constexpr ColorTuple HsvToRgb(ColorTuple const hsv) noexcept {
	if (hsv.b == 0u) {
		return { hsv.c, hsv.c, hsv.c };
	}

	unsigned char region = hsv.a / 43;
	unsigned char remainder = (hsv.a - (region * 43)) * 6;

	unsigned char p = (hsv.c * (255 - hsv.b)) >> 8;
	unsigned char q = (hsv.c * (255 - ((hsv.b * remainder) >> 8))) >> 8;
	unsigned char t = (hsv.c * (255 - ((hsv.b * (255 - remainder)) >> 8))) >> 8;

	switch (region) {
	case 0:
		return { hsv.c, t, p };
	case 1:
		return { q, hsv.c, p };
	case 2:
		return { p, hsv.c, t };
	case 3:
		return { p, q, hsv.c };
	case 4:
		return { t, p, hsv.c };
	default:
		return { hsv.c, p, q };
	}
}

DEFINE_HOOK(46088E, sub_460530_RGBColor, 5) //fs
{
	REF_STACK(ppmfc::CString, name, STACK_OFFS(0xA4, 0x94));

	INIClass& rules = GlobalVars::INIFiles::Rules;

	if (strlen(name) <= 0) 
		name = "White";
	auto pValue = rules.GetString("Colors", name);
	if (STDHelpers::IsNullOrEmpty(pValue))
		pValue = "0,0,255";
	ColorTuple hsv{};
	if (sscanf_s(pValue, "%hhu,%hhu,%hhu",
		&hsv.a, &hsv.b, &hsv.c) == 3	)
	{
		auto const rgb = HsvToRgb(hsv);
		name.~CString();
		R->EAX<unsigned int>(rgb.a | rgb.b << 8u | rgb.c << 16u);
		return 0x460B42; //fs
	}
	return 0;
}
