#include <map> 
#include <vector> 

using namespace std; 
extern map<int, vector<string>> hotkeys;
extern bool hotkeys_initialized;

void init_hotkeymap();

bool is_hotkey_present(int hotkey, string item);