#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, e, r, c, d;
    cin >> n >> e;
    vector<pair<int, int>> arr[n];
    while (e--) {
        cin >> r >> c >> d;
        arr[r].push_back({c, d});
        arr[c].push_back({r, d});
    }
    for (int i = 0; i < n; i++) {
        cout << i << " -> ";
        for (pair<int, int> val : arr[i]) {
            cout << val.first << " " << val.second << ", ";
        }
        cout << "\n";
    }
    return 0;
}

//  sample input
// 5 8
// 0 1 10
// 1 2 1
// 0 2 7
// 0 3 4
// 2 3 1
// 3 4 5 
// 1 4 3
// 2 4 5