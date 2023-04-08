// Brute
int climbStairs(int n) {
    if (n <= 1) return 1;
    return (climbStairs(n - 1) + climbStairs(n - 2));
}

// Memo
int solve(int n, vector<int>& dp) {
    if (n <= 1) return 1;
    if (dp[n] != -1) return dp[n];
    return dp[n] = solve(n - 1, dp) + solve(n - 2, dp);
}
int climbStairs(int n) {
    vector<int> dp(n + 1, -1);
    return solve(n, dp);
}

// Tabulation
int climbStairs(int n) {
    vector<int> dp(n + 1, -1);
    dp[0] = dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

// Best

int climbStairs(int n) {
    vector<int> dp(n + 1, -1);
    int oneStep = 1, twoStep = 1;
    int currStep = 1;
    for (int i = 2; i <= n; i++) {
        currStep = oneStep + twoStep;
        oneStep = twoStep;
        twoStep = currStep;
    }
    return currStep;
}
