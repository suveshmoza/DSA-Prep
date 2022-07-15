// ! O(n*n)

int lengthOfLIS(vector<int>& nums) {
    int n=nums.size();
    vector<int>dp(n+1,1);
        
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(nums[i]>nums[j]){
                dp[i]=max(dp[i],dp[j]+1);
            }
        }
    }
    int maxi=INT_MIN;
    for(int i=0;i<n;i++){
        maxi=max(maxi,dp[i]);
    }
    return maxi;
}

// ! O(n*log(n)) 
int lengthOfLIS(vector<int>& nums) {
    if(nums.size()==0) return 0;
    int n=nums.size();
    vector<int>temp;
    temp.push_back(nums[0]);
    for(int i=1;i<n;i++){
        if(nums[i]>temp.back()){
            temp.push_back(nums[i]);
        }else{
            int index=lower_bound(temp.begin(),temp.end(),nums[i])-temp.begin();
            temp[index]=nums[i];
        }
    }
    return temp.size();
}