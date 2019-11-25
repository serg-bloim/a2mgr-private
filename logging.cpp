#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>
#include "game_objects/types.h"

using namespace std;
ofstream myfile;
void startLogging(){
  myfile.open ("example.txt", fstream::out);
}
void stopLogging(){
  myfile.close();
}

void log(const char *msg){
  myfile << msg << "\n";
  myfile.flush();
}

void log(std::string msg){
  log(msg.c_str());
}

string toHex(string str){
    stringstream ss;
    string::iterator itr = str.begin();
    for (;itr != str.end();  itr++ ){
      ss << "\\x" << std::uppercase << std::setfill('0') << std::setw(2) << std::hex << (uint)(uchar)*itr;
    }
    return ss.str();
}
string toHex(vector<char> str){
    stringstream ss;
    vector<char>::iterator itr = str.begin();
    for (;itr != str.end();  itr++ ){
      ss << "\\x" << std::uppercase << std::setfill('0') << std::setw(2) << std::hex << (uint)(uchar)*itr;
    }
    return ss.str();
}