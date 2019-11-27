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


char transform(char c) {
    if (c >= '0' && c <= '9')
        return c - '0';
    if (c >= 'a' && c <= 'f')
        return c - 'a' + 10;
    if (c >= 'A' && c <= 'F')
        return c - 'A' + 10;
    return 100;
}

bytearr stoba(string &str) {
    bytearr res;
    stringstream ss(str);
    for (int i = 0; i + 2 <= str.size(); i += 2) {
        unsigned char v, h, l;
        ss >>  h >> l;
        h = transform(h);
        l = transform(l);
        v = (h<<4) + l;
        res.push_back(v);
    }
    return res;
}

void HotKeyConfig::load(string filename) {
    ifstream myfile (filename.c_str());
    stringstream ss;
    if (myfile.is_open())
    {
        char ch;
        string buffer;
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
                default:
                    if((ch >= '0' && ch <='9' )||
                            (ch >= 'a' && ch <= 'f')||
                            (ch >='A' && ch <='F')){
                        buffer.push_back(ch);
                    }else{
                        //wrong character. ignore
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