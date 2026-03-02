#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, e, r, c, val;
    cin >> n >> e;
    int matrx[n][n];
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) matrx[i][j] = i==j ? 0 : INT_MAX;
    while (e--) {
        cin >> r >> c >> val;
        matrx[r][c] = val;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if(matrx[j][i] != INT_MAX && matrx[i][k] != INT_MAX && matrx[j][i] + matrx[i][k] < matrx[j][k]){
                    matrx[j][k] = matrx[j][i] + matrx[i][k];
                }
            }
            
        }
    }
    bool cycle = false;
    for (int i = 0; i < n; i++) if(matrx[i][i]<0) cycle = true;
    if(cycle){
        cout << "Negative weighted cycle detected";
        return 0;
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if(matrx[i][j] == INT_MAX) cout << "i ";
            else cout << matrx[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// Sample input
// 4 5
// 0 1 3
// 2 0 -6
// 1 2 2
// 1 3 5
// 2 3 4