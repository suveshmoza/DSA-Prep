int coinChange(vector<int>& coins, int sum) {
    int n=coins.size();
    int dp[n+1][sum+1];

    for(int i=0;i<=n;i++){
        for(int j=0;j<=sum;j++){
            if(i==0) dp[i][j]=INT_MAX-1;
            if(j==0) dp[i][j]=0;
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            if(coins[i-1]<=j) dp[i][j]=min(1+dp[i][j-coins[i-1]],dp[i-1][j]);
            else dp[i][j]=dp[i-1][j];
        }
    }
    return dp[n][sum]==INT_MAX-1?-1:dp[n][sum];
}