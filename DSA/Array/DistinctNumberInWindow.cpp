vector<int> countDistinct(int A[], int n, int k) {
    vector<int> res;
    unordered_map<int, int> mp;
    for (int i = 0; i < k; i++) {
        mp[A[i]]++;
    }
    res.push_back(mp.size());
    for (int i = k; i < n; i++) {
        mp[A[i - k]]--;
        if (mp[A[i - k]] == 0) {
            mp.erase(A[i - k]);
        }
        mp[A[i]]++;
        res.push_back(mp.size());
    }
    return res;
}