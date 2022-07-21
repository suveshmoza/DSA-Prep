vector<vector<int>>res;
vector<int>v;
    
void recur(vector<int>& cand,int target, int start){
    if(target<0){
        return;
    }
    if(target==0){
        res.push_back(v);
        return;
    }
    for(int i=start;i<cand.size();i++){
        v.push_back(cand[i]);
        recur(cand,target-cand[i],i);
        v.pop_back();
    }
}

vector<vector<int> > combinationSum(vector<int> &cand, int target) {
    sort(cand.begin(), cand.end());
    cand.erase(unique(cand.begin(), cand.end()), cand.end());
    recur(cand,target,0);
    return res;
}