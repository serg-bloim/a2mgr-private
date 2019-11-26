//
// Created by a2fan on 11/25/2019.
//

#include "HotKeyConfig.h"
#include <iostream>
#include <fstream>
using namespace std;
void HotKeyConfig::load(string filename) {
    ofstream myfile;
    myfile.open (filename, fstream::in);
}

map<int> HotKeyConfig::getAsMap() {
    return hotkeys;
}