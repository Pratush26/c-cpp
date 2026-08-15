#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    // cout << "Enter A Number: ";
    cin >> n;
    vector<bool> isPrime(n+1, true);
    for (int i = 2; i <= n; i++)
    {
        if(!isPrime[i]) continue;
        cout << i << " ";
        for (int j = i+i; j <= n; j += i)
        {
            isPrime[j] = false;
        }
        
    }
    
    return 0;
}