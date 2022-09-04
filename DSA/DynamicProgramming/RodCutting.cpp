int cutRod(vector<int> &price, int n) {
    vector<int> length(n);
    for (int i = 0; i < n; i++) {
        length[i] = i + 1;
    }
    int dp[n + 1][n + 1];

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (length[i - 1] <= j) {
                dp[i][j] = max(dp[i - 1][j], price[i - 1] + dp[i][j - length[i - 1]]);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[n][n];
}
