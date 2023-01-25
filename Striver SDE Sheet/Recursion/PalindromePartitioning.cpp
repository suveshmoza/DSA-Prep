bool isPalindrome(string s,int i,int j){
    while(i<=j){
        if(s[i++]!=s[j--]) return false;
    }
    return true;
}
    
void solve(string s,int start,vector<vector<string>>&res,vector<string>&temp){
    if(start==s.length()){
        res.push_back(temp);
        return;
    }

    for(int i=start;i<s.length();i++){
        if(isPalindrome(s,start,i)){
            temp.push_back(s.substr(start, i-start+1));
            solve(s,i+1,res,temp);
            temp.pop_back();
        }
    }
}   

vector<vector<string>> partition(string s) {
    vector<vector<string>>res;
    vector<string>temp;
    solve(s,0,res,temp);
    return res;
}