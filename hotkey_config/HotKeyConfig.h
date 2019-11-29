//
// Created by a2fan on 11/25/2019.
//

#ifndef A2MGR_HOTKEYCONFIG_H
#define A2MGR_HOTKEYCONFIG_H

#include <string>
#include <map>
#include <vector>
#include "../game_objects/types.h"
#include "../game_objects/utils.h"

using namespace std;
class HotKeyConfig {
private:
    map<int, vector<bytearr>> hotkeys;
public:
    void load(string filename);
    map<int, vector<bytearr>> getAsMap();
};

#endif //A2MGR_HOTKEYCONFIG_H
