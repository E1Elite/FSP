#pragma once

#include "FA2PP.h"
#include "Helpers/CompileTime.h"

struct BGRStruct 
{ 
    unsigned char B, G, R, Zero;
    bool operator< (const BGRStruct& rhs) const { return *(int*)this < *(int*)&rhs; }
    bool operator==(const BGRStruct& rhs) const { return *(int*)this == *(int*)&rhs; }
};

struct ColorStruct
{
    unsigned char red, green, blue;
};

class BytePalette
{
public:
    ColorStruct Data[256];

    ColorStruct& operator[](int index) { return Data[index]; }
};

class Palette
{
public:
    static constexpr constant_ptr<Palette, 0x71A3D4> PALETTE_UNIT{}; //fs
    static constexpr constant_ptr<Palette, 0x71A7D4> PALETTE_ISO{}; //fs
    static constexpr constant_ptr<Palette, 0x719BD4> PALETTE_THEATER{}; //fs

    BGRStruct Data[256];

    BGRStruct& operator[](int index) { return Data[index]; }
    ColorStruct GetByteColor(int index) { // It's BGR color
        ColorStruct ret;
        BGRStruct& tmp = *(BGRStruct*)&Data[index];
        ret.red = tmp.R;
        ret.green = tmp.G;
        ret.blue = tmp.B;
        return ret;
    }
};