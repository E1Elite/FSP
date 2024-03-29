#pragma once

#include <CINI.h>
#include <GlobalVars.h>
#include <CObjectDatas.h>
#include <CPalette.h>

#include <Structures/FAVector.h>

struct CellData_BaseNodeData
{
    int BuildingID;
    int BasenodeID;
    CString House;
};

struct CellData
{
    short Unit;
    short Infantry[3];
    short Aircraft;
    short Structure;
    int TypeListIndex; // for BuildingType, it's -65536+{idx in list}, for TerrainType, it's some number, or it's -1
    int TerrainType;
    short Smudge;
    int SmudgeType;
    short Waypoint;
    CellData_BaseNodeData BaseNode;
    unsigned char Overlay;
    unsigned char OverlayData; // [0, 59]
    short TileIndex;
    short Short_30; // leading bytes of TileIndex
    unsigned char TileSubIndex;
    unsigned char Height;
    unsigned char IceGrowth;
    short CellTag;
    short Tube;
    unsigned char TubeDataIndex;
    unsigned char StatusFlag;
    unsigned char LAT; // uses high 4 bit, see https://modenc.renegadeprojects.com/images/ConnectingLATSetSubTileSelection.png
};

#pragma pack(push, 1)
struct TileStruct
{
    short X;
    short Y;
    int TileIndex;
    unsigned char TileSubIndex;
    unsigned char Level;
    unsigned char IceGrowth;
};
#pragma pack(pop)

struct StructureData
{
    ColorStruct HouseColor;
    CString ID;
    short Y;
    short X;
    short Facing;
    unsigned char Strength;
    unsigned char PowerUpCount; //Upgrades
    CString PowerUp1;
    CString PowerUp2;
    CString PowerUp3;
};

struct TubeData
{
    __int16 Unknown_0;
    __int16 DestY;
    __int16 DestX;
    __int16 TubeDir;
    __int16 Unknown_8; // X related?
    char Data[102];
};

class NOVTABLE CMapData
{
public:

    void UpdateMapFieldData(bool bFlag) { JMP_THIS(0x493B80); } //fs
    INIClass* UpdateCurrentDocument() { JMP_THIS(0x493B60); } //fs
    static INIClass* GetMapDocument(bool bUpdateMapField = false)
    {
        if (bUpdateMapField)
            GlobalVars::CMapData().UpdateMapFieldData(1);
        return &GlobalVars::CMapData().INI;
    }

    const wchar_t* QueryUIName(const char* pRegName) { JMP_THIS(0x4A9EF0); } //fs
    static CString GetUIName(const char* pRegName) { return CString(GlobalVars::CMapData->QueryUIName(pRegName)); }

    void LoadMap(const char* pMapPath) { JMP_THIS(0x494BC0); } //fs
    void UnpackData() { JMP_THIS(0x496750); } //fs // called in LoadMap

    void InitializeBuildingTypes(const char* ID) { JMP_THIS(0x4ACD60); } //fs // use nullptr to reload all

    // FA2 magics
    int GetCoordIndex(int X, int Y) { return Y + X * MapWidthPlusHeight; }  
    int GetXFromCoordIndex(int CoordIndex) { return CoordIndex / MapWidthPlusHeight; }
    int GetYFromCoordIndex(int CoordIndex) { return CoordIndex % MapWidthPlusHeight; }

    void GetStructureData(int structureID, StructureData* pRet) { JMP_THIS(0x4B9F90); } //fs
//    TubeData* GetTubeData(int tubeID) { JMP_THIS(0x4753C0); }

    CString StringBuffer;
    BOOL Initialized; // Maybe? It's data related, if this is false, UnitData, StructureData and so on will be called for loading?
    int MapWidthPlusHeight;
    CellData TempCellData;
    BOOL FieldDataAllocated;
    FAVector<int> BuildingTypes;
    FAVector<int> TerrainTypes;
    FAVector<int> UnitTypes;
    unsigned char Overlay[0x40000];
    unsigned char OverlayData[0x40000];
    TileStruct* IsoPackData;
    int IsoPackDataCount;
    INIClass INI;
    RECT Size;
    RECT LocalSize;
    CellData* CellDatas; // see 4BB920 validate the map, dtor at 416FC0
    int CellDataCount; // see 4BB920 validate the map
    void* UndoRedoData;
    int UndoRedoDataCount; // undo redo count related
    int UndoRedoCurrentDataIndex; // undo redo count related, UndoRedoDataCount - 1
    int MoneyCount;
    FAVector<StructureData> StructureDatas; // being used in 4C3C20
    FAVector<TubeData> TubeDatas; // see 4753C0, might be TUBE related
    FAVector<int> vector_801F8;
    FAVector<CTerrainData> TerrainDatas;
    FAVector<CInfantryData> InfantryDatas;
    FAVector<CUnitData> UnitDatas; // Seems never used except DTOR
    FAVector<int> vector_80238;    // Seems never used except DTOR
    unsigned char MapPreview[0x40000];
    BITMAPINFO MapPreviewInfo;
    int nSomeMapPreviewData_C0274;
    INIClass SomeTheaterINI; //maybe?
    int Unknown_C0380;
    int Unknown_C0384;
    int Unknown_C0388;
    int Unknown_C038C;
};
