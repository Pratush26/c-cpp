#include <bits/stdc++.h>
using namespace std;

int main() {
    int r, c, rx = -1, ry = -1, dx = -1, dy = -1;
    queue<pair<int,int>> qu;
    cin >> r >> c;

    vector<vector<char>> grid(r, vector<char>(c));
    vector<vector<bool>> vis(r, vector<bool>(c, false));
    vector<vector<pair<int,int>>> parnt(r, vector<pair<int,int>>(c, {-1, -1}));

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'R') {    //  to
                rx = i;
                ry = j;
            }
            if (grid[i][j] == 'D') {    //  from
                dx = i;
                dy = j;
            }
        }
    }

    if (rx == -1 || dx == -1) {
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) cout << grid[i][j];
            cout << '\n';
        }
        return 0;
    }

    bool found = false;
    int mx[] = {0, 0, -1, 1};
    int my[] = {1, -1, 0, 0};
    qu.push({rx, ry});
    vis[rx][ry] = true;

    while (!qu.empty()) {
        auto cur = qu.front();
        qu.pop();
        if (cur.first == dx && cur.second == dy) {
            found = true;
            break;
        }
        for (int d = 0; d < 4; d++) {
            int nx = cur.first + mx[d];
            int ny = cur.second + my[d];
            if (nx < 0 || ny < 0 || nx >= r || ny >= c || vis[nx][ny] || grid[nx][ny] == '#') continue;
            vis[nx][ny] = true;
            parnt[nx][ny] = cur;
            qu.push({nx, ny});
        }
    }

    if (found) {
        int x = dx, y = dy;
        while (!(x == rx && y == ry)) {
            auto p = parnt[x][y];
            cout << grid[x][y] << " -> ";
            x = p.first;
            y = p.second;
        }
        cout << grid[x][y];
    }
    return 0;
}

// Sample input
// 5 6
// ...D.#
// .##..#
// ....#.
// .R#...
// .#.##.