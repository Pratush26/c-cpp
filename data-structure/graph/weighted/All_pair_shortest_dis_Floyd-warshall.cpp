#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, q;
    cin >> n >> m >> q;

    const long long INF = 1e18;
    vector<vector<long long>> dist(n, vector<long long>(n, INF));

    for (int i = 0; i < n; i++) dist[i][i] = 0;

    while (m--){
        int a, b;
        long long c;
        cin >> a >> b >> c;
        a--;
        b--;
        dist[a][b] = min(dist[a][b], c);
        dist[b][a] = min(dist[b][a], c);    //  for undirected graph
    }

    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];

    bool cycle = false;
    for (int i = 0; i < n; i++) if (dist[i][i] < 0) cycle = true;
    if (cycle){
        cout << "Negative weighted cycle detected";
        return 0;
    }

    while (q--){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        cout << (dist[a][b] == INF ? -1 : dist[a][b]) << '\n';
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