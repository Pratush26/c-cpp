#include <bits/stdc++.h>
using namespace std;

int main() {
    multiset<int> ms; // keep duplicate and store in sorted manner
    int n, val;
    cin >> n;
    while (n--) {
        cin >> val;
        ms.insert(val);  //  logN
    }
    for(auto i: ms) cout << i << " ";
    cout << "\nEnter a value that you want to remove from set: ";
    cin >> n;
    
    auto it = ms.find(n);   // for deleting single value from duplicate
    ms.erase(it);   // O(2log n)
    for(auto i: ms) cout << i << " ";
    cout << "\n";

    ms.erase(n);    // O(log(n) + k) where set O(log n)
    for(auto i: ms) cout << i << " ";
    return 0;
}