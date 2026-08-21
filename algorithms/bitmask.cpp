#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    // O(n*2^n)
    for (int i = 0; i < (1 << n); i++)
    {
        cout << i << " -> ";
        for (int j = 0; j < n; j++) cout << ((i >> j)&1 ? "1" : "0");
        cout << "\n";
    }
    return 0;
}