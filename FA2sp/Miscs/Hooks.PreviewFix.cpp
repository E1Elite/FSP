#include <Helpers/Macro.h>

#include "../RunTime.h"

// FinalAlert 2 used a MapPreview buffer in CMapData::InitMinimap(0x4C3D40):
// memset(this->MapPreview, 0xFFu, previewHeight * stride);
// If we create a big map, it will probably corrupt all members following it, like all the INI datas
// 
// However, the buffer sizes only 0x40000
// As it is a bitmap and as how FA2 paint the minimap, the size a map takes is (2 * W * H + 3) / 4 * 3 bytes.
// 256 * 256 * 2 * 3 = 0x60000
// This is the preview buffer size we need instead of stupid FA2's 0x40000,
// which limited the map size to 209 * 209 at max
// (2 * 209 * 209 + 3) / 4 * 3 = 65523 (0xFFF3)
//
// Therefore we just need to replace this buffer and it will works fine

static char MapPreviewBuffer[0x60000];

#define DEFINE_REG_HELPER(to, from) \
void __declspec(naked) to##_##from() \
{ __asm {lea to, [MapPreviewBuffer + from]} }

#define DEFINE_ZERO_HELPER(to) \
void __declspec(naked) to##_##0() \
{ __asm {lea to, [MapPreviewBuffer]} }

namespace PreviewFixDetails
{
    // These two naked function both takes 6 bytes
    // So we can easily copy the op codes from them

    // original op code
    // XX XX (XX) 48 02 08 00

    DEFINE_ZERO_HELPER(esi);
    DEFINE_ZERO_HELPER(edi);
    DEFINE_ZERO_HELPER(edx);
    DEFINE_ZERO_HELPER(eax);
    DEFINE_ZERO_HELPER(ebp);
    DEFINE_ZERO_HELPER(ecx);
    DEFINE_REG_HELPER(esi, eax);
    DEFINE_REG_HELPER(ecx, eax);
    DEFINE_REG_HELPER(edx, eax);
    DEFINE_REG_HELPER(ebp, eax);
    DEFINE_REG_HELPER(eax, eax);
    DEFINE_REG_HELPER(ebx, eax);
    DEFINE_REG_HELPER(edi, eax);

    static constexpr byte NOP = 0x90;

    inline void DoZero(unsigned long addr, void* fn)
    {
        RunTime::ResetMemoryContentAt(addr - 2, fn, 6);
    }

    inline void DoReg(unsigned long addr, void* fn)
    {
        RunTime::ResetMemoryContentAt(addr - 3, fn, 6);
        RunTime::ResetMemoryContentAt(addr - 3 + 6, &NOP, 1);
    }
}

#undef DEFINE_ZERO_HELPER
#undef DEFINE_REG_HELPER

DEFINE_HOOK(527D09, ExeRun_PreviewFix, 9) //fs Program entry
{
    using namespace PreviewFixDetails;

    DoZero(0x416021, eax_0); //fs
    DoZero(0x455B56, eax_0); //fs
    DoZero(0x456255, eax_0); //fs
    DoZero(0x499CC0, eax_0); //fs
    DoZero(0x49AC5F, eax_0); //fs
    DoZero(0x49BDC2, eax_0); //fs
    DoZero(0x49CA2B, eax_0); //fs
    DoZero(0x49DB90, eax_0); //fs
    DoZero(0x49E313, eax_0); //fs
    DoZero(0x49F8B5, eax_0); //fs
    DoZero(0x4A046A, eax_0); //fs
    DoZero(0x4A0CE9, eax_0); //fs
    DoZero(0x4A156A, eax_0); //fs
    DoZero(0x4AC4B2, eax_0); //fs
    DoZero(0x4BA137, edi_0); //fs
    DoZero(0x4BA166, eax_0); //fs
    DoZero(0x4BDCC6, eax_0); //fs

    DoReg(0x416119, edi_eax); //fs
    DoReg(0x416126, ebx_eax); //fs
    DoReg(0x455C51, ebp_eax); //fs
    DoReg(0x455C5E, ebx_eax); //fs
	DoReg(0x45634E, ebp_eax); //fs
    DoReg(0x45635B, ecx_eax); //fs
    DoReg(0x499DC0, ebp_eax); //fs
    DoReg(0x499DCD, eax_eax); //fs
    DoReg(0x49AD6A, ebp_eax); //fs
    DoReg(0x49AD77, edi_eax); //fs
    DoReg(0x49BEB5, ebp_eax); //fs
    DoReg(0x49BEC2, eax_eax); //fs
    DoReg(0x49CB1E, ebp_eax); //fs
    DoReg(0x49CB2B, eax_eax); //fs
    DoReg(0x49DC83, ebp_eax); //fs
    DoReg(0x49DC90, eax_eax); //fs
    DoReg(0x49E410, ebp_eax); //fs
    DoReg(0x49E41D, eax_eax); //fs
    DoReg(0x49F9A8, ebp_eax); //fs
    DoReg(0x49F9B5, ebx_eax); //fs
    DoReg(0x4A055F, ebp_eax); //fs
    DoReg(0x4A056C, ebx_eax); //fs
    DoReg(0x4A0DD9, edi_eax); //fs
    DoReg(0x4A0DE6, eax_eax); //fs
    DoReg(0x4A165F, ebp_eax); //fs
    DoReg(0x4A166C, ebx_eax); //fs
    DoReg(0x4AC5AD, ebx_eax); //fs
    DoReg(0x4AC5BA, eax_eax); //fs
    DoReg(0x4B4CA3, esi_eax); //fs
    DoReg(0x4B4CB7, ebp_eax); //fs
    DoReg(0x4B53C1, esi_eax); //fs
    DoReg(0x4B53D5, edi_eax); //fs
    DoReg(0x4B5F2A, esi_eax); //fs
	DoReg(0x4B5F3E, edi_eax); //fs
    DoReg(0x4B6709, esi_eax); //fs
    DoReg(0x4B671D, edi_eax); //fs
    DoReg(0x4B7955, ebp_eax); //fs
    DoReg(0x4B7962, edi_eax); //fs
    DoReg(0x4B8A57, ebp_eax); //fs
    DoReg(0x4B8A64, eax_eax); //fs
    DoReg(0x4BDDC1, esi_eax); //fs
    DoReg(0x4BDDD5, edi_eax); //fs

    DoZero(0x4B4BA5, edi_0); //fs
    DoZero(0x4B52BA, esi_0); //fs
    DoZero(0x4B5E27, ebp_0); //fs
    DoZero(0x4B6604, ebp_0); //fs
    DoZero(0x4B7850, esi_0); //fs
    DoZero(0x4B8950, ecx_0); //fs

    return 0;
}