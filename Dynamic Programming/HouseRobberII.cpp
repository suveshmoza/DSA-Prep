class Solution {
   public:
    int maxAdjSum(vector<int> arr) {
        int n = arr.size();
        int prev1 = arr[0], prev2 = 0;
        for (int i = 0; i < n; i++) {
            int take = arr[i] + (i > 1 ? prev2 : 0);
            int noTake = prev1;
            int curr = max(take, noTake);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }

    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        vector<int> a(nums.begin(), nums.end() - 1), b(nums.begin() + 1, nums.end());
        int withoutLast = maxAdjSum(a);
        int withoutFirst = maxAdjSum(b);
        return max(withoutLast, withoutFirst);
    }
};