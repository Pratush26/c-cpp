#include <bits/stdc++.h>
using namespace std;

int val[1005], dp[1005][1005];

int knapsack(int i, int sum){
    if(i<0) return sum == 0 ? 1 : 0;
    if(dp[i][sum] != -1) return dp[i][sum];
    if(sum >= val[i]){
        int op1 = knapsack(i-1, sum - val[i]);
        int op2 = knapsack(i-1, sum);
        dp[i][sum] = op1 + op2;
        return dp[i][sum];
    }
    else{
        dp[i][sum] = knapsack(i-1, sum);
        return dp[i][sum];
    }
}
int main() {
    int n, t;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> val[i];
    cin >> t;
    for (int i = 0; i <= n; i++) for (int j = 0; j <= t; j++) dp[i][j] = -1;
    cout << knapsack(n-1, t);
    return 0;
}
// Sample input_iterator_tag
// 5
// 1 2 4 3 5
// 5