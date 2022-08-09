vector<vector<int>>res;
vector<int>temp;

void solve(vector<int>arr,int n,int sum,int start){
    if(sum<0) return;
    if(sum==0){
        res.push_back(temp);
        return;
    }
    for(int i=start;i<arr.size();i++){
        if(i!=start&&arr[i]==arr[i-1]) continue;
        temp.push_back(arr[i]);
        solve(arr,n,sum-arr[i],i+1);
        temp.pop_back();
    }
}

    
vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    sort(candidates.begin(),candidates.end());
    solve(candidates,candidates.size(),target,0);
    return res;
}