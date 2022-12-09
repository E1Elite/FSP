#pragma once

#include "FA2PP.h"

struct ShapeHeader
{
    short Type;
    short Width;
    short Height;
    short FrameCount;
};

struct ShapeImageHeader
{
    short X;
    short Y;
    short Width;
    short Height;
    int Compression;
    int Unknown;
    int Zero;
    int Offset;
};

/*
struct ARGB
{
    unsigned char A;
    unsigned char R;
    unsigned char G;
    unsigned char B;
};

struct ShapeImageHeader
{
    short X;
    short Y;
    short Width;
    short Height;
    char Compression; // yes == Compression & 0x2
    char padding[3];
	ARGB RadarColor;
    int Zero;
    int Offset;
};
*/
struct ShapeFileStruct
{
    ShapeHeader Header;
    ShapeImageHeader* FrameHeaders;
};


class CShpFile
{
public:
    static bool __cdecl GetSHPHeader(ShapeHeader* pHeader) { JMP_STD(0x517E60); } //fs
    static bool __cdecl GetSHPImageHeader(int nFrame, ShapeImageHeader* pHeader) { JMP_STD(0x517E90); } //fs
    static bool __cdecl LoadFrame(int nFrame, int nFrameCount, unsigned char** ppBuffer) { JMP_STD(0x518450); } //fs
};