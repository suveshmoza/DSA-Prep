bool isValid(string s) {
    stack<char> st;
    int n = s.length();
    for (int i = 0; i < n; i++) {
        if (s[i] == '[' || s[i] == '(' || s[i] == '{') {
            st.push(s[i]);
        } else if (!st.empty() && s[i] == ')' && st.top() == '(') {
            st.pop();
        } else if (!st.empty() && s[i] == '}' && st.top() == '{') {
            st.pop();
        } else if (!st.empty() && s[i] == ']' && st.top() == '[') {
            st.pop();
        } else {
            st.push(s[i]);
        }
    }
    return st.size() == 0;
}