// Memo
class Solution {
   public:
    int solve(vector<int>& prices, int i, int buy, vector<vector<int>>& dp) {
        if (i == prices.size()) {
            return 0;
        }
        if (dp[i][buy] != -1) return dp[i][buy];
        int profit = 0;
        if (buy) {
            profit = max(-prices[i] + solve(prices, i + 1, !buy, dp), 0 + solve(prices, i + 1, buy, dp));

        } else {
            profit = max(prices[i] + solve(prices, i + 1, !buy, dp), 0 + solve(prices, i + 1, buy, dp));
        }
        return dp[i][buy] = profit;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return solve(prices, 0, 1, dp);
    }
};

// Tabulation
class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));
        dp[n][0] = dp[n][1] = 0;
        for (int i = n - 1; i >= 0; i--) {
            for (int buy = 0; buy <= 1; buy++) {
                int profit = 0;
                if (buy) {
                    profit = max(-prices[i] + dp[i + 1][!buy], dp[i + 1][buy]);

                } else {
                    profit = max(prices[i] + dp[i + 1][!buy], dp[i + 1][buy]);
                }
                dp[i][buy] = profit;
            }
        }
        return dp[0][1];
    }
};

// Best
class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));
        vector<int> prev(2, 0), curr(2, 0);
        prev[0] = prev[1] = 0;
        for (int i = n - 1; i >= 0; i--) {
            for (int buy = 0; buy <= 1; buy++) {
                int profit = 0;
                if (buy) {
                    profit = max(-prices[i] + prev[!buy], prev[buy]);

                } else {
                    profit = max(prices[i] + prev[!buy], prev[buy]);
                }
                curr[buy] = profit;
            }
            prev = curr;
        }
        return prev[1];
    }
};