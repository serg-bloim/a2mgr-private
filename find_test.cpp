#include <vector>
#include <algorithm>
#include <string>
using namespace std;
bool lookup()
{
    vector<string> v;
    v.push_back("abc");
    v.push_back("xyz");

    string s = "abc";
    if (find(v.begin(), v.end(), s) != v.end())
    {
        return true;
    }
    return false;
}