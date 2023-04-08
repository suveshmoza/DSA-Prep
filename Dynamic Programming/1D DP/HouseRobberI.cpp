// Brute
int solve(vector<int> arr, int i) {
    if (i >= arr.size()) return 0;
    return max(arr[i] + solve(arr, i + 2), solve(arr, i + 1));
}

int maxAdjSum(vector<int> arr) {
    return solve(arr, 0);
}

// Memo
int solve(vector<int> arr, int i, vector<int>& dp) {
    if (i >= arr.size()) return 0;
    if (dp[i] != -1) return dp[i];
    return dp[i] = max(arr[i] + solve(arr, i + 2, dp), solve(arr, i + 1, dp));
}

int maxAdjSum(vector<int> arr) {
    vector<int> dp(arr.size(), -1);
    return solve(arr, 0, dp);
}

// Tabulation
int maxAdjSum(vector<int> arr) {
    int n = arr.size();
    vector<int> dp(n);
    dp[0] = arr[0];
    for (int i = 0; i < n; i++) {
        int take = arr[i] + (i > 1 ? dp[i - 2] : 0);
        int noTake = dp[i - 1];
        dp[i] = max(take, noTake);
    }
    return dp[n - 1];
}

// Best
int maxAdjSum(vector<int> arr) {
    int n = arr.size();
    int prev1 = arr[0], prev2 = 0;
    for (int i = 0; i < n; i++) {
        int take = arr[i] + (i > 1 ? prev2 : 0);
        int noTake = prev1;
        int curr = max(take, noTake);
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}
