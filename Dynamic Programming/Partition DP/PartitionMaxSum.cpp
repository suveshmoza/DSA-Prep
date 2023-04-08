class Solution {
   public:
    int f(vector<int>& arr, int i, int n, int k, vector<int>& dp) {
        if (i == n) return 0;
        if (dp[i] != -1) return dp[i];
        int len = 0, maxi = INT_MIN, maxAns = INT_MIN;
        for (int j = i; j < min(n, i + k); j++) {
            len++;
            maxi = max(maxi, arr[j]);
            int curr = (len * maxi) + f(arr, j + 1, n, k, dp);
            maxAns = max(maxAns, curr);
        }
        return dp[i] = maxAns;
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n, -1);
        return f(arr, 0, n, k, dp);
    }
};