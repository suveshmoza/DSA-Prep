int dp[302];
int helper(string s, vector<string> dict, int i, unordered_set<string> us){
    if(i==s.size()) return 1;
    if(dp[i]!= -1) return dp[i];
    for(int j=i;j<s.size();j++){
        if(us.find(s.substr(i, j-i+1))!= us.end() && helper(s, dict, j+1, us))
            return dp[i] = 1;
    }
    return dp[i] = 0;
}

bool wordBreak(string s, vector<string>& wordDict) {
    memset(dp, -1, sizeof(dp));
    unordered_set<string> us(wordDict.begin(), wordDict.end());
    return helper(s, wordDict, 0, us);
}