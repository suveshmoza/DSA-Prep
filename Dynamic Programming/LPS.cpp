// Recursion
class Solution {
   public:
    int solve(string s1, string s2, int n, int m) {
        if (n < 0 || m < 0) return 0;
        if (s1[n] == s2[m]) {
            return 1 + solve(s1, s2, n - 1, m - 1);
        }
        return max(solve(s1, s2, n - 1, m), solve(s1, s2, n, m - 1));
    }

    int longestPalindromeSubseq(string s) {
        string s1 = s;
        reverse(s.begin(), s.end());
        return solve(s1, s, s.length() - 1, s.length() - 1);
    }
};

// Memo
class Solution {
   public:
    int solve(string s1, string s2, int n, int m, vector<vector<int>>& dp) {
        if (n == 0 || m == 0) return 0;
        if (s1[n - 1] == s2[m - 1]) {
            return dp[n][m] = 1 + solve(s1, s2, n - 1, m - 1, dp);
        }
        return dp[n][m] = max(solve(s1, s2, n - 1, m, dp), solve(s1, s2, n, m - 1, dp));
    }

    int longestPalindromeSubseq(string s) {
        string s1 = s;
        reverse(s.begin(), s.end());
        vector<vector<int>> dp(s.length() + 1, vector<int>(s.length() + 1, -1));
        return solve(s1, s, s.length(), s.length(), dp);
    }
};

// Tabulation
class Solution {
   public:
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        string s1 = s;
        reverse(s.begin(), s.end());
        string s2 = s;
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[n][n];
    }
};

// Best
class Solution {
   public:
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        string s1 = s;
        reverse(s.begin(), s.end());
        string s2 = s;
        vector<int> prev(n + 1, 0), curr(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    curr[j] = 1 + prev[j - 1];
                } else {
                    curr[j] = max(prev[j], curr[j - 1]);
                }
            }
            prev = curr;
        }
        return curr[n];
    }
};