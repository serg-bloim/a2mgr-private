#pragma once

#include "types.h"
#include <string>
//
// Created by a2fan on 11/24/2019.

//
//#ifndef A2MGR_UTILS_H
//
//#define A2MGR_UTILS_H
//#endif //A2MGR_UTILS_H

int ths_wrapper(const void *fptr);

bool compare(bytearr &barr, _BYTE *arr, int arrsize);

int ceilingDiv(int a, int b);

bytearr stoba(std::string &str);

bytearr stoba(const char *str);

std::string nospaces(const char *c_str);