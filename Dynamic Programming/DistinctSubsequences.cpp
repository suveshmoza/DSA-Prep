// Recursive
class Solution {
   public:
    int minDistance(string word1, string word2) {
        int n = word1.length(), m = word2.length();
        vector<int> prev(m + 1, 0), curr(m + 1, 0);
        for (int j = 0; j <= m; j++) {
            prev[j] = j;
        }
        for (int i = 1; i <= n; i++) {
            curr[0] = i;
            for (int j = 1; j <= m; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    curr[j] = prev[j - 1];
                } else {
                    int insertChar = curr[j - 1];
                    int deleteChar = prev[j];
                    int replaceChar = prev[j - 1];
                    curr[j] = 1 + min(insertChar, min(deleteChar, replaceChar));
                }
            }
            prev = curr;
        }
        return prev[m];
    }
};

// Memo
class Solution {
   public:
    int solve(string s, string t, int n, int m, vector<vector<int>>& dp) {
        if (m < 0) return 1;
        if (n < 0) return 0;
        if (dp[n][m] != -1) return dp[n][m];
        if (s[n] == t[m]) {
            return dp[n][m] = solve(s, t, n - 1, m - 1, dp) + solve(s, t, n - 1, m, dp);
        } else {
            return dp[n][m] = solve(s, t, n - 1, m, dp);
        }
    }

    int numDistinct(string s, string t) {
        int n = s.length(), m = t.length();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solve(s, t, n - 1, m - 1, dp);
    }
};

// Tabulation
class Solution {
   public:
    int numDistinct(string s, string t) {
        int n = s.length(), m = t.length();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s[i - 1] == t[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[n][m];
    }
};

// Best
class Solution {
   public:
    int numDistinct(string s, string t) {
        int n = s.length(), m = t.length();
        vector<int> prev(m + 1, 0), curr(m + 1, 0);
        prev[0] = 1;
        for (int i = 1; i <= n; i++) {
            curr[0] = 1;
            for (int j = 1; j <= m; j++) {
                if (s[i - 1] == t[j - 1]) {
                    curr[j] = prev[j - 1] + prev[j];
                } else {
                    curr[j] = prev[j];
                }
            }
            prev = curr;
        }
        return prev[m];
    }
};