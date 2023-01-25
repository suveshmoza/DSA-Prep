//* Approach 1
string reverseWords(string s) {
    stack<string>st;
    string temp,res;
    stringstream S(s);
    while(S>>temp){
        st.push(temp);
    }
    while(!st.empty()){
        res+=st.top();
        st.pop();
        if(!st.empty()) res+=" ";
    }
    return res;
}

//* Approach 2 
string reverseWords(string s) {
    int left = 0,right = s.length()-1;
    string temp="",ans="";
    while (left <= right) {
        char ch= s[left];
        if (ch != ' ') {
            temp += ch;
        } else if (ch == ' ') {
            if (ans!="") ans = temp + " " + ans;
            else ans = temp;
            temp = "";
        }
        left++;
    }
    if (temp!="") {
        if (ans!="") ans = temp + " " + ans;
        else ans = temp;
    }
    return ans;    
}