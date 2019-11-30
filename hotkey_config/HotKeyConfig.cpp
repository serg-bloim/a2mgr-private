//
// Created by a2fan on 11/25/2019.
//

#include "HotKeyConfig.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
#include "../logging.h"

using namespace std;




void HotKeyConfig::load(string filename) {
    ifstream myfile (filename.c_str());
    stringstream ss;
    if (myfile.is_open())
    {
        char ch;
        string buffer;
        bool comment = false;
        int hotkey =-1;
        vector<bytearr> items;
        int i =0;
        while (myfile.get(ch)) {
            switch (ch){
                case ' ':
                case '\t':
                case '\r':
                    //skip
                    break;
                case '\n':
                    comment = false;
                case ';':
                    if(buffer.size() > 0 && hotkey != -1) {
                        hotkeys[hotkey].push_back(stoba(buffer));
                        buffer.clear();
                    }
                    break;
                case '=':
                    stringstream(buffer) >> hotkey;
                    buffer.clear();
                    break;
                case '#':
                    comment = true;
                    break;
                default:
                    if(!comment) {
                        if ((ch >= '0' && ch <= '9') ||
                            (ch >= 'a' && ch <= 'f') ||
                            (ch >= 'A' && ch <= 'F')) {
                            buffer.push_back(ch);
                        }
                    }
            }
        }
        if(buffer.size() > 0 && hotkey != -1){
            hotkeys[hotkey].push_back(stoba(buffer));
            buffer.clear();
        }
        myfile.close();
    }
    else cout << "Unable to open file";;
}

map<int, vector<bytearr>> HotKeyConfig::getAsMap() {
    return hotkeys;
}