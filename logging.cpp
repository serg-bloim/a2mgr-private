#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;
ofstream myfile;
void startLogging(){
  myfile.open ("example.txt", fstream::out);
}
void stopLogging(){
  myfile.close();
}

void log(const char *msg){
  // myfile << msg << "\n";
}

void log(std::string msg){
  log(msg.c_str());
}

string toHex(std::string str){
    stringstream ss;
    string::iterator itr = str.begin();
    for (;itr != str.end();  itr++ ){
      ss << std::uppercase << std::setfill('0') << std::setw(2) << std::hex << *itr << " ";
    }
    return ss.str();
}