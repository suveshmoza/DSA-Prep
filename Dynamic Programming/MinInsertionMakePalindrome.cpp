class Solution {
   public:
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        string s1 = s;
        reverse(s.begin(), s.end());
        string s2 = s;
        vector<int> prev(n + 1, 0), curr(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    curr[j] = 1 + prev[j - 1];
                } else {
                    curr[j] = max(prev[j], curr[j - 1]);
                }
            }
            prev = curr;
        }
        return curr[n];
    }

    int minInsertions(string s) {
        int lcsLen = longestPalindromeSubseq(s);
        return s.length() - lcsLen;
    }
};