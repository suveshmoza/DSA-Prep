int maxSubArray(vector<int>& nums) {
    int currSum=0,maxSum=INT_MIN;
    for(int i=0;i<nums.size();i++){
        currSum=(currSum+nums[i])<nums[i]?nums[i]:currSum+nums[i];
        if(currSum>maxSum){
            maxSum=currSum;
        }
    }
    return maxSum;
}