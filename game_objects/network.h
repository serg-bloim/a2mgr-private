//
// Created by a2fan on 11/28/2019.
//

#ifndef A2MGR_NETWORK_H
#define A2MGR_NETWORK_H

//enum : unsigned int NETWORK_DATA_TYPE{
//        HEALTH = 1
//};
//struct __declspec(align(2)) T_MSG
//        {
//        _DWORD dword0;
//        _BYTE gap0;
//        _WORD word_5;
//        _WORD word7;
//        char msgType;
//        _WORD word_A;
//        _BYTE byte_C;
//        _BYTE amount;
//        _WORD inv_item_ind;
//        _WORD item_type;
//        _WORD word_12;
//        };
#pragma pack(1)
struct __declspec(align(1)) T_MSG
        {
        _DWORD dword0;
        _BYTE gap0;
        _WORD word_5;
        _WORD word7;
        _BYTE msgType;
        _WORD word_A;
        _BYTE byte_C;
        _BYTE amount;
        _WORD inv_item_ind;
        _WORD item_type;
        _WORD word_12;
        };
#endif //A2MGR_NETWORK_H
