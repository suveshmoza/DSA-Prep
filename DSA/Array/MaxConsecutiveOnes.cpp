int findMaxConsecutiveOnes(vector<int>& nums) {
    int count=0,maxLength=INT_MIN;
    for(int i=0;i<nums.size();i++){
        if(nums[i]==1){
            count++;
        }else{
            maxLength=max(maxLength,count);
            count=0;
        }
    }
    maxLength=max(maxLength,count);
    return maxLength;
}