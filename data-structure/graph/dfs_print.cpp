#include <bits/stdc++.h>
using namespace std;

void dfs(int src, vector<vector<int>> &arr, vector<bool> &visited) {
    cout << src << " ";
    visited[src] = true;
    for(int i: arr[src]) if (!visited[i]) dfs(i, arr, visited);
}

int main() {
    int n, e, r, c, check;
    cin >> n >> e;
    vector<vector<int>> arr(n);
    vector<bool> visited(n, false);
    while (e--) {
        cin >> r >> c;
        arr[r].push_back(c);
        arr[c].push_back(r);
    }
    dfs(0, arr, visited);   //  Depth First Search

    return 0;
}

//  sample input
// 7 5
// 0 1
// 1 3
// 3 2
// 4 6
// 3 5