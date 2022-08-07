// memo
int dp[1001][1001];
    
int lcs(string &x,string &y,int n,int m){
    if(n==0||m==0) return 0;
    if(dp[n][m]!=-1) return dp[n][m];
    if(x[n-1]==y[m-1]) return dp[n][m]=1+lcs(x,y,n-1,m-1);
    else return dp[n][m]= max(lcs(x,y,n-1,m),lcs(x,y,n,m-1));
}

int longestCommonSubsequence(string text1, string text2) {
    memset(dp,-1,sizeof(dp));
    return lcs(text1,text2,text1.length(),text2.length());
}

// tabulation

int longestCommonSubsequence(string x, string y) {
    int n=x.length(),m=y.length();
    int dp[n+1][m+1];
    for(int i=0;i<=n;i++) dp[i][0]=0;
    for(int i=0;i<=m;i++) dp[0][i]=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(x[i-1]==y[j-1]) dp[i][j]=1+dp[i-1][j-1];
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[n][m];
}