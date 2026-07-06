#include <bits/stdc++.h>
using namespace std;

int FBinarySearch(vector<long long>& arr, long long t) {
    int s = 0, e = arr.size() - 1, ans = -1;
    while (s <= e) {
        int mid = s + (e - s) / 2;
        if (arr[mid] < t) {
            s = mid + 1;
        } else {
            ans = mid;
            e = mid - 1;
        }
    }
    return ans;
}
int LBinarySearch(vector<long long>& arr, long long t) {
    int s = 0, e = arr.size() - 1, ans = -1;
    while (s <= e) {
        int mid = s + (e - s) / 2;
        if (arr[mid] <= t) {
            ans = mid;
            s = mid + 1;
        } else {
            e = mid - 1;
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<long long> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr.begin(), arr.end());
    int q;
    cin >> q;
    long long l, r, s, e;
    while (q--)
    {
        cin >> l >> r;
        s = FBinarySearch(arr, l);
        e = LBinarySearch(arr, r);
        cout << max(e-s+1, (long long)0) << " ";
    }
    return 0;
}

// Sample inputs
// 5
// 10 1 10 3 4
// 4
// 1 10
// 2 9
// 3 4
// 2 2