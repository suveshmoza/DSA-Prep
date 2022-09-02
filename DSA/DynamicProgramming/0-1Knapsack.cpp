// Recursive Code
#include <bits/stdc++.h>
using namespace std;

int knapSack(int W, vector<int> wt, vector<int> val, int n) {
    //!  Base case
    // * 1. all items processed
    // * 2. bag becomes full
    if (n == 0 || W == 0)
        return 0;
    // ! If weight of current item is more than bag capacity
    if (wt[n - 1] > W)
        return knapSack(W, wt, val, n - 1);
    // ! take maximum of curr item  or without this item
    // !
    else
        return max(
            val[n - 1] + knapSack(W - wt[n - 1], wt, val, n - 1),
            knapSack(W, wt, val, n - 1));
}

int main() {
    vector<int> wt{10, 20, 30};
    vector<int> val{60, 100, 120};
    int w = 50;
    int ans = knapSack(w, wt, val, wt.size());
    cout << ans << endl;
    return 0;
}

// Memo Version

#include <bits/stdc++.h>
using namespace std;

int dp[100][100];

int knapSack(int W, vector<int> wt, vector<int> val, int n) {
    if (n == 0 || W == 0)
        return 0;
    if (dp[n][W] != -1)
        return dp[n][W];
    if (wt[n - 1] > W)
        return dp[n][W] = knapSack(W, wt, val, n - 1);
    else
        return dp[n][W] = max(val[n - 1] + knapSack(W - wt[n - 1], wt, val, n - 1), knapSack(W, wt, val, n - 1));
}

int main() {
    memset(dp, -1, sizeof(dp));
    vector<int> wt{10, 20, 30};
    vector<int> val{60, 100, 120};
    int w = 50;
    int ans = knapSack(w, wt, val, wt.size());
    cout << ans << endl;
    return 0;
}

// Top Down Version

#include <bits/stdc++.h>
using namespace std;

int knapSack(int W, vector<int> wt, vector<int> val, int n) {
    int dp[n + 1][W + 1];
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= W; j++) {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (wt[i - 1] <= j)
                dp[i][j] = max(val[i - 1] + dp[i - 1][j - wt[i - 1]], dp[i - 1][j]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][W];
}

int main() {
    vector<int> wt{10, 20, 30};
    vector<int> val{60, 100, 120};
    int w = 50;
    int ans = knapSack(w, wt, val, wt.size());
    cout << ans << endl;
    return 0;
}