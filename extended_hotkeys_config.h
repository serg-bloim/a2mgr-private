#include <map> 
#include <vector> 

using namespace std; 

typedef vector<char> bytearray;
//extern map<int, vector<string>> hotkeys;
//extern bool hotkeys_initialized;

void init_hotkeymap(bool force);

bool is_hotkey_present(int hotkey, bytearray item);