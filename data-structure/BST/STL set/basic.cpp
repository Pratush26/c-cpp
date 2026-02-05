#include <bits/stdc++.h>
using namespace std;

int main() {
    set<int> s; // remove duplicate and store in sorted manner
    int n, val;
    cin >> n;
    while (n--) {
        cin >> val;
        s.insert(val);  //  logN
    }

    for(auto i: s) cout << i << " ";

    //  search
    cout << "\nSearch any value in the set: ";
    cin >> val;
    cout << (s.count(val)? "Found" : "Not Found");
    return 0;
}