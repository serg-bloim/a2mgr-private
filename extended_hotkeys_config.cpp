#include "extended_hotkeys_config.h"
#include <vector>
#include <map>
#include <algorithm>
#include <string>

using namespace std;

map<int, vector<string>> hotkeys;
bool hotkeys_initialized = false;

void init_hotkeymap()
{
    if (!hotkeys_initialized)
    {
        hotkeys_initialized = true;
        // string item1 = "\x01\x2f\x08\x02\x00\x33\x00\x29\x1a\x32\x64";
        string item1 = "\x01\x45\x5c\x24\x00\x0f\x0f\x33\x00\x25\x12";
        hotkeys[90].push_back(item1);
        // for(string::iterator it = item1.begin(); it != item1.end(); it++){
        //     hotkeys[90][0].push_back(*it);
        // }
    }
}

bool is_hotkey_present(int hotkey, string item)
{
    if (hotkeys.find(hotkey) != hotkeys.end())
    {
        vector<string> itms = hotkeys[hotkey];
        if (std::find(itms.begin(), itms.end(), item) != itms.end())
        {
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

bool iventory_data_compare(vector<char> data1, vector<char> data2)
{
    if (data1.size() != data2.size())
    {
        return false;
    }
    std::vector<char>::iterator it1 = data1.begin();
    std::vector<char>::iterator it2 = data2.begin();
    while (it1 != data1.end() || it2 != data2.end())
    {
        if (*it1 != *it2)
        {
            return false;
        }
        it1++;
        it2++;
    }
    return it1 == data1.end() && it2 == data2.end();
}