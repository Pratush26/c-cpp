#include <bits/stdc++.h>
using namespace std;
#define ll long long int

class cmp {
public:
    bool operator()(pair<ll, ll> a, pair<ll, ll> b){
        return a.second > b.second;
    }
};

void dijkstra_bfs(ll src, vector<pair<ll, ll>> arr[], vector<ll> &distn, vector<ll> &par) {
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, cmp> pq;
    distn[src] = 0;
    pq.push({src, 0});

    while (!pq.empty()) {
        pair<ll, ll> parnt = pq.top();
        ll p = parnt.first;
        ll pDist = parnt.second;
        pq.pop();
        if (pDist > distn[p]) continue;

        for (pair<ll, ll> child : arr[p]) {
            ll c = child.first;
            ll cDist = child.second;

            if (pDist + cDist < distn[c]) {
                distn[c] = pDist + cDist;
                pq.push({c, distn[c]});
                par[c] = p;
            }
        }
    }
}

int main() {
    ll n, e, r, c, d;
    cin >> n >> e;
    vector<pair<ll, ll>> arr[n+1];
    vector<ll> distn(n+1, LLONG_MAX);
    vector<ll> par(n+1, -1);
    while (e--) {
        cin >> r >> c >> d;
        arr[r].push_back({c, d});
        arr[c].push_back({r, d});
    }
    dijkstra_bfs(1, arr, distn, par);
    if(distn[n] == LLONG_MAX) cout << -1;
    else{
        ll node = n;
        stack<ll> st;
        while(node != -1){
            st.push(node);
            node = par[node];
        }
        while(!st.empty()){
            cout << st.top() << " ";
            st.pop();
        }
    }
    return 0;
}
// Sample input
// 5 6
// 1 2 2
// 2 5 5
// 2 3 4
// 1 4 1
// 4 3 3
// 3 5 1