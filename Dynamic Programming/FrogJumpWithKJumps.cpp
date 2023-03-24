// Brute
int frogJump(vector<int>& arr, int n, int k) {
    if (n == 0) return 0;
    int res = INT_MAX;
    for (int jump = 1; jump <= k; jump++) {
        if (n - jump >= 0) {
            int currCost = frogJump(arr, n - jump, k) + abs(arr[n] - arr[n - jump]);
            res = min(res, currCost);
        }
    }
    return res;
}

// Memo
int solve(vector<int>& arr, int n, int k, vector<int>& dp) {
    if (n == 0) return 0;
    if (dp[n] != 0) return dp[n];
    int res = INT_MAX;
    for (int jump = 1; jump <= k; jump++) {
        if (n - jump >= 0) {
            int currCost = solve(arr, n - jump, k, dp) + abs(arr[n] - arr[n - jump]);
            res = min(res, currCost);
        }
    }
    return dp[n] = res;
}

int frogJump(vector<int>& arr, int n, int k) {
    vector<int> dp(n, 0);
    return solve(arr, n - 1, k, dp);
}

// Tabulation
int solve(vector<int>& arr, int n, int k, vector<int>& dp) {
    dp[0] = 0;
    for (int i = 1; i < n; i++) {
        int res = INT_MAX;
        for (int j = 1; j <= k; j++) {
            if (i - j >= 0) {
                int currCost = solve(arr, i - j, k, dp) + abs(arr[i] - arr[i - j]);
                res = min(res, currCost);
            }
        }
        dp[i] = res;
    }
    return dp[n - 1];
}

int frogJump(vector<int>& arr, int n, int k) {
    vector<int> dp(n, 0);
    return solve(arr, n, k, dp);
}