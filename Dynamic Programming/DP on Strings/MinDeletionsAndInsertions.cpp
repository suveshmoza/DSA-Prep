int longestCommonSubsequence(string text1, string text2) {
    int n = text1.length(), m = text2.length();
    vector<int> prev(m + 1, 0), curr(m + 1, 0);
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (i == 0 || j == 0) {
                curr[j] = 0;
            } else if (text1[i - 1] == text2[j - 1]) {
                curr[j] = 1 + prev[j - 1];
            } else {
                curr[j] = max(prev[j], curr[j - 1]);
            }
        }
        prev = curr;
    }
    return prev[m];
}

int minOperations(string str1, string str2) {
    int lcsLen = longestCommonSubsequence(str1, str2);
    return str1.length() + str2.length() - 2 * lcsLen;
}