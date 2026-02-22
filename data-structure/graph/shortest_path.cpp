#include <bits/stdc++.h>
using namespace std;

void bfs(int src, vector<vector<int>> &arr, vector<bool> &visited, vector<int> &level, vector<int> &parnt){
    queue<int> qu;
    qu.push(src);
    visited[src] = true;
    level[src] = 0;
    while (!qu.empty()) {
        int cur = qu.front();
        qu.pop();
        for(int i: arr[cur]) {
            if (!visited[i]) {
                visited[i] = true;
                level[i] = level[cur] + 1;
                parnt[i] = cur;
                qu.push(i);
            }
        }
    }
}
int main() {
    int n, e, r, c;
    cin >> n >> e;
    vector<vector<int>> arr(n);
    vector<bool> visited(n, false);
    vector<int> level(n, -1);
    vector<int> parnt(n, -1);
    while (e--) {
        cin >> r >> c;
        arr[r].push_back(c);
        arr[c].push_back(r);
    }
    bfs(0, arr, visited, level, parnt);
    cin >> r;
    cout << "Destination: " << r << "\nDistance: " << level[r] << "\nPath";
    while (r != -1)
    {
        cout << " -> " << r;
        r = parnt[r];
    }
    
    return 0;
}

//  sample input
// 7 8
// 0 1
// 1 3
// 3 2
// 1 4
// 3 5
// 2 5
// 5 6
// 4 6
// 4