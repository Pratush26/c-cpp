#include <bits/stdc++.h>
using namespace std;

int r, c;

bool valid(int i, int j){
    if(i < 0 || j < 0 || i >= r || j >= c) return false;
    return true;
}
int dfs(int x, int y, vector<vector<bool>> &visited, vector<vector<char>> &grid) {
    if(!valid(x, y) || visited[x][y] || grid[x][y] == '#') return 0;
    visited[x][y] = true;
    int size = 1;
    size += dfs(x, y+1, visited, grid);
    size += dfs(x, y-1, visited, grid);
    size += dfs(x-1, y, visited, grid);
    size += dfs(x+1, y, visited, grid);
    return size;
}

int main() {
    int count = 0;
    cin >> r >> c;
    vector<vector<char>> grid(r, vector<char>(c));
    vector<vector<bool>> visited(r, vector<bool>(c, false));
    for (int i = 0; i < r; i++) for (int j = 0; j < c; j++) cin >> grid[i][j];
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if(grid[i][j] == '.' && !visited[i][j]) {
                cout << dfs(i, j, visited, grid) << " ";
                count++;
            }
        }
    }
    cout << "\nTotal Rooms : " << count;
    return 0;
}