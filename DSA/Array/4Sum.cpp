vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>>res;
    int n=nums.size();
    if(n<4) return res;
    sort(nums.begin(),nums.end());
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int rem=target-nums[i]-nums[j];
            int left=j+1,right=n-1;
            while(left<right){
                int sum=nums[left]+nums[right];
                if(sum<rem) left++;
                else if(sum>rem) right--;
                else{
                    res.push_back({nums[i],nums[j],nums[left],nums[right]});
                    int prevLeft=nums[left],prevRight=nums[right];
                    while(left<right&&nums[left]==prevLeft) left++;
                    while(left<right&&nums[right]==prevRight) right--;      
                }
            }
                while(j<n-1&&nums[j]==nums[j+1]) j++;
        }
             while(i<n-1&&nums[i]==nums[i+1]) i++;
    }
        return res;
}