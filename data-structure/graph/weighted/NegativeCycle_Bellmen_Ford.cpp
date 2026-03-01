#include <bits/stdc++.h>
using namespace std;

class Edge {
    public:
    int a, b, c;
    Edge(int a, int b, int c){
        this->a = a;
        this->b = b;
        this->c = c;
    }
};

int n, e;
vector<Edge> edge_list;
bool bellman_ford(vector<int> &dis){
    bool cycle = false;
    for (int i = 1; i < n; i++){
        for(Edge e: edge_list){
            if(dis[e.a] != INT_MAX && (dis[e.a] + e.c < dis[e.b])){
                dis[e.b] = dis[e.a] + e.c;
            }
        }
    }
    for(Edge e: edge_list){
        if(dis[e.a] != INT_MAX && (dis[e.a] + e.c < dis[e.b])){
            cycle = true;
            break;
        }
    }
    return cycle;
}

int main() {
    cin >> n >> e;
    vector<int> dis(n, INT_MAX);
    while (e--) {
        int a, b, c;
        cin >> a >> b >> c;
        edge_list.push_back(Edge(a, b, c));
        // edge_list.push_back(Edge(b, a, c)); //  for undirected graph
    }
    dis[0] = 0;
    if(bellman_ford(dis)) cout << "Negative weighted Cycle Detected";
    else{
        cout << "Cycle Not Found!\n";
        for (int i = 0; i < n; i++) cout << i << " -> " << dis[i] << "\n";
    }
    return 0;
}

// Sample input
// 4 4
// 0 1 5
// 1 2 3
// 2 3 2
// 3 1 -6