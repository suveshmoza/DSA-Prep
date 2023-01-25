int maxProduct(vector<int>& nums) {
    int res=nums[0];
    int mini=res,maxi=res;
    for(int i=1;i<nums.size();i++){
        if(nums[i]<0) swap(mini,maxi);
        mini=min(nums[i],nums[i]*mini);
        maxi=max(nums[i],nums[i]*maxi);
        res=max(res,maxi);
    }
    return res;
}