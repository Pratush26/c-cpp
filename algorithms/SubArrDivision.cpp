#include <bits/stdc++.h>
using namespace std;

long long ans = INTMAX_MAX;
void subArr(int pos, vector<int> &arr, vector<int> &grp1, vector<int> &grp2){
    if(pos >= arr.size()){
        long long sum1 = 0, sum2 = 0;
        for(int i: grp1) sum1 += i;
        for(int i: grp2) sum2 += i;
        ans = min(ans, abs(sum1-sum2));
        return;
    }
    grp1.push_back(arr[pos]);
    subArr(pos+1, arr, grp1, grp2);
    grp1.pop_back();
    
    grp2.push_back(arr[pos]);
    subArr(pos+1, arr, grp1, grp2);
    grp2.pop_back();
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> arr(n), grp1, grp2;
    for (int i = 0; i < n; i++) cin >> arr[i];
    subArr(0, arr, grp1, grp2);
    cout << ans;
    return 0;
}
// Sample input
// 5
// 5 2 3 1 4