#include <bits/stdc++.h>
using namespace std;

int main() {
    string str, word;
    cout << "Enter a message: ";
    getline(cin, str);
    stringstream ss(str);
    while (ss >> word) cout << word << "\n";             
    return 0;
}