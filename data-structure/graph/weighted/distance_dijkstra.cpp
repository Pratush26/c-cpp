#include <bits/stdc++.h>
using namespace std;

class cmp {
public:
    bool operator()(pair<int, int> a, pair<int, int> b){
        return a.second > b.second;
    }
};

void dijkstra_bfs(int src, vector<pair<int, int>> arr[], vector<int> &distn) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
    distn[src] = 0;
    pq.push({src, 0});

    while (!pq.empty()) {
        pair<int, int> parnt = pq.top();
        int p = parnt.first;
        int pDist = parnt.second;
        pq.pop();
        if (pDist > distn[p]) continue;

        for (pair<int, int> child : arr[p]) {
            int c = child.first;
            int cDist = child.second;

            if (pDist + cDist < distn[c]) {
                distn[c] = pDist + cDist;
                pq.push({c, distn[c]});
            }
        }
    }
}

int main() {
    int n, e, r, c, d;
    cin >> n >> e;
    vector<pair<int, int>> arr[n];
    vector<int> distn(n, INT_MAX);
    while (e--) {
        cin >> r >> c >> d;
        arr[r].push_back({c, d});
        arr[c].push_back({r, d});
    }
    dijkstra_bfs(0, arr, distn);
    for (int i = 0; i < n; i++) cout << i << " -> " << distn[i] << "\n";
    return 0;
}

//  sample input
// 5 8
// 0 1 10
// 1 2 1
// 0 2 7
// 0 3 4
// 2 3 1
// 3 4 5 
// 1 4 3
// 2 4 5