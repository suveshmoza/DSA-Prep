//! 1
vector<string>compute(string s){
    vector<string>a;
    int index = 0;        
    int i = 0;
    string tmp = "";
    while(i < s.size()){
        if(s[i] == '.'){
            a.push_back(tmp);
            tmp = "";
            i++;
            
        }
        else if(s[i] == '0' && tmp == "")i++;
        else tmp.push_back(s[i++]);
    }
    a.push_back(tmp);
    return a;
}
    
bool comp(string a , string b){
    if(a.size() != b.size())
        return a.size() > b.size();
    return a > b;
}
    
int compareVersion(string version1, string version2) {
    vector<string>a = compute(version1);
    vector<string>b = compute(version2);
    while(a.size() < b.size())a.push_back("");
    while(b.size() < a.size())b.push_back("");    
    for(int i=0;i<a.size();i++){
        
        if(comp(a[i] , b[i])) return 1;
        else if(comp(b[i] , a[i])) return -1;
    }
    return 0;
}

//! 2
int compareVersion(string version1, string version2) {
    int i=0,j=0,n=version1.length(),m=version2.length(),n1,n2;
    while(i<n||j<m){
        n1=0,n2=0;
        while(i<n&&version1[i]!='.') n1=n1*10+(version1[i++]-'0');
        while(j<m&&version2[j]!='.') n2=n2*10+(version2[j++]-'0');
        if(n1<n2) return -1;
        else if(n1>n2) return 1;
        i++,j++;
    }
    return 0;
}