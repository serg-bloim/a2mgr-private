#include <string>
#include <vector>


void startLogging();
void stopLogging();
void log(const char* msg);
void log(std::string msg);
std::string toHex(std::string str);
std::string toHex(std::vector<char> str);
std::string toHex2(std::vector<char> str);