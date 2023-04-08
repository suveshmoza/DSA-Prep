// Memo
int solve(vector<int> w, vector<int> v, int n, int maxWeight, vector<vector<int>>& dp) {
    if (n == 0) {
        if (w[0] <= maxWeight)
            return v[0];
        else
            return 0;
    }
    if (dp[n][maxWeight] != -1) return dp[n][maxWeight];
    int notTaken = solve(w, v, n - 1, maxWeight, dp);
    int taken = INT_MIN;
    if (w[n] <= maxWeight) {
        taken = v[n] + solve(w, v, n - 1, maxWeight - w[n], dp);
    }
    return dp[n][maxWeight] = max(notTaken, taken);
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) {
    vector<vector<int>> dp(n, vector<int>(maxWeight + 1, -1));
    return solve(weight, value, n - 1, maxWeight, dp);
}

// Tabulation
int knapsack(vector<int>& wt, vector<int>& val, int n, int W) {
    vector<vector<int>> dp(n, vector<int>(W + 1, 0));
    for (int i = wt[0]; i <= W; i++) dp[0][i] = val[0];
    for (int i = 1; i < n; i++) {
        for (int cap = 0; cap <= W; cap++) {
            int notTaken = dp[i - 1][cap];
            int taken = INT_MIN;
            if (wt[i] <= cap) {
                taken = val[i] + dp[i - 1][cap - wt[i]];
            }
            dp[i][cap] = max(notTaken, taken);
        }
    }
    return dp[n - 1][W];
}

// Best
int knapsack(vector<int>& wt, vector<int>& val, int n, int W) {
    vector<int> prev(W + 1, 0), curr(W + 1, 0);
    for (int i = wt[0]; i <= W; i++) prev[i] = val[0];
    for (int i = 1; i < n; i++) {
        for (int cap = 0; cap <= W; cap++) {
            int notTaken = prev[cap];
            int taken = INT_MIN;
            if (wt[i] <= cap) {
                taken = val[i] + prev[cap - wt[i]];
            }
            curr[cap] = max(notTaken, taken);
        }
        prev = curr;
    }
    return prev[W];
}