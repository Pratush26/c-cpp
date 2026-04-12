#include <bits/stdc++.h>
using namespace std;

int main() {
    map<string, int> mp;
    mp["sakib"] = 25;   //  logN
    mp.insert({"sajid", 35});
    mp["rakib"] = 43;
    
    for (auto i = mp.begin(); i != mp.end(); i++) cout << "Name: " << i->first << ", Roll: " << i->second << "\n";
    // for(auto [key, value]: mp) cout << "Name: " << key << ", Roll: " << value << "\n";
    
    // safety check
    mp.erase("sakib");
    
    auto it = mp.find("sakib");
    if(it == mp.end()) cout << "Key not found";
    else cout << it->first << " -> " << it->second;
    
    return 0;
}