// Recursive
class Solution {
   public:
    int solve(vector<vector<int>>& matrix, int i, int j, int n, int m) {
        if (j < 0 || j >= m) return INT_MAX;
        if (i == 0) return matrix[0][j];
        int up = solve(matrix, i - 1, j, n, m);
        int leftDiag = solve(matrix, i - 1, j - 1, n, m);
        int rightDiag = solve(matrix, i - 1, j + 1, n, m);
        return matrix[i][j] + min(up, min(leftDiag, rightDiag));
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        int maxi = INT_MAX;

        for (int i = 0; i < m; i++) {
            int curr = solve(matrix, n - 1, i, n, m);
            maxi = min(maxi, curr);
        }
        return maxi;
    }
};

// Memo
class Solution {
   public:
    int solve(vector<vector<int>>& dp, vector<vector<int>>& matrix, int i, int j, int n, int m) {
        if (j < 0 || j >= m) return INT_MAX;
        if (i == 0) return matrix[0][j];
        if (dp[i][j] != -1) return dp[i][j];
        int up = solve(dp, matrix, i - 1, j, n, m);
        int leftDiag = solve(dp, matrix, i - 1, j - 1, n, m);
        int rightDiag = solve(dp, matrix, i - 1, j + 1, n, m);
        return dp[i][j] = matrix[i][j] + min(up, min(leftDiag, rightDiag));
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        int maxi = INT_MAX;
        vector<vector<int>> dp(n, vector<int>(m, -1));
        for (int i = 0; i < m; i++) {
            int curr = solve(dp, matrix, n - 1, i, n, m);
            maxi = min(maxi, curr);
        }
        return maxi;
    }
};

// Tabulation
class Solution {
   public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        int maxi = INT_MAX;
        vector<vector<int>> dp(n, vector<int>(m, -1));
        for (int i = 0; i < m; i++) {
            dp[0][i] = matrix[0][i];
        }
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int up = dp[i - 1][j];
                int ld = (j - 1 >= 0) ? dp[i - 1][j - 1] : INT_MAX;
                int rd = (j + 1 < m) ? dp[i - 1][j + 1] : INT_MAX;
                dp[i][j] = matrix[i][j] + min(up, min(ld, rd));
            }
        }
        int ans = INT_MAX;
        for (int i = 0; i < m; i++) {
            ans = min(ans, dp[n - 1][i]);
        }
        return ans;
    }
};

// Best
class Solution {
   public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<int> prev(m, 0), curr(m, 0);
        for (int i = 0; i < m; i++) {
            prev[i] = matrix[0][i];
        }
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int up = prev[j];
                int ld = (j - 1 >= 0) ? prev[j - 1] : INT_MAX;
                int rd = (j + 1 < m) ? prev[j + 1] : INT_MAX;
                curr[j] = matrix[i][j] + min(up, min(ld, rd));
            }
            prev = curr;
        }
        int ans = INT_MAX;
        for (int i = 0; i < m; i++) {
            ans = min(ans, prev[i]);
        }
        return ans;
    }
};