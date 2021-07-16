#pragma once

#include "FA2PP.h"
#include "CINI.h"
#include "Helpers/CompileTime.h"

class CFinalSunDlg;

class GlobalVars
{
public:
    static constexpr reference<char, 0x719650, 260> const ExePath{}; // Where FA2.exe locates  //fs
    static constexpr reference<char, 0x719448, 260> const MapPath{}; // Where current map locates //fs 
    static constexpr reference<char, 0x71954C, 260> const FilePath{}; // Where mix files locates //fs 
    
    static constexpr reference<int, 0x71BB10> const CurrentMapWidthPlusHeight{}; // duh  //fs 

    class Dialogs
    {
    public:
        static constexpr reference<CFinalSunDlg*, 0x7DCE34> const CFinalSunDlg{}; //fs
    };
    class INIFiles
    {
    public:
        static constexpr reference<INIClass, 0x7DCCE8> const Rules{}; // rulesmd.ini / rules.ini  //fs 
        static constexpr reference<INIClass, 0x7DCBB8> const Art{}; // artmd.ini / art.ini  //fs 
        static constexpr reference<INIClass, 0x7DC870> const Turtorial{}; // tutorial.ini  //fs 
        static constexpr reference<INIClass, 0x7DC988> const Sound{}; // soundmd.ini / sound.ini  //fs reading sound file is broken in FS
        static constexpr reference<INIClass, 0x7DC758> const Eva{}; // evamd.ini / eva.ini //fs - Path is not full path, TS doesn't have eva ini
        static constexpr reference<INIClass, 0x7DC640> const Theme{}; // thememd.ini / theme.ini  //fs 
        static constexpr reference<INIClass, 0x7DCAA0> const Ai{}; // aimd.ini / ai.ini  //fs 
        static constexpr reference<INIClass, 0x7DC2F8> const Temperate{}; // temperatmd.ini / temperat.ini   //fs 
        static constexpr reference<INIClass, 0x7DC1E0> const Snow{}; // snowmd.ini / snow.ini  //fs 
//        static constexpr reference<INIClass, 0x7ED1B8> const Urban{}; // urbanmd.ini / urban.ini
//        static constexpr reference<INIClass, 0x7ED0A0> const NewUrban{}; // urbannmd.ini
//        static constexpr reference<INIClass, 0x7ECF88> const Lunar{}; // lunarmd.ini
//        static constexpr reference<INIClass, 0x7ECE70> const Desert{}; // desertmd.ini
        static constexpr reference<INIClass, 0x7DC528> const FAData{}; // FAData.ini  //fs  FSData
        static constexpr reference<INIClass, 0x7DC410> const FALanguage{}; // FALanguage.ini  //fs  FSLanguage
        // static constexpr reference<INIClass, 0x71BB08> const UINameHolder{}; // Holds Stringtable //fs
        static constexpr reference<INIClass, 0x79BB90> const CurrentDocument{}; // Current map file, without update  //fs 
        static constexpr reference<INIClass, 0x7DCF4C> const CurrentTheater{}; // Current theater file //fs
    };

};