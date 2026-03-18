#include <bits/stdc++.h>
using namespace std;

int val[1005], weight[1005];
int dp[1005][1005];

int knapsack(int i, int mx_weight){
    if(i<0 || mx_weight <= 0) return 0;
    if(dp[i][mx_weight] != -1) return dp[i][mx_weight];
    if(mx_weight >= weight[i]){
        int op1 = knapsack(i-1, mx_weight - weight[i]) + val[i];
        int op2 = knapsack(i-1, mx_weight);
        dp[i][mx_weight] = max(op1, op2);
        return dp[i][mx_weight];
    }
    else{
        dp[i][mx_weight] = knapsack(i-1, mx_weight);
        return dp[i][mx_weight];
    }
}
int main() {
    int mx_weight, n;
    cin >> n >> mx_weight;
    for (int i = 0; i <= n; i++) for (int j = 0; j <= mx_weight; j++) dp[i][j] = -1;
    for (int i = 0; i < n; i++) cin >> weight[i] >> val[i];
    cout << knapsack(n-1, mx_weight);
    return 0;
}
// Sample input
// 3 8
// 3 30
// 4 50
// 5 60