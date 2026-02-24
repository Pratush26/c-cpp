#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, mx[] = {1, 2, 2, 1, -1, -2, -2, -1}, my[] = {-2, -1, 1, 2, 2, 1, -1, -2};
    cin >> t;
    while (t--) {
        int r, c;
        cin >> r >> c;
        int rx, ry, qx, qy;
        cin >> rx >> ry >> qx >> qy;

        vector<vector<int>> dist(r, vector<int>(c, -1));
        queue<pair<int,int>> qu;
        qu.push({rx, ry});
        dist[rx][ry] = 0;

        while (!qu.empty()) {
            auto [x, y] = qu.front();
            qu.pop();
            if (x == qx && y == qy) break;
            for (int i = 0; i < 8; i++) {
                int nx = x + mx[i];
                int ny = y + my[i];
                if (nx < 0 || ny < 0 || nx >= r || ny >= c || dist[nx][ny] != -1) continue;
                dist[nx][ny] = dist[x][y] + 1;
                qu.push({nx, ny});
            }
        }
        cout << dist[qx][qy] << "\n";
    }
    return 0;
}

// Sample input
// 4
// 8 8
// 0 0
// 7 7
// 5 6
// 0 1
// 0 1
// 4 4
// 0 0
// 0 1
// 2 2
// 0 0
// 0 1