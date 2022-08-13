//* Recursive 

int dfs(int m,int n,int row,int col){
    if(row>m||col>n){
        return 0;
    }
    if(row==m-1||col==n-1){
        return 1;
    }
    return dfs(m,n,row+1,col)+dfs(m,n,row,col+1);
}

int uniquePaths(int m, int n) {
    int res=0;
    res=dfs(m,n,0,0);
    return res;
}

//* Memo

int dp[101][101];
int solve(int m,int n,int i,int j){
    if(i>m||j>n) return 0;
    if(i==m-1&&j==n-1) return 1;
    if(dp[i][j]!=-1) return dp[i][j];
    return dp[i][j]=solve(m,n,i+1,j)+solve(m,n,i,j+1);
}

int uniquePaths(int m, int n) {
    memset(dp,-1,sizeof(dp));
    int res=0;
    res=solve(m,n,0,0);
    return res;
}

//* Tabulation 
int uniquePaths(int m, int n) {
  int dp[m][n];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(i==0||j==0){
                dp[i][j]=1;
            }else{
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
    }
    return dp[m-1][n-1];
}