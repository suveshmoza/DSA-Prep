int dp[101][101];

bool isPallindrome(string X, int i, int j) {
    while (i <= j) {
        if (X[i] != X[j])
            return false;
        i++, j--;
    }
    return true;
}

int PalindromePartitioning(string s, int i, int j) {
    if (i >= j || isPallindrome(s, i, j)) return 0;
    if (dp[i][j]) return dp[i][j];
    int ans = INT_MAX;
    for (int k = i; k < j; k++) {
        int left, right;
        if (!dp[i][k]) {
            left = PalindromePartitioning(s, i, k);
        } else {
            left = dp[i][k];
        }
        if (!dp[k + 1][j]) {
            right = PalindromePartitioning(s, k + 1, j);
        } else {
            right = dp[k + 1][j];
        }
        ans = min(ans, left + right + 1);
    }
    return dp[i][j] = ans;
}

int palindromePartitioning(string s) {
    memset(dp, 0, sizeof(dp));
    return PalindromePartitioning(s, 0, s.length() - 1);
}
