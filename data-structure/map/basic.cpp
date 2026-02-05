#include <bits/stdc++.h>
using namespace std;

int main() {
    map<string, int> mp;
    mp["sakib"] = 25;
    mp.insert({"sajid", 35});
    mp["rakib"] = 43;
    
    for (auto i = mp.begin(); i != mp.end(); i++) cout << "Name: " << i->first << ", Roll: " << i->second << "\n";
    return 0;
}