#include <bits/stdc++.h>
using namespace std;
#define ll long long

void subArr(int pos, vector<ll> &arr, vector<ll> &taken){
    if(pos >= arr.size()){
        for(ll i: taken) cout << i << " ";
        cout << "\n";
        return;
    }
    taken.push_back(arr[pos]);
    subArr(pos+1, arr, taken);
    taken.pop_back();
    subArr(pos+1, arr, taken);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<ll> arr(n), taken;
    for (int i = 0; i < n; i++) cin >> arr[i];
    subArr(0, arr, taken);
    return 0;
}
// Sample input
// 5
// 1 2 3 4 5