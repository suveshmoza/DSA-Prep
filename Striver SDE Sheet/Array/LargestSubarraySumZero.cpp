int maxLen(vector<int>&A, int n){   
    int maxi=0;
    int sum=0;
    unordered_map<int,int>mp;
    for(int i=0;i<n;i++){
        sum+=A[i];
        if(sum==0) maxi=i+1;
        if(mp.find(sum)!=mp.end()) maxi=max(maxi,i-mp[sum]);
        if(mp.find(sum)==mp.end()) mp[sum]=i;
    }
    return maxi;
}