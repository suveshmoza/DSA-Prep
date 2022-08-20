bool isSafe(vector<vector<int>> &grid, int i, int j, int m, int n) {
    return (i >= 0 and i < m and j >= 0 and j < n and grid[i][j] == 1);
}

void bfs(queue<pair<int, int>> &q, vector<vector<int>> &grid, int m, int n, int &timer) {
    while (q.empty() == false) {
        int size = q.size();
        timer++;
        for (int srt = 0; srt < size; srt++) {
            auto c = q.front();
            q.pop();
            int i = c.first, j = c.second;
            if (isSafe(grid, i, j + 1, m, n) == true) {
                q.push({i, j + 1});
                grid[i][j + 1] = -1;
            }
            if (isSafe(grid, i + 1, j, m, n) == true) {
                q.push({i + 1, j});
                grid[i + 1][j] = -1;
            }
            if (isSafe(grid, i - 1, j, m, n) == true) {
                q.push({i - 1, j});
                grid[i - 1][j] = -1;
            }
            if (isSafe(grid, i, j - 1, m, n) == true) {
                q.push({i, j - 1});
                grid[i][j - 1] = -1;
            }
        }
    }
}
int orangesRotting(vector<vector<int>> &grid) {
    queue<pair<int, int>> q;
    int timer = -1, m = grid.size(), n = grid[0].size();
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[i].size(); j++) {
            if (grid[i][j] == 2) {
                q.push({i, j});
                grid[i][j] = -1;
            }
        }
    }
    bfs(q, grid, m, n, timer);
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[i].size(); j++) {
            if (grid[i][j] == 1)
                return -1;
        }
    }
    return timer;
}