static bool comparator(vector<int>&a,vector<int>&b){
    return a[1]<b[1];
}

int eraseOverlapIntervals(vector<vector<int>>& nums) {
    sort(nums.begin(),nums.end(),comparator);
    int count =0;
    int start = nums[0][0],end = nums[0][1];
    for(int i=1;i<nums.size();i++){
        if(nums[i][0]<end){
            count++;
        }
        else{
            start=nums[i][0];
            end=nums[i][1];
        }
           
    }
    return count;
}