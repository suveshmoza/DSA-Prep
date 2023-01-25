int subarraysXor(vector<int> &arr, int x){
    int n = arr.size();
    unordered_map<int, int> mp;
    int cnt = 0;
    int Xor = 0;
    for (int i = 0; i < n; i++){
        Xor ^= arr[i];
        if (Xor == x){
            cnt++;
        }
        if (mp.find(Xor ^ x) != mp.end()){
            cnt += mp[Xor ^ x];
        }
        mp[Xor] += 1;
    }
    return cnt;
}