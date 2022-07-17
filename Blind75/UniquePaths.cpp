//! 1
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

//! 2
int dp[101][101];
    int dfs(int m,int n,int row,int col){
        if(row>m||col>n){
        return 0;
    }
    if(row==m-1||col==n-1){
        return 1;
    }
    if(dp[row][col]!=-1){
        return dp[row][col];
    }
    return dp[row][col]=dfs(m,n,row+1,col)+dfs(m,n,row,col+1);
}

int uniquePaths(int m, int n) {
    memset(dp,-1,sizeof(dp));
    int res=0;
    res=dfs(m,n,0,0);
    return res;
}

//! 3
int dfs(int m,int n,int row,int col){
    if(row>m||col>n){
        return 0;
    }
    if(row==m-1||col==n-1){
        return 1;
    }
    if(dp[row][col]!=-1){
        return dp[row][col];
    }
    return dp[row][col]=dfs(m,n,row+1,col)+dfs(m,n,row,col+1);
}    

int uniquePaths(int n, int m) {
    int dp[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
        if(i==0||j==0){
                dp[i][j]=1;
            }else{
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
    }
    return dp[n-1][m-1];
}

//! 4
int uniquePaths(int n, int m) {
    vector<int> prev(n,0);
    for(int i=0; i<m; i++){
    vector<int> temp(n,0);
    for(int j=0; j<n; j++){
            if(i==0 && j==0){
                temp[j]=1;
                continue;
            }
            int up=0,left =0;
            if(i>0) up = prev[j];
            if(j>0) left = temp[j-1];          
            temp[j] = up + left;
        }
        prev = temp;
    }
    return prev[n-1];
}