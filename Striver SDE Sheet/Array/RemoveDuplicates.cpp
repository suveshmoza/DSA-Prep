int removeDuplicates(vector<int>& nums) {
    int i=0,j=0,n=nums.size();
    if(n<=0) return 0;
    for(int j=1;j<n;j++){
        if(nums[i]!=nums[j]){
            i++;
            nums[i]=nums[j];
        }
    }
    return i+1;
}