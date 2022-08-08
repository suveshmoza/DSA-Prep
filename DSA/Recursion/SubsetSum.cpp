 vector<int>ans;

void solve(vector<int>arr,int i,int j,int sum){
    if(i>j){
        ans.push_back(sum);
        return;
    }
    solve(arr,i+1,j,sum+arr[i]);
    solve(arr,i+1,j,sum);
}

vector<int> subsetSums(vector<int> arr, int N){
    solve(arr,0,N-1,0);
    return ans;
}