#include <bits/stdc++.h>
using namespace std;

void dfs(int src, vector<vector<int>> &arr, vector<bool> &visited) {
    cout << src << " ";
    visited[src] = true;
    for(int i: arr[src]) if (!visited[i]) dfs(i, arr, visited);
}

int main() {
    int n, e, r, c, comp = 0;
    cin >> n >> e;
    vector<vector<int>> arr(n);
    vector<bool> visited(n, false);
    while (e--) {
        cin >> r >> c;
        arr[r].push_back(c);
        arr[c].push_back(r);
    }
    for (int i = 0; i < n; i++) {
        if(!visited[i]) {
            dfs(i, arr, visited);
            comp++;
            cout << "\n";
        }
    }
    cout << "Total Component Found : " << comp;
    return 0;
}

//  sample input
// 8 6
// 1 2
// 0 5
// 2 3
// 6 7
// 4 5
// 1 3