#pragma once

#include <MFC/ppmfc_cstring.h>

enum class ObjectType
{
    Infantry = 0,
    Structure = 1,
    Aircraft = 2,
    Unit = 3,
    Overlay = 4,
    Celltag = 5,
    Waypoints = 6
};

class CInfantryData
{
public:
    CString House;
    CString TypeID;
    CString Health;
    CString X;
    CString Y;
    CString SubCell;
    CString Status; // Mission
    CString Facing;
    CString Tag;
    CString VeterancyPercentage;
    CString Group;
    CString IsAboveGround;
    CString AutoNORecruitType;
    CString AutoYESRecruitType;
    int Flag;
};

class CStructureData
{
    CString House;
    CString TypeID;
    CString Health;
    CString X;
    CString Y;
    CString Facing;
    CString Tag;
    CString AISellable;
    CString AIRebuildable;
    CString PoweredOn;
    CString Upgrades; // Count
    CString SpotLight;
    CString Upgrade1;
    CString Upgrade2;
    CString Upgrade3;
    CString AIRepairable;
    CString Nominal;
    int Flag;
};

class CUnitData
{
public:
    CString House;
    CString TypeID;
    CString Health;
    CString X;
    CString Y;
    CString Facing;
    CString Status; // Mission
    CString Tag;
    CString VeterancyPercentage;
    CString Group;
    CString IsAboveGround;
    CString FollowsIndex;
    CString AutoNORecruitType;
    CString AutoYESRecruitType;
    int Flag;
};

class CAircraftData
{
public:
    CString House;
    CString TypeID;
    CString Health;
    CString X;
    CString Y;
    CString Facing;
    CString Status; // Mission
    CString Tag;
    CString VeterancyPercentage;
    CString Group;
    CString AutoNORecruitType;
    CString AutoYESRecruitType;
    int Flag;
};

class CTerrainData
{
public:
    CString TypeID;
    CString X; // maybe
    CString Y; // maybe
    int Flag;
};