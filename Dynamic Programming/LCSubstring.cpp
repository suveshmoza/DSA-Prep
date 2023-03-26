int lcs(string &text1, string &text2) {
    int n = text1.length(), m = text2.length();
    vector<int> prev(m + 1, 0), curr(m + 1, 0);
    int maxLen = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (text1[i - 1] == text2[j - 1]) {
                curr[j] = 1 + prev[j - 1];
                maxLen = max(maxLen, curr[j]);
            } else {
                curr[j] = 0;
            }
        }
        prev = curr;
    }
    return maxLen;
}