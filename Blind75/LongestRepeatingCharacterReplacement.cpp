int characterReplacement(string s, int k) {
    int i=0,j=0,n=s.length(),maxCount=0;
    unordered_map<char,int>mp;
    int length=-1;
    while(j<n){
        mp[s[j]]++;
        maxCount=max(maxCount,mp[s[j]]);
        if((j-i+1)-maxCount>k){
            mp[s[i]]--;
            i++;
        }
        length=max(length,j-i+1);
        j++;
    }
    return length;
}