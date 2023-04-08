// Recursive
int solve(vector<int> num, int n, int k) {
    if (k == 0) return 1;
    if (n == 0) return (num[0] == k ? 1 : 0);
    int notTake = solve(num, n - 1, k);
    int take = 0;
    if (num[n] <= k) {
        take = solve(num, n - 1, k - num[n]);
    }
    return take + notTake;
}

int findWays(vector<int> &num, int tar) {
    return solve(num, num.size() - 1, tar);
}

// Memo
#include <bits/stdc++.h>
int findWaysUtil(int ind, int target, vector<int> &arr, vector<vector<int>> &dp) {
    // if(target==0) return 1;
    // Explore more ways because of 0 in the array
    if (ind == 0) {
        if (target == 0 && arr[0] == 0) return 2;
        if (target == 0 || target == arr[0]) return 1;
        return 0;
    }
    if (target == 0) return 1;
    if (dp[ind][target] != -1) return dp[ind][target];
    int notTaken = findWaysUtil(ind - 1, target, arr, dp);
    int taken = 0;
    if (arr[ind] <= target)
        taken = findWaysUtil(ind - 1, target - arr[ind], arr, dp);
    return dp[ind][target] = notTaken + taken;
}

int findWays(vector<int> &num, int tar) {
    int n = num.size();
    vector<vector<int>> dp(n, vector<int>(tar + 1, -1));
    return findWaysUtil(num.size() - 1, tar, num, dp);
}