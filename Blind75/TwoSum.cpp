vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mp;
        int n=nums.size();
        for(int i=0;i<n;i++){
            mp[nums[i]]=i;
        }
        vector<int>res(2);   
        for(int i=0;i<n;i++){
            if(mp.find(target-nums[i])!=mp.end()&&mp[target-nums[i]]!=i){
                res[0]=mp[target-nums[i]];
                res[1]=i;
                break;
            }
        }
        return res;
    }