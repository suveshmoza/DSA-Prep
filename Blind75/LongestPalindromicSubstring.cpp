string longestPalindrome(string s) {
    int n = s.size();
    if(n <= 1){
        return s;
    }
    int len, maxLen=1;
    int l, r, start=0;
    
    for(int i=0;i<n;i++){
        l=i, r=i;
        while(l>=0 && r<n && s[l]==s[r]){
            l--;
            r++;
        }
        len=r-l-1;
        if(len>maxLen){
            maxLen=len;
            start=l+1;
        }
        
        l=i,r=i+1;
         while(l>=0&&r<n&&s[l]==s[r]){
            l--,r++;
        }
        len=r-l-1;
        if(len>maxLen){
            maxLen=len;
            start=l+1;
        }
    }
    return s.substr(start,maxLen);
}