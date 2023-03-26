// Recursion
class Solution {
   public:
    int solve(string text1, string text2, int n, int m) {
        if (n < 0 || m < 0) return 0;
        if (text1[n] == text2[m]) {
            return 1 + solve(text1, text2, n - 1, m - 1);
        }
        return max(solve(text1, text2, n - 1, m), solve(text1, text2, n, m - 1));
    }

    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length(), m = text2.length();
        return solve(text1, text2, n - 1, m - 1);
    }
};

// Memo
class Solution {
   public:
    int solve(string text1, string text2, int n, int m, vector<vector<int>>& dp) {
        if (dp[n][m] != -1) return dp[n][m];
        // base case was occuring at -ve indexes but we can't
        // have negative indexes so we increment our indexes
        if (n == 0 || m == 0) return 0;
        if (text1[n - 1] == text2[m - 1]) {
            return dp[n][m] = 1 + solve(text1, text2, n - 1, m - 1, dp);
        }
        return dp[n][m] = max(solve(text1, text2, n - 1, m, dp), solve(text1, text2, n, m - 1, dp));
    }

    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length(), m = text2.length();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return solve(text1, text2, n, m, dp);
    }
};

// Tabulation
class Solution {
   public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length(), m = text2.length();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                if (i == 0 || j == 0) {
                    dp[i][j] = 0;
                } else if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[n][m];
    }
};

// Best
class Solution {
   public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length(), m = text2.length();
        vector<int> prev(m + 1, 0), curr(m + 1, 0);
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                if (i == 0 || j == 0) {
                    curr[j] = 0;
                } else if (text1[i - 1] == text2[j - 1]) {
                    curr[j] = 1 + prev[j - 1];
                } else {
                    curr[j] = max(prev[j], curr[j - 1]);
                }
            }
            prev = curr;
        }
        return prev[m];
    }
};