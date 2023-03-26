// Recursion
class Solution {
   public:
    int solve(vector<vector<int>>& mat, int i, int j, int n, int m) {
        if (i == n - 1) return mat[i][j];
        int down = mat[i][j] + solve(mat, i + 1, j, n, m, dp);
        int diag = mat[i][j] + solve(mat, i + 1, j + 1, n, m, dp);
        return min(down, diag);
    }

    int minimumTotal(vector<vector<int>>& mat) {
        int n = mat.size();
        return solve(mat, 0, 0, n, n);
    }
};

// Memo
class Solution {
   public:
    int solve(vector<vector<int>>& mat, int i, int j, int n, int m, vector<vector<int>>& dp) {
        if (dp[i][j] != -1) return dp[i][j];
        if (i == n - 1) return mat[i][j];
        int down = mat[i][j] + solve(mat, i + 1, j, n, m, dp);
        int diag = mat[i][j] + solve(mat, i + 1, j + 1, n, m, dp);
        return dp[i][j] = min(down, diag);
    }

    int minimumTotal(vector<vector<int>>& mat) {
        int n = mat.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solve(mat, 0, 0, n, n, dp);
    }
};

// Tabulatioon
class Solution {
   public:
    int minimumTotal(vector<vector<int>>& mat) {
        int n = mat.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            dp[n - 1][i] = mat[n - 1][i];
        }
        for (int i = n - 2; i >= 0; i--) {
            for (int j = i; j >= 0; j--) {
                int down = mat[i][j] + dp[i + 1][j];
                int diag = mat[i][j] + dp[i + 1][j + 1];
                dp[i][j] = min(down, diag);
            }
        }
        return dp[0][0];
    }
};

// Best
class Solution {
   public:
    int minimumTotal(vector<vector<int>>& mat) {
        int n = mat.size();
        vector<int> next(n, 0), temp(n, 0);
        for (int i = 0; i < n; i++) {
            next[i] = mat[n - 1][i];
        }
        for (int i = n - 2; i >= 0; i--) {
            for (int j = i; j >= 0; j--) {
                int down = mat[i][j] + next[j];
                int diag = mat[i][j] + next[j + 1];
                temp[j] = min(down, diag);
            }
            next = temp;
        }
        return next[0];
    }
};