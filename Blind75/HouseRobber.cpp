//! 1
int dp[101];
int helper(vector<int>&nums,int start){
    if(start>=nums.size()) return 0;
    if(dp[start]!=-1) return dp[start];
    return dp[start]= max(nums[start]+helper(nums,start+2),helper(nums,start+1));
}

int rob(vector<int>& nums) {
    memset(dp,-1,sizeof(dp));
    if(nums.size()==1) return nums[0];
    return helper(nums,0);
}

//! 2
int rob(vector<int>& A) {
    if(size(A) == 1) return A[0];
    vector<int> dp(A);
    dp[1] = max(A[0], A[1]);
    for(int i = 2; i < size(A); i++)
        dp[i] = max(dp[i-1], A[i] + dp[i-2]);
    return dp.back();
}

//! 3 
int rob(vector<int>& nums) {
    if(nums.size()==1) return nums[0];
    int prevOne=0,prevTwo=0;
    for(int i=0;i<nums.size();i++){
        int currMax=max(nums[i]+prevTwo,prevOne);
        prevTwo=prevOne;
        prevOne=currMax;
    }
    return prevOne;
}
