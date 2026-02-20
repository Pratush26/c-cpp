#include <bits/stdc++.h>
using namespace std;

    // There is 3 types of input stretagy for graph input

int main() {

    // Adjacent Array
    int n, e, r, c;
    cin >> n >> e;
    int matrx[n][n];
    memset(matrx, 0, sizeof(matrx));
    for (int i = 0; i < e; i++) {
        matrx[i][i] = 1;
    }
    for (int i = 0; i < e; i++) {
        cin >> r >> c;
        matrx[r][c] = 1;
        matrx[c][r] = 1;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cout <<  matrx[i][j] << " ";
        cout << "\n";
    }

    // Adjacent List
    cin >> n >> e;
    vector<int> arr[n];
    while (e--) {
        cin >> r >> c;
        arr[r].push_back(c);
        arr[c].push_back(r);
    }
    for (int i = 0; i < n; i++) {
        cout << i << " -> ";
        for (int val : arr[i]) {
            cout << val << " ";
        }
        cout << "\n";
    }

    //  Edge List
    cin >> n >> e;
    vector<pair<int, int>> li;
    while (e--) {
        cin >> r >> c;
        li.push_back({r, c});
    }
    for (auto i : li) cout << i.first << " -> " << i.second << "\n";
    return 0;
}

//  sample input
// 5 5
// 0 1
// 0 2
// 3 0
// 1 3
// 3 4