int maxIncreasingDumbbellsSum(vector<int> &nums, int n) {
    vector<int> dp(nums.begin(), nums.end());

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[i] > nums[j]) {
                dp[i] = max(dp[i], dp[j] + nums[i]);
            }
        }
    }
    int maxi = INT_MIN;
    for (int i = 0; i < n; i++) {
        maxi = max(maxi, dp[i]);
    }
    return maxi;
}