#include <bits/stdc++.h>
using namespace std;

void bfs(int src, vector<vector<int>> &arr, vector<bool> &visited){
    queue<int> qu;
    qu.push(src);
    visited[src] = true;
    while (!qu.empty()) {
        int cur = qu.front();
        qu.pop();
        cout << cur <<" ";
        for(int i: arr[cur]) {
            if (!visited[i]) {
                visited[i] = true;
                qu.push(i);
            }
        }
    }
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
    bfs(0, arr, visited);   //  Breath First Search

    //  check connected or not
    cin >> check;
    cout << "\n" << (visited[check]? "YES" : "NO") << "\n";
    return 0;
}

//  sample input
// 7 5
// 0 1
// 1 3
// 3 2
// 4 6
// 3 5
// 4