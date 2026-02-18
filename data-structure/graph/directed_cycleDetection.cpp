#include <bits/stdc++.h>
using namespace std;

bool cycle = false;

void dfs(int src, vector<vector<int>> &arr, vector<bool> &path_vistd, vector<bool> &visited){;
    visited[src] = true;
    path_vistd[src] = true;
    for(int i: arr[src]) {
        if (visited[i] && path_vistd[src]) cycle = true;
        if (!visited[i]) {
            dfs(i, arr, path_vistd, visited);
        }
    }
    path_vistd[src] = false;
}

int main() {
    int n, e, r, c;
    cin >> n >> e;
    vector<vector<int>> arr(n);
    vector<bool> visited(n, false);
    vector<bool> path_vistd(n, false);
    while (e--) {
        cin >> r >> c;
        arr[r].push_back(c);
    }
    for (int i = 0; i < n; i++) {
        if(!visited[i]) dfs(i, arr, path_vistd, visited);
    }
    cout << (cycle? "Cycle detected" : "No cycle found!");
    return 0;
}

//  sample input
// 4 4
// 0 1
// 1 2
// 2 3
// 3 0