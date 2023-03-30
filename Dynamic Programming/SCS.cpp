#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> lcs(string text1, string text2) {
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
    // return dp[n][m];
    return dp;
}

void printDP(vector<vector<int>> dp, int n, int m) {
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
}

void scs(string str1, string str2) {
    string temp = str1 + str2;
    vector<vector<int>> dp = lcs(str1, str2);
    // (str1+str2)-lcs === len of scs
    int n = str1.length(), m = str2.length();
    // printDP(dp, n, m);
    int i = n, j = m;
    string res;
    while (i > 0 && j > 0) {
        if (str1[i - 1] == str2[j - 1]) {
            res.push_back(str1[i - 1]);
            i--, j--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            res.push_back(str1[i - 1]);
            i--;
        } else {
            res.push_back(str2[j - 1]);
            j--;
        }
    }
    while (i > 0) {
        res.push_back(str1[i - 1]);
        i--;
    }
    while (j > 0) {
        res.push_back(str2[j - 1]);
        j--;
    }
    reverse(res.begin(), res.end());
    cout << "res :" << res << endl;
}

int main() {
    string str1 = "brute", str2 = "groot";
    scs(str1, str2);
    return 0;
}