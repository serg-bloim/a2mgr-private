//
// Created by a2fan on 11/28/2019.
//

#ifndef A2MGR_NETWORK_H
#define A2MGR_NETWORK_H

//enum : unsigned int NETWORK_DATA_TYPE{
//        HEALTH = 1
//};
struct T_MSG {
    _BYTE gap0[18];
    _WORD word12;
    unsigned int data_types;
    char char18;
};

#endif //A2MGR_NETWORK_H
