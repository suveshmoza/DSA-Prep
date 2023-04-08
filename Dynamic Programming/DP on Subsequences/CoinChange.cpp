// Memo
int solve(vector<int>& coins, int n, int amount, vector<vector<int>>& dp) {
    if (n == 0) {
        return amount % coins[0] == 0;
    }
    if (dp[n][amount] != -1) return dp[n][amount];
    int notTake = solve(coins, n - 1, amount, dp);
    int take = 0;
    if (coins[n] <= amount) {
        take = solve(coins, n, amount - coins[n], dp);
    }
    return dp[n][amount] = take + notTake;
}

int change(int amount, vector<int>& coins) {
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
    return solve(coins, n - 1, amount, dp);
}

// Tabulation
int change(int T, vector<int>& arr) {
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(T + 1, 0));
    for (int i = 0; i <= T; i++) {
        if (i % arr[0] == 0) dp[0][i] = 1;
    }
    for (int ind = 1; ind < n; ind++) {
        for (int target = 0; target <= T; target++) {
            int notTaken = dp[ind - 1][target];
            int taken = 0;
            if (arr[ind] <= target)
                taken = dp[ind][target - arr[ind]];
            dp[ind][target] = notTaken + taken;
        }
    }
    return dp[n - 1][T];
}

// Best
int change(int T, vector<int>& arr) {
    vector<int> prev(T + 1, 0);
    for (int i = 0; i <= T; i++) {
        if (i % arr[0] == 0) prev[i] = 1;
    }
    for (int ind = 1; ind < n; ind++) {
        vector<int> cur(T + 1, 0);
        for (int target = 0; target <= T; target++) {
            int notTaken = prev[target];
            int taken = 0;
            if (arr[ind] <= target) taken = cur[target - arr[ind]];
            cur[target] = notTaken + taken;
        }
        prev = cur;
    }

    return prev[T];
}
