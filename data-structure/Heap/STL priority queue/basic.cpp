#include <bits/stdc++.h>
using namespace std;

int main() {
    priority_queue<int> pq;
    // priority_queue<int, vector<int>, greater<int>> pq;  //  minimum priority queue
    pq.push(30);
    pq.push(90);
    pq.push(40);
    pq.push(20);
    pq.push(10);
    cout << pq.top();
    return 0;
}