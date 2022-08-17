vector<int> topKFrequent(vector<int>& nums, int k) {
    if (nums.size() == 1) return nums;
    unordered_map<int, int> mp;
    vector<int> res;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        mp[nums[i]]++;
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
    for (auto i : mp) {
        minHeap.push({i.second, i.first});
        if (minHeap.size() > k) {
            minHeap.pop();
        }
    }
    while (minHeap.size()) {
        res.push_back(minHeap.top().second);
        minHeap.pop();
    }
    return res;
}

// Bucket Sort

vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> mp;
    for (auto num : nums) {
        mp[num]++;
    }

    vector<vector<int>> bucket(nums.size() + 1);
    for (auto [a, b] : mp) {
        bucket[b].push_back(a);
    }

    vector<int> res;
    for (int i = nums.size(); k; i--) {
        for (auto a : bucket[i]) {
            res.push_back(a);
            k--;
        }
    }
    return res;
}