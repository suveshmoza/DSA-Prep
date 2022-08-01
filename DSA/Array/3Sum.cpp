vector<vector<int>> threeSum(vector<int>& nums) {
    int n=nums.size();
    vector<vector<int>>res;
    if(n<3) return res;
    sort(nums.begin(),nums.end());
    for(int i=0;i<n;i++){
        if(i>0&&nums[i]==nums[i-1]) continue;
        int fix=nums[i];
        int left=i+1,right=n-1;
        while(left<right){
            int sum=fix+nums[left]+nums[right];
            if(sum==0){
                res.push_back({fix,nums[left],nums[right]});
            while(left<right&&nums[left]==nums[left+1]) left++;
            while(left<right&&nums[right]==nums[right-1]) right--;
            left++,right--;
            }else if(fix+nums[left]+nums[right]>0) right--;
            else left++;
        }
    }
    return res;
}