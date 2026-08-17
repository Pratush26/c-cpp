// Smallest Prime Factorization
// nlog(long(n))
#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) cin >> arr[i];
        
        for (int i = 0; i < n; i++)
        {
            cout << "For: " << arr[i] << "\n";
            map<int, int> mp;
            for (int j = 2; j*j <= arr[i]; j++)
            {
                if(arr[i]%j == 0){
                    while (arr[i]%j == 0)
                    {
                        mp[j]++;
                        arr[i] /= j;
                    }
                }
            }
            if(arr[i] > 1) mp[arr[i]]++;
            for(auto it: mp)cout << it.first << " -> " << it.second << "\n";
            cout << "\n";
        }
    }
    return 0;
}
// Sample input
// 1
// 6
// 3 6 1 7 8 12