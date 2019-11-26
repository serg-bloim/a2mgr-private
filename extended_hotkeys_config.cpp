#include "extended_hotkeys_config.h"
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <sstream>
#include <iomanip>
#include "logging.h"

using namespace std;
map<int, vector<bytearray>> hotkeys;
bool hotkeys_initialized = false;

vector<char> convert( const char arr[], int size) {
    vector<char> v(arr, arr + size-1);
    return v;
}

void init_hotkeymap() {
    if (!hotkeys_initialized) {
        hotkeys_initialized = true;
        // string item1 = "\x01\x2f\x08\x02\x00\x33\x00\x29\x1a\x32\x64";
        const char item1[] = "\x01\x45\x5C\x24\x00\x0F\x0F\x33\x00\x25\x12";
        const char item2[] = "\x01\x89\x6E\x0F\x00\x0F\x0A\x33\x00\x25\x0F";
        const char item3[] = "\x01\xC5\x4F\x24\x00\x0F\x07\x33\x00\x25\x12";
        hotkeys[90].push_back(convert(item1, sizeof(item1)));
        hotkeys[90].push_back(convert(item2, sizeof(item2)));
        hotkeys[90].push_back(convert(item3, sizeof(item3)));
        // for(string::iterator it = item1.begin(); it != item1.end(); it++){
        //     hotkeys[90][0].push_back(*it);
        // }
        stringstream ss;
        ss << "Binded item is: '" << toHex(hotkeys[90][0]) << "'";
        log(ss.str());
    }
}

bool is_hotkey_present(int hotkey, bytearray item) {
    stringstream ss;
    ss << "Item's data: '" << toHex(item) << "'";
    log(ss.str());
    if (hotkeys.find(hotkey) != hotkeys.end()) {
        log("Found a hotkey!");
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