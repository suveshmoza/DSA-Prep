//* Memo
int dp[205][205];
int dfs(vector<vector<int>> &grid, int row, int col, int i, int j) {
    if (i >= row || j >= col) return INT_MAX;
    if (i == row - 1 && j == col - 1) {
        dp[i][j] = grid[i][j];
        return grid[i][j];
    }
    if (dp[i][j] != -1) return dp[i][j];
    return dp[i][j] = grid[i][j] + min(dfs(grid, row, col, i + 1, j), dfs(grid, row, col, i, j + 1));
}

int minSumPath(vector<vector<int>> &grid) {
    memset(dp, -1, sizeof(dp));
    return dfs(grid, grid.size(), grid[0].size(), 0, 0);
}

//* Tabulation
int minSumPath(vector<vector<int>> &grid) {
    int m = grid.size(), n = grid[0].size();
    int dp[m][n];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 && j == 0)
                dp[i][j] = grid[i][j];
            else if (i == 0) {
                dp[i][j] = dp[i][j - 1] + grid[i][j];
            } else if (j == 0) {
                dp[i][j] = dp[i - 1][j] + grid[i][j];
            } else {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
            }
        }
    }
    return dp[m - 1][n - 1];
}