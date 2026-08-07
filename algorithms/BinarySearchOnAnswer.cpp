#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        ll h, n, l = 1, r = 4e10, mid, ans = 0;
        cin >> h >> n;
        ll arr[n], rest[n];
        for (int i = 0; i < n; i++) cin >> arr[i];
        for (int i = 0; i < n; i++) cin >> rest[i];
        auto ok = [&](ll mid) {
            ll cnt = 0;
            for (int i = 0; i < n; i++) {
                cnt += (1 + (mid - 1) / rest[i]) * arr[i];
                if (cnt >= h) return true;
            }
            return false;
        };
    
        while (l<=r){
            mid = l + (r-l)/2;
            if (ok(mid))
            {
                ans = mid;
                r = mid - 1;
            } else l = mid + 1;
        }
        
        cout << ans << "\n";
    }
    return 0;
}