int solve(vector<int>&arr,int i,int j,vector<vector<int>>&dp){
    if(i>=j) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int ans=INT_MAX;
    for(int cut=i;cut<=j-1;cut++){
        int left,right;
        if(dp[i][cut]!=-1){
            left=dp[i][cut];
        }else{
            left=solve(arr,i,cut,dp);
        }
        if(dp[cut+1][j]!=-1){
            right=dp[cut+1][j];
        }else{
            right=solve(arr,cut+1,j,dp);
        }
        int temp=left+right+arr[i-1]*arr[cut]*arr[j];
        ans=min(ans,temp);
    }
    return dp[i][j]=ans;
}

int matrixMultiplication(vector<int> &arr, int N){
    vector<vector<int>>dp(N,vector<int>(N,-1));
    return solve(arr,1,N-1,dp);
}