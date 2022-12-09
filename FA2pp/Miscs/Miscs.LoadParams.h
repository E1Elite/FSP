#pragma once

#include "../FA2PP.h"


class Miscs {
public:
    class LoadParams {
    public:
        void LoadToCombobox(CComboBox* pComboBox, int nParamCode) {
            JMP(0x438D00); //fs
        }

        void BuildingTypes(CComboBox* pComboBox, bool bDisplayAsName) {
            JMP(0x43A5B0); //fs
        }

        void InfantryTypes(CComboBox* pComboBox) {
            JMP(0x43AB20); //fs
        }

        void VehicleTypes(CComboBox* pComboBox) {
            JMP(0x43AFC0); //fs FA2 starts with 6 instead of 4
        }

        void AircraftTypes(CComboBox* pComboBox) {
            JMP(0x43B460); //fs
        }

        void TechnoTypes(CComboBox* pComboBox) {
            JMP(0x43B900); //fs
        }

        void LocalVariables(CComboBox* pComboBox) {
            JMP(0x43C9A0); //fs
        }

        void GlobalVariables(CComboBox* pComboBox) {
            JMP(0x43CD90); //fs
        }

        void TutorialTexts(CComboBox* pComboBox) {
            JMP(0x43D170); //fs Has more logic
        }

        void Triggers(CComboBox* pComboBox) {
            JMP(0x43D540); //fs
        }

        void YesNo(CComboBox* pComboBox) {
            JMP(0x43D900); //fs
        }


        void Sounds(CComboBox* pComboBox) {
            JMP(0x43DA20); //fs
        }
/*
        void Themes(CComboBox* pComboBox) {
            JMP(0x442240);
        }

        void Speeches(CComboBox* pComboBox) {
            JMP(0x442740);
        }
*/
        void SuperWeaponTypes(CComboBox* pComboBox) {
            JMP(0x43DA20); //fs
        }

        void Animations(CComboBox* pComboBox) {
            JMP(0x43DE10); //fs
        }

        void Particles(CComboBox* pComboBox) {
            JMP(0x43E200); //fs
        }

        void Movies(CComboBox* pComboBox, bool arg4, bool a3) {
            JMP(0x43E5F0); //fs
        }

        void Movies(CComboBox* pComboBox, bool bShowIndex) {
            Movies(pComboBox, !bShowIndex, bShowIndex);
        }

        void Houses(CComboBox* pComboBox,
            bool b1, bool b2, bool b3) {
            JMP(0x43F310); //fs
        }

        void TeamTypes(CComboBox* pComboBox, bool bLeaveNone) {
            JMP(0x440660); //fs
        }

        void Waypoints(CComboBox* pComboBox) {
            JMP(0x440BA0); //fs
        }
    };
};