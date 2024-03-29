// Memo
int solve(int price[], int ind, int N, vector<vector<int>>& dp) {
    if (ind == 0) {
        return N * price[0];
    }
    if (dp[ind][N] != -1)
        return dp[ind][N];
    int notTaken = 0 + solve(price, ind - 1, N, dp);
    int taken = INT_MIN;
    int rodLength = ind + 1;
    if (rodLength <= N) taken = price[ind] + solve(price, ind, N - rodLength, dp);
    return dp[ind][N] = max(notTaken, taken);
}

int cutRod(int price[], int N) {
    vector<vector<int>> dp(N, vector<int>(N + 1, -1));
    return solve(price, N - 1, N, dp);
}

// Tabulation
int cutRod(vector<int>& price, int N) {
    vector<vector<int>> dp(N, vector<int>(N + 1, -1));

    for (int i = 0; i <= N; i++) {
        dp[0][i] = i * price[0];
    }

    for (int ind = 1; ind < N; ind++) {
        for (int length = 0; length <= N; length++) {
            int notTaken = 0 + dp[ind - 1][length];

            int taken = INT_MIN;
            int rodLength = ind + 1;
            if (rodLength <= length)
                taken = price[ind] + dp[ind][length - rodLength];

            dp[ind][length] = max(notTaken, taken);
        }
    }

    return dp[N - 1][N];
}

// Best
int cutRod(vector<int>& price, int N) {
    vector<int> cur(N + 1, 0);

    for (int i = 0; i <= N; i++) {
        cur[i] = i * price[0];
    }

    for (int ind = 1; ind < N; ind++) {
        for (int length = 0; length <= N; length++) {
            int notTaken = cur[length];
            int taken = INT_MIN;
            int rodLength = ind + 1;
            if (rodLength <= length)
                taken = price[ind] + cur[length - rodLength];
            cur[length] = max(notTaken, taken);
        }
    }

    return cur[N];
}