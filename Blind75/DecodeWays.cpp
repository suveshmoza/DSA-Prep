//! 1
int dp[101];        
int decode(string s,int size){
    if(s[0]=='0') return 0;
    if(size==0||size==1) return 1;
    if(dp[size]!=-1) return dp[size];
    int count=0;
    if(s[size-1]>'0') count=decode(s,size-1);
    if(s[size-2]=='1'||s[size-2]=='2'&&s[size-1]<'7') count+=decode(s,size-2);
    return dp[size]=count;
}

int numDecodings(string s) {
    memset(dp,-1,sizeof(dp));
    return decode(s,s.size());
}

//! 2
int numDecodings(string s,int n) {
    int count[n+1];  
    count[0] = 1; 
    count[1] = 1;  	
    if(s[0]=='0') return 0; 
    for (int i = 2; i <= n; i++){  count[i] = 0; 
        if (s[i-1] > '0') count[i] = count[i-1]; 
        if (s[i-2] == '1' || (s[i-2] == '2' && s[i-1] < '7') ) count[i] += count[i-2]; 
    } 
    return count[n];
}

int numDecodings(string s) {
    return numDecodings(s,s.size());
}

//! 3
int numDecodings(string s) {
    int prev,prevWays=1,currWays=1;
    if(s.length()<=0||s[0]=='0') return 0;
    for(int i=1;i<s.length();i++){
        prev=currWays;
        if(s[i-1]=='0') currWays=0;
        if(s[i-1]=='1'||(s[i-2]=='2'&&s[i-1]<='6')) currWays+=prevWays;
        prevWays=prev;
    }
    return currWays;
}