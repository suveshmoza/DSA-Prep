int helper(vector<int>nums){
    if(nums.size()==1) return nums[0];
    int prevOne=0,prevTwo=0;
    for(int i=0;i<nums.size();i++){
        int currMax=max(nums[i]+prevTwo,prevOne);
        prevTwo=prevOne;
        prevOne=currMax;
    }
    return prevOne;
}

int rob(vector<int>& nums) {
    if(nums.size()==1) return nums[0];
    vector<int>v1(nums.begin(),nums.end()-1);
    vector<int>v2(nums.begin()+1,nums.end());
    return max(helper(v1),helper(v2));
}