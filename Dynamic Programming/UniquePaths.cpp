// Recursion
class Solution {
   public:
    int solve(int n, int m) {
        if (n == 0 && m == 0) return 1;
        if (n < 0 || m < 0) return 0;
        return solve(n - 1, m) + solve(n, m - 1);
    }

    int uniquePaths(int m, int n) {
        return solve(m - 1, n - 1);
    }
};

// Memo
class Solution {
   public:
    int solve(int n, int m, vector<vector<int>>& dp) {
        if (n == 0 && m == 0) return 1;
        if (n < 0 || m < 0) return 0;
        if (dp[n][m] != -1) return dp[n][m];
        return dp[n][m] = solve(n - 1, m, dp) + solve(n, m - 1, dp);
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(m - 1, n - 1, dp);
    }
};

// Tabulation
class Solution {
   public:
    int countWaysUtil(int m, int n, vector<vector<int>>& dp) {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) {
                    dp[i][j] = 1;
                } else {
                    int up = 0, left = 0;
                    if (i > 0)
                        up = dp[i - 1][j];
                    if (j > 0)
                        left = dp[i][j - 1];
                    dp[i][j] = up + left;
                }
            }
        }
        return dp[m - 1][n - 1];
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return countWaysUtil(m, n, dp);
    }
};

// Best
class Solution {
   public:
    int uniquePaths(int m, int n) {
        vector<int> prev(n, 0);
        for (int i = 0; i < m; i++) {
            vector<int> temp(n, 0);
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) {
                    temp[j] = 1;
                } else {
                    int up = 0, left = 0;
                    if (i > 0)
                        up = prev[j];
                    if (j > 0)
                        left = temp[j - 1];
                    temp[j] = up + left;
                }
            }
            prev = temp;
        }
        return prev[n - 1];
    }
};