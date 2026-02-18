#include <bits/stdc++.h>
using namespace std;

bool cycle = false;

    //  using bfs
void bfs(int src, vector<vector<int>> &arr, vector<int> &parnt, vector<bool> &visited){
    queue<int> qu;
    qu.push(src);
    visited[src] = true;
    while (!qu.empty()) {
        int cur = qu.front();
        qu.pop();
        for(int i: arr[cur]) {
            if (visited[i] && parnt[cur] != i) cycle = true;
            if (!visited[i]) {
                visited[i] = true;
                parnt[i] = cur;
                qu.push(i);
            }
        }
    }
}

    //  using dfs
void dfs(int src, vector<vector<int>> &arr, vector<int> &parnt, vector<bool> &visited){;
    visited[src] = true;
    for(int i: arr[src]) {
        if (visited[i] && parnt[src] != i) cycle = true;
        if (!visited[i]) {
            parnt[i] = src;
            dfs(i, arr, parnt, visited);
        }
    }
}

int main() {
    int n, e, r, c;
    cin >> n >> e;
    vector<vector<int>> arr(n);
    vector<bool> visited(n, false);
    vector<int> parnt(n, -1);
    while (e--) {
        cin >> r >> c;
        arr[r].push_back(c);
        arr[c].push_back(r);
    }
    for (int i = 0; i < n; i++) {
        if(!visited[i]) dfs(i, arr, parnt, visited);
    }
    cout << (cycle? "Cycle detected" : "No cycle found!");
    return 0;
}

//  sample input
// 6 5
// 0 1
// 1 2
// 2 3
// 3 0
// 4 5