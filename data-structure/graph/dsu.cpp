//  Disjoint Set Union
#include <bits/stdc++.h>
using namespace std;

int par[1005];
int group_size[1005];

int find(int n){
    if(par[n] == -1) return n;
    par[n] = find(par[n]);
    return par[n];
}

void dsu_union(int n1, int n2){
    int ledr1 = find(n1);
    int ledr2 = find(n2);
    if(group_size[ledr1] >= group_size[ledr2]){
        par[ledr2] = ledr1;
        group_size[ledr1] += group_size[ledr2];
    }
    else{
        par[ledr1] = ledr2;
        group_size[ledr2] += group_size[ledr1];
    }
}

int main() {
    int n, e, a, b;
    bool cycle = false;
    memset(par, -1, sizeof(par));
    fill(group_size, group_size + 1005, 1);
    cin >> n >> e;
    while (e--){
        cin >> a >> b;
        int ledr1 = find(a);
        int ledr2 = find(b);
        if(ledr1 == ledr2) cycle = true;
        else dsu_union(a, b);
    }
    cout << (cycle ? "Cyle Ditected" : "No Cycle Found") << "\n";
    return 0;
}

// Sample input
// 6 6
// 0 1
// 1 2
// 0 4
// 4 5
// 5 3
// 3 4