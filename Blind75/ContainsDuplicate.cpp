bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int>mp;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(mp.find(nums[i])==mp.end()){
                mp[nums[i]]++;
            }else{
                return true;
            }
        }
        return false;
    }