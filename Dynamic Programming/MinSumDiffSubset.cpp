// Tabulation
int minSubsetSumDifference(vector<int>& arr, int n) {
    int totalSum = 0;
    for (auto i : arr) totalSum += i;
    int k = totalSum;
    vector<vector<bool>> dp(n, vector<bool>(k + 1, false));
    for (int i = 0; i < n; i++) dp[i][0] = true;
    dp[0][arr[0]] = true;
    for (int i = 1; i < n; i++) {
        for (int target = 1; target <= k; target++) {
            bool notTaken = dp[i - 1][target];
            bool taken = false;
            if (arr[i] <= target) {
                taken = dp[i - 1][target - arr[i]];
            }
            dp[i][target] = taken | notTaken;
        }
    }
    int ans = INT_MAX;
    for (int s1 = 0; s1 <= (totalSum / 2); s1++) {
        if (dp[n - 1][s1]) {
            ans = min(ans, abs(s1 - (totalSum - s1)));
        }
    }
    return ans;
}

// Best
#include <bits/stdc++.h>
int minSubsetSumDifference(vector<int>& arr, int n) {
    int totalSum = 0;
    for (auto i : arr) totalSum += i;
    int k = totalSum;
    vector<bool> prev(k + 1, false);
    for (int i = 0; i < n; i++) prev[0] = true;
    if (arr[0] <= k) prev[arr[0]] = true;
    for (int i = 1; i < n; i++) {
        vector<bool> curr(k + 1, false);
        curr[0] = true;
        for (int target = 1; target <= k; target++) {
            bool notTaken = prev[target];
            bool taken = false;
            if (arr[i] <= target) {
                taken = prev[target - arr[i]];
            }
            curr[target] = taken | notTaken;
        }
        prev = curr;
    }
    int ans = INT_MAX;
    for (int s1 = 0; s1 <= (totalSum / 2); s1++) {
        if (prev[s1]) {
            ans = min(ans, abs(s1 - (totalSum - s1)));
        }
    }
    return ans;
}
