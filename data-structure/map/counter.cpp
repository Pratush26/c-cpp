#include <bits/stdc++.h>
using namespace std;

int main() {
    map<string, int> mp;
    string str, word;
    getline(cin, str);
    stringstream ss(str);
    while (ss >> word) mp[word]++;
    for (auto i = mp.begin(); i != mp.end(); i++) cout<< i->first << " = " << i->second << "\n";
    return 0;
}
// sample input
// I love to play football and Soha like to watch football but Kamal does not like football