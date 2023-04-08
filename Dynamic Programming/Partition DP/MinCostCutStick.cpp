class Solution {
   public:
    int dfs(int i, int j, vector<int>& cuts, int n, vector<vector<int>>& dp) {
        if (i > j) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        int ans = INT_MAX;
        for (int k = i; k <= j; k++) {
            int curr = cuts[j + 1] - cuts[i - 1] + dfs(i, k - 1, cuts, n, dp) + dfs(k + 1, j, cuts, n, dp);
            ans = min(ans, curr);
        }
        return dp[i][j] = ans;
    }

    int minCost(int n, vector<int>& cuts) {
        int c = cuts.size();
        cuts.emplace_back(n);
        cuts.insert(begin(cuts), 0);
        sort(begin(cuts), end(cuts));
        vector<vector<int>> dp(c + 1, vector<int>(c + 1, -1));
        return dfs(1, c, cuts, n, dp);
    }
};