//
// Created by a2fan on 11/28/2019.
//

#ifndef A2MGR_UNIT_VIEW_H
#define A2MGR_UNIT_VIEW_H
#include "types.h"

struct __declspec(align(2)) T_UNIT_VIEW
        {
        _DWORD *clazz;
        _WORD word4;
        _BYTE gap0[2];
        _DWORD dword8;
        _DWORD dwordC;
        _DWORD dword10;
        _DWORD dword14;
        _DWORD dword18;
        _DWORD dword1C;
        _BYTE gap1[4];
        _DWORD dword24;
        _DWORD dword28;
        _DWORD dword2C;
        _DWORD dword30;
        _BYTE gap2[4];
        int pos_x;
        int pos_y;
        _BYTE gap3[48];
        _DWORD dword70;
        _BYTE gap4[8];
        int field_7C;
        int selected;
        _BYTE gap5[4];
        _DWORD dword88;
        _BYTE byte8C;
        _BYTE byte8D;
        _BYTE gap6[2];
        _DWORD dword90;
        _DWORD dword94;
        _BYTE gap7[4];
        _DWORD dword9C;
        _DWORD dwordA0;
        _DWORD dwordA4;
        _DWORD dwordA8;
        _BYTE gap8[60];
        _DWORD dwordE8;
        char charEC;
        _BYTE gap9[11];
        char charF8;
        _BYTE gap10[11];
        short health;
        _BYTE gap11[2];
        short maxHealth;;
        _WORD word10A;
        _WORD word10C;
        _WORD word10E;
        _DWORD dword110;
        _DWORD dword114;
        _BYTE byte118;
        _BYTE gap12[43];
        _BYTE byte144;
        _BYTE mind;
        _BYTE byte146;
        _BYTE byte147;
        _WORD word148;
        _WORD word14A;
        _BYTE gap13[2];
        _BYTE byte14E;
        _WORD word150;
        _WORD word152;
        _BYTE byte154;
        _BYTE byte155;
        _BYTE skills;
        _BYTE byte157;
        _BYTE byte158;
        _BYTE byte159;
        _BYTE byte15A;
        _BYTE byte15B;
        _BYTE byte15C;
        _BYTE byte15D;
        _BYTE byte15E;
        _BYTE byte15F;
        _BYTE byte160;
        _BYTE gap14[11];
        _DWORD dword16C;
        _DWORD dword170;
        _DWORD dword174;
        _DWORD dword178;
        _DWORD dword17C;
        _BYTE byte180;
        _BYTE byte181;
        _BYTE byte182;
        _BYTE byte183;
        _BYTE byte184;
        _BYTE gap15[51];
        unsigned int attrs;
        _BYTE gap16[32];
        _WORD word1DC;
        bool isMainUnit();
        };

#endif //A2MGR_UNIT_VIEW_H
