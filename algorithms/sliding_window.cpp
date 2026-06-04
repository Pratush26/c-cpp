#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n, k, ans = 0;
    cin >> n >> k;

    ll arr[n], sum = 0;
    for (int i = 0; i < n; i++) cin >> arr[i];
    int l = 0, r = 0;
    while (r < n)
    {
        sum += arr[r];
        while(sum >= k){
            sum -= arr[l];
            l++;
            ans += n-r;
        }
        r++;
    }
    cout << ans;
    return 0;
}