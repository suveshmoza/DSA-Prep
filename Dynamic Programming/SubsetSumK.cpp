// Recursive
bool solve(vector<int> &arr, int n, int k) {
    if (k == 0) return true;
    if (n == 0) return arr[n] == k;
    int dontTake = solve(arr, n - 1, k);
    int take = false;
    if (arr[n] <= k) {
        take = solve(arr, n - 1, k - arr[n]);
    }
    return take || dontTake;
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
    return solve(arr, n - 1, k);
}

// Memo
bool solve(vector<int> &arr, int n, int k, vector<vector<int>> &dp) {
    if (k == 0) return true;
    if (n == 0) return arr[n] == k;
    if (dp[n][k] != -1) return dp[n][k];
    bool dontTake = solve(arr, n - 1, k, dp);
    bool take = false;
    if (arr[n] <= k) {
        take = solve(arr, n - 1, k - arr[n], dp);
    }
    return dp[n][k] = take || dontTake;
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));
    return solve(arr, n - 1, k, dp);
}
// Tabulation
bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<bool>> dp(n, vector<bool>(k + 1, false));
    for (int i = 0; i < n; i++) dp[i][0] = true;
    dp[0][arr[0]] = true;
    for (int i = 1; i < n; i++) {
        for (int target = 1; target <= k; target++) {
            bool notTaken = dp[i - 1][target];
            bool taken = false;
            if (arr[i] <= target) {
                taken = dp[i - 1][target - arr[i]];
            }
            dp[i][target] = taken | notTaken;
        }
    }
    return dp[n - 1][k];
}

// Best
#include <bits/stdc++.h>

bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<bool> prev(k + 1, false);
    prev[0] = true;
    prev[arr[0]] = true;
    for (int i = 1; i < n; i++) {
        vector<bool> curr(k + 1, false);
        curr[0] = true;
        for (int target = 1; target <= k; target++) {
            bool notTaken = prev[target];
            bool taken = false;
            if (arr[i] <= target) {
                taken = prev[target - arr[i]];
            }
            curr[target] = taken | notTaken;
        }
        prev = curr;
    }
    return prev[k];
}