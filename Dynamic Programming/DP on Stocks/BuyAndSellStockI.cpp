class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX, maxProfit = INT_MIN;
        for (auto price : prices) {
            minPrice = min(minPrice, price);
            maxProfit = max(maxProfit, price - minPrice);
        }
        return maxProfit;
    }
};