//
// Created by a2fan on 11/25/2019.
//

#ifndef A2MGR_HOTKEYCONFIG_H
#define A2MGR_HOTKEYCONFIG_H

#include <string>
#include <map>
#include <vector>

using namespace std;
typedef vector<char> bytearr;
class HotKeyConfig {
private:
    map<int, vector<bytearr>> hotkeys;
public:
    void load(string filename);
    map<int, vector<bytearr>> getAsMap();
};


#endif //A2MGR_HOTKEYCONFIG_H
