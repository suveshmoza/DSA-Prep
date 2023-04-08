// Memo
class Solution {
   public:
    bool solve(vector<int> &arr, int n, int k, vector<vector<int>> &dp) {
        if (k == 0) return true;
        if (n == 0) return arr[n] == k;
        if (dp[n][k] != -1) return dp[n][k];
        bool dontTake = solve(arr, n - 1, k, dp);
        bool take = false;
        if (arr[n] <= k) {
            take = solve(arr, n - 1, k - arr[n], dp);
        }
        return dp[n][k] = take || dontTake;
    }

    bool canPartition(vector<int> &nums) {
        int sum = 0;
        for (auto i : nums) {
            sum += i;
        }
        if (sum % 2 == 1)
            return false;
        else {
            vector<vector<int>> dp(nums.size(), vector<int>(sum + 1, -1));
            return solve(nums, nums.size() - 1, sum / 2, dp);
        }
    }
};

// Tabulation
class Solution {
   public:
    bool canPartition(vector<int> &arr) {
        int n = arr.size(), totSum = 0;
        for (int i = 0; i < n; i++) {
            totSum += arr[i];
        }
        if (totSum % 2 == 1)
            return false;
        else {
            int k = totSum / 2;
            vector<vector<bool>> dp(n, vector<bool>(k + 1, false));

            for (int i = 0; i < n; i++) {
                dp[i][0] = true;
            }
            if (arr[0] <= k) {
                dp[0][arr[0]] = true;
            }
            for (int ind = 1; ind < n; ind++) {
                for (int target = 1; target <= k; target++) {
                    bool notTaken = dp[ind - 1][target];

                    bool taken = false;
                    if (arr[ind] <= target)
                        taken = dp[ind - 1][target - arr[ind]];

                    dp[ind][target] = notTaken || taken;
                }
            }

            return dp[n - 1][k];
        }
    }
};

// Best
class Solution {
   public:
    bool canPartition(vector<int> &arr) {
        int n = arr.size(), totSum = 0;
        for (int i = 0; i < n; i++) {
            totSum += arr[i];
        }
        if (totSum % 2 == 1)
            return false;
        else {
            int k = totSum / 2;
            vector<bool> prev(k + 1, false);
            for (int i = 0; i < n; i++) {
                prev[0] = true;
            }

            if (arr[0] <= k)
                prev[arr[0]] = true;

            for (int ind = 1; ind < n; ind++) {
                vector<bool> curr(k + 1, false);
                curr[0] = true;
                for (int target = 1; target <= k; target++) {
                    bool notTaken = prev[target];
                    bool taken = false;
                    if (arr[ind] <= target) taken = prev[target - arr[ind]];
                    curr[target] = notTaken || taken;
                }
                prev = curr;
            }
            return prev[k];
        }
    }
};