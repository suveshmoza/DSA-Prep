 bool canJump(vector<int>& nums) {
        int farthest=0;
        for(int i=0;i<nums.size();i++){
            if(farthest<i) return false;
            farthest=max(farthest,nums[i]+i);
        }
        return true;
    }