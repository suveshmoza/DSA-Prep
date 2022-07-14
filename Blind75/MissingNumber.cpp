int missingNumber(vector<int>& nums) {
        int finder=0,n=nums.size();
        for(int i=1;i<=n;i++) finder^=i;
        for(int i=0;i<n;i++){
            finder^=nums[i];
        }
        return finder;
    }