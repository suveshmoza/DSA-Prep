vector<vector<int>>res;
vector<int>temp;

void solve(vector<int>arr,int n,int sum,int start){
    if(sum<0) return;
    if(sum==0){
        res.push_back(temp);
        return;
    }
    for(int i=start;i<arr.size();i++){
        temp.push_back(arr[i]);
        solve(arr,n,sum-arr[i],i);
        temp.pop_back();
    }
}

    
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    solve(candidates,candidates.size(),target,0);
    return res;
}