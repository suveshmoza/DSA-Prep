#include <bits/stdc++.h>
using namespace std;

void printLCS(string text1, string text2) {
    int n = text1.length(), m = text2.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            } else if (text1[i - 1] == text2[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    string res;
    int i = n, j = m;
    while (i > 0 && j > 0) {
        if (text1[i - 1] == text2[j - 1]) {
            res.push_back(text1[i - 1]);
            i--, j--;
        } else if (text1[i - 1] > text2[j - 1]) {
            i--;
        } else {
            j--;
        }
    }
    reverse(res.begin(), res.end());
    cout << "LCS of two strings is " << res << endl;
}

int main() {
    string s = "abcde";
    string t = "bdgek";
    printLCS(s, t);
}