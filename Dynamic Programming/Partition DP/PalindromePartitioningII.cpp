class Solution {
   public:
    bool isPal(string& str, int i, int j) {
        while (i <= j) {
            if (str[i] != str[j]) {
                return false;
            }
            i++, j--;
        }
        return true;
    }

    int f(string s, int i, int n, vector<int>& dp) {
        if (i == n) return 0;
        if (dp[i] != -1) return dp[i];
        int ans = INT_MAX;
        string temp;
        for (int j = i; j < n; j++) {
            if (isPal(s, i, j)) {
                int cost = 1 + f(s, j + 1, n, dp);
                ans = min(ans, cost);
            }
        }
        return dp[i] = ans;
    }

    int minCut(string s) {
        int n = s.length();
        vector<int> dp(n, -1);
        return f(s, 0, n, dp) - 1;
    }
};