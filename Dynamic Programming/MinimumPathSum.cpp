// Recursion
int solve(vector<vector<int>>& grid, int n, int m, int i, int j) {
    if (i < 0 || j < 0) return INT_MAX;
    if (i == 0 && j == 0) return grid[i][j];
    return grid[i][j] + min(solve(grid, n, m, i - 1, j), solve(grid, n, m, i, j - 1));
}

int minSumPath(vector<vector<int>>& grid) {
    int n = grid.size(), m = grid[0].size();
    return solve(grid, n, m, n - 1, m - 1);
}

// Memo
int solve(vector<vector<int>>& grid, int n, int m, int i, int j, vector<vector<int>>& dp) {
    if (i < 0 || j < 0) return INT_MAX;
    if (i == 0 && j == 0) return grid[i][j];
    if (dp[i][j] != -1) return dp[i][j];
    return dp[i][j] = grid[i][j] + min(solve(grid, n, m, i - 1, j, dp), solve(grid, n, m, i, j - 1, dp));
}

int minSumPath(vector<vector<int>>& grid) {
    int n = grid.size(), m = grid[0].size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return solve(grid, n, m, n - 1, m - 1, dp);
}

// Tabulation
#include <bits/stdc++.h>

int minSumPath(vector<vector<int>>& grid) {
    int n = grid.size(), m = grid[0].size();
    vector<vector<int>> dp(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == 0 && j == 0) {
                dp[i][j] = grid[i][j];
            } else {
                int curr = min(i > 0 ? dp[i - 1][j] : INT_MAX, j > 0 ? dp[i][j - 1] : INT_MAX);
                dp[i][j] = grid[i][j] + curr;
            }
        }
    }
    return dp[n - 1][m - 1];
}

// Best
int minSumPath(vector<vector<int>>& grid) {
    int n = grid.size(), m = grid[0].size();
    vector<int> prev(m, 0);
    for (int i = 0; i < n; i++) {
        vector<int> temp(m, 0);
        for (int j = 0; j < m; j++) {
            if (i == 0 && j == 0) {
                temp[j] = grid[i][j];
            } else {
                int curr = min(i > 0 ? prev[j] : INT_MAX, j > 0 ? temp[j - 1] : INT_MAX);
                temp[j] = grid[i][j] + curr;
            }
        }
        prev = temp;
    }
    return prev[m - 1];
}