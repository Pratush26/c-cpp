#include <bits/stdc++.h>
using namespace std;

int r, c;
vector<pair<int, int>> way = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

bool valid(int i, int j){
    if(i < 0 || j < 0 || i >= r || j >= c) return false;
    return true;
}
void dfs(int x, int y, vector<vector<bool>> &visited) {
    cout << x << " " << y << "\n";
    visited[x][y] = true;
    for (int i = 0; i < 4; i++) {
        int ni = x + way[i].first;
        int nj = y + way[i].second;
        if(valid(ni, nj) && !visited[ni][nj]) dfs(ni, nj, visited);
    }
}

void bfs(int x, int y) {
    queue<pair<int, int>> q;
    q.push({x, y});
    vector<vector<bool>> visited(r, vector<bool>(c, false));
    visited[x][y] = true;
    while (!q.empty()) {
        pair<int, int> p = q.front();
        x = p.first;
        y = p.second;
        q.pop();
        cout << x << " " << y << "\n";
        for (int i = 0; i < 4; i++) {
            int ni = x + way[i].first;
            int nj = y + way[i].second;
            if(valid(ni, nj) && !visited[ni][nj]) {
                q.push({ni, nj});
                visited[ni][nj] = true;
            }
        }
    }
}

int main() {
    int x, y;
    cin >> r >> c;
    char grid[r][c];
    vector<vector<bool>> visited(r, vector<bool>(c, false));
    for (int i = 0; i < r; i++) for (int j = 0; j < c; j++) cin >> grid[i][j];
    cin >> x >> y;

    //  bfs output
    cout << "bfs output\n";
    dfs(x, y, visited);
    //  dfs output
    cout << "dfs output\n";
    bfs(x, y);
    return 0;
}

//  sample input
// 3 4
// * * * *
// * * * *
// * * * *
// 1 2