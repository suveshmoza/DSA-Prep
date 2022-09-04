int dp[105];
bool solve(string target, unordered_set<string> st) {
    if (target.length() == 0) return true;
    if (dp[target.length()] != -1) return dp[target.length()];
    for (int i = 1; i <= target.length(); i++) {
        cout << target.substr(0, i) << endl;
        if (st.find(target.substr(0, i)) != st.end() && solve(target.substr(i, target.length() - i), st)) {
            return dp[target.length()] = true;
        }
    }
    return dp[target.length()] = false;
}

bool wordBreak(vector<string>& arr, int n, string& target) {
    memset(dp, -1, sizeof(dp));
    unordered_set<string> st;
    for (auto s : arr) {
        st.insert(s);
    }
    return solve(target, st);
}