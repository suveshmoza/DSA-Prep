#include <bits/stdc++.h>
int f(int indx, int k, vector<int>& arr, vector<vector<int>>& dp) {
    if (indx == 0) {
        if (k == 0 && arr[0] == 0)
            return 2;
        else if (k == 0 || k == arr[0])
            return 1;
        return 0;
    };
    if (dp[indx][k] != -1) return dp[indx][k];
    int notake = f(indx - 1, k, arr, dp);
    int take = 0;
    if (arr[indx] <= k)
        take = f(indx - 1, k - arr[indx], arr, dp);
    return dp[indx][k] = take + notake;
}

int findWays(vector<int>& num, int tar) {
    int n = num.size();
    vector<vector<int>> dp(n, vector<int>(tar + 1, -1));
    return f(n - 1, tar, num, dp);
}