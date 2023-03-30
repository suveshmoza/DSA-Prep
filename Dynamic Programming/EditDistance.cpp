// Recursive
class Solution {
   public:
    int solve(string text1, string text2, int n, int m) {
        if (n < 0) return m + 1;
        if (m < 0) return n + 1;
        if (text1[n] == text2[m]) {
            return solve(text1, text2, n - 1, m - 1);
        }
        int insertChar = solve(text1, text2, n, m - 1);
        int deleteChar = solve(text1, text2, n - 1, m);
        int replaceChar = solve(text1, text2, n - 1, m - 1);
        ;
        return 1 + min(insertChar, min(deleteChar, replaceChar));
    }

    int minDistance(string word1, string word2) {
        int n = word1.length(), m = word2.length();
        return solve(word1, word2, n - 1, m - 1);
    }
};

// Memo
class Solution {
   public:
    int solve(string text1, string text2, int n, int m, vector<vector<int>>& dp) {
        if (n < 0) return m + 1;
        if (m < 0) return n + 1;
        if (dp[n][m] != -1) return dp[n][m];
        if (text1[n] == text2[m]) {
            return dp[n][m] = solve(text1, text2, n - 1, m - 1, dp);
        }
        int insertChar = solve(text1, text2, n, m - 1, dp);
        int deleteChar = solve(text1, text2, n - 1, m, dp);
        int replaceChar = solve(text1, text2, n - 1, m - 1, dp);
        return dp[n][m] = 1 + min(insertChar, min(deleteChar, replaceChar));
    }

    int minDistance(string word1, string word2) {
        int n = word1.length(), m = word2.length();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solve(word1, word2, n - 1, m - 1, dp);
    }
};

// Tabulation
class Solution {
   public:
    int minDistance(string word1, string word2) {
        int n = word1.length(), m = word2.length();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int i = 0; i <= n; i++) {
            dp[i][0] = i;
        }
        for (int j = 0; j <= m; j++) {
            dp[0][j] = j;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    int insertChar = dp[i][j - 1];
                    int deleteChar = dp[i - 1][j];
                    int replaceChar = dp[i - 1][j - 1];
                    dp[i][j] = 1 + min(insertChar, min(deleteChar, replaceChar));
                }
            }
        }
        return dp[n][m];
    }
};

// Best
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