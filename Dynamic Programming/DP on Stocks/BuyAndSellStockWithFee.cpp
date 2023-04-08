class Solution {
   public:
    int solve(vector<int>& prices, int i, int buy, int fee, vector<vector<int>>& dp) {
        if (i == prices.size()) {
            return 0;
        }
        if (dp[i][buy] != -1) return dp[i][buy];
        int profit = 0;
        if (buy) {
            profit = max(-prices[i] + solve(prices, i + 1, !buy, fee, dp), 0 + solve(prices, i + 1, buy, fee, dp));
        } else {
            profit = max(prices[i] + solve(prices, i + 1, !buy, fee, dp) - fee, 0 + solve(prices, i + 1, buy, fee, dp));
        }
        return dp[i][buy] = profit;
    }

    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return solve(prices, 0, 1, fee, dp);
    }
};