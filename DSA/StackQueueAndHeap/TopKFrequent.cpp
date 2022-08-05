vector<int> topKFrequent(vector<int>& nums, int k) {
    if(nums.size()==1) return nums;
    unordered_map<int,int>mp;
    vector<int>res;
    int n=nums.size();
    for(int i=0;i<n;i++){
        mp[nums[i]]++;    
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>minHeap;
    for(auto i:mp){
        minHeap.push({i.second,i.first});
        if(minHeap.size()>k){
            minHeap.pop();
        }
    }
    while(minHeap.size()){
        res.push_back(minHeap.top().second);
        minHeap.pop();
    }
    return res;
}