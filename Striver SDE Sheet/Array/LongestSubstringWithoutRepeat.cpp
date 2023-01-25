int lengthOfLongestSubstring(string s) {
    int n=s.length(),i=0,j=0,len=0;
    unordered_map<char,int>mp;
    while(j<n){
        mp[s[j]]++;
        while(mp[s[j]]>1&&i<=j){
            mp[s[i]]--;
            i++;
        }
        len=max(len,j-i+1);
        j++;
    }
    return len;
}