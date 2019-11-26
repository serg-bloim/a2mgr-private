#include "extended_hotkeys_config.h"
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <sstream>
#include <iomanip>
#include "logging.h"
#include "hotkey_config/HotKeyConfig.h"

using namespace std;
map<int, vector<bytearray>> hotkeys;
bool hotkeys_initialized = false;

vector<char> convert( const char arr[], int size) {
    vector<char> v(arr, arr + size-1);
    return v;
}

void init_hotkeymap() {
    if (!hotkeys_initialized) {
        log("start reading hotkeys.txt");
        hotkeys_initialized = true;
        HotKeyConfig conf;
        conf.load("hotkeys.txt");
        hotkeys = conf.getAsMap();

        stringstream ss;
        for (map<int,vector<bytearr>>::iterator it = hotkeys.begin(); it!=hotkeys.end(); ++it){
            vector<bytearr> itms = it->second;
            ss << it->first << "(" << itms.size() << ") = ";
            for (vector<bytearr>::iterator it2 = itms.begin(); it2 != itms.end(); it2++){
                ss << toHex(*it2) << "; ";
            }
            log(ss.str());
            ss.clear();
        }
        log("end reading hotkeys.txt");
    }
}

bool is_hotkey_present(int hotkey, bytearray item) {
    stringstream ss;
    ss << "Item's data: '" << toHex(item) << "'";
//    log(ss.str());
    if (hotkeys.find(hotkey) != hotkeys.end()) {
//        log("Found a hotkey!");
        vector<bytearray> itms = hotkeys[hotkey];
        if (std::find(itms.begin(), itms.end(), item) != itms.end()) {
            log("Found a match!");
            return true;
        }
    }
    return false;
}
// bool lookup()
// {
//     vector<string> v;
//     v.push_back("abc");
//     v.push_back("xyz");

//     string s = "abc";
//     if (find(v.begin(), v.end(), s) != v.end())
//     {
//         return true;
//     }
//     return false;
// }

bool iventory_data_compare(vector<char> data1, vector<char> data2) {
    if (data1.size() != data2.size()) {
        return false;
    }
    std::vector<char>::iterator it1 = data1.begin();
    std::vector<char>::iterator it2 = data2.begin();
    while (it1 != data1.end() || it2 != data2.end()) {
        if (*it1 != *it2) {
            return false;
        }
        it1++;
        it2++;
    }
    return it1 == data1.end() && it2 == data2.end();
}