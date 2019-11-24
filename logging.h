#include <string>


void startLogging();
void stopLogging();
void log(const char* msg);
void log(std::string msg);
std::string toHex(std::string str);