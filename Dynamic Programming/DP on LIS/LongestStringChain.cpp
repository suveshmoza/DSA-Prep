class Solution {
   public:
    bool differByOne(string s1, string s2) {
        int n = s1.length(), m = s2.length();
        if (n != m + 1) return false;
        int i = 0, j = 0;
        while (i < n) {
            if (j < m && s1[i] == s2[j]) {
                i++, j++;
            } else {
                i++;
            }
        }
        if (i == n && j == m) return true;
        return false;
    }

    static bool comp(string &s1, string &s2) {
        return s1.size() < s2.size();
    }

    int longestStrChain(vector<string> &words) {
        int n = words.size(), maxi = 1;
        sort(words.begin(), words.end(), comp);
        vector<int> dp(n, 1);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (differByOne(words[i], words[j]) && dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                }
            }
            if (maxi < dp[i]) maxi = dp[i];
        }
        return maxi;
    }
};