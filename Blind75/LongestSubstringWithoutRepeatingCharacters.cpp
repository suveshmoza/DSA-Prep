int lengthOfLongestSubstring(string s) {
    unordered_map<char,int>mp;
    int i=0,j=0,n=s.length();
    int length=0;
    while(j<n){
        mp[s[j]]++;
        if(mp[s[j]]>1){
            while(mp[s[j]]>1&&i<=j){
                mp[s[i]]--;
                i++;
            }
        }
        length=max(length,j-i+1);
        j++;
    }
    return length;
}