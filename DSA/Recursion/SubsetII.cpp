void helper(vector<int>& nums,vector<vector<int>>& res,vector<int>& tmp,int i){  
    res.push_back(tmp);
    for(int j = i;j<nums.size();j++)
    {
        if(j>i&&nums[j]==nums[j-1])continue;
        tmp.push_back(nums[j]);
        helper(nums,res,tmp,j+1);
        tmp.pop_back();
    }
}
    
vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    vector<int>temp;
    sort(nums.begin(),nums.end());
    vector<vector<int>>res;
    helper(nums,res,temp,0);
    return res;
}