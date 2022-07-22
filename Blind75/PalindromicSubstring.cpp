int expand(string s,int i,int j,int &count){
    if(i>j) return 0;
    while(i>=0&&j<s.length()&&s[i]==s[j]){
        i--,j++,count++;
    }
    return count;
}

int countSubstrings(string s) {
    if(s.length()==0) return 0;
    int count=0;
    for(int i=0;i<s.length();i++){
        expand(s,i,i,count);
        expand(s,i,i+1,count);
    }
    return count;
}