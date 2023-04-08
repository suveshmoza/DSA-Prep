// DP Method
class Solution {
   public:
    int lengthOfLIS(vector<int>& arr) {
        int n = arr.size();
        vector<int> dp(n, 1);
        int ans = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (arr[i] > arr[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};

// Binary Search Method
class Solution {
   public:
    int lowerBound(vector<int> nums, int target) {
        int low = 0, high = nums.size();
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] >= target) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }

    int lengthOfLIS(vector<int>& nums) {
        vector<int> lis;
        lis.push_back(nums[0]);
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > lis.back()) {
                lis.push_back(nums[i]);
            } else {
                int idx = lowerBound(lis, nums[i]);
                lis[idx] = nums[i];
            }
        }
        for (auto i : lis) {
            cout << i << " ";
        }
        cout << endl;
        return lis.size();
    }
};