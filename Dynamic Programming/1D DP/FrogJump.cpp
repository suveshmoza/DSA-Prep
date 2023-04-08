// Brute
int solve(vector<int> arr, int i) {
    if (i <= 0) return 0;
    int twoJump = INT_MAX;
    int oneJump = solve(arr, i - 1) + abs(arr[i] - arr[i - 1]);
    if (i > 1) {
        twoJump = solve(arr, i - 2) + abs(arr[i] - arr[i - 2]);
    }
    return min(oneJump, twoJump);
}

int frogJump(vector<int> arr, int n) {
    return solve(arr, n - 1);
}

// Memo
int solve(vector<int> arr, int i, vector<int> &dp) {
    if (i <= 0) return 0;
    if (dp[i] != -1) return dp[i];
    int twoJump = INT_MAX;
    int oneJump = solve(arr, i - 1, dp) + abs(arr[i] - arr[i - 1]);
    if (i > 1) twoJump = solve(arr, i - 2, dp) + abs(arr[i] - arr[i - 2]);
    return dp[i] = min(oneJump, twoJump);
}

int frogJump(int n, vector<int> &heights) {
    vector<int> dp(n, -1);
    return solve(heights, n - 1, dp);
}

// Tabulation

int frogJump(int n, vector<int> &heights) {
    vector<int> dp(n, 0);
    // dp[0]=0;
    for (int i = 1; i < n; i++) {
        int oneJump = dp[i - 1] + abs(heights[i] - heights[i - 1]);
        int twoJump = INT_MAX;
        if (i > 1) twoJump = dp[i - 2] + abs(heights[i] - heights[i - 2]);
        dp[i] = min(oneJump, twoJump);
    }
    return dp[n - 1];
}

// Best
#include <bits/stdc++.h>
int frogJump(int n, vector<int> &heights) {
    int prev1 = 0, prev2 = 0;
    for (int i = 1; i < n; i++) {
        int oneJump = prev1 + abs(heights[i] - heights[i - 1]);
        int twoJump = INT_MAX;
        if (i > 1) twoJump = prev2 + abs(heights[i] - heights[i - 2]);
        int curr = min(oneJump, twoJump);
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}