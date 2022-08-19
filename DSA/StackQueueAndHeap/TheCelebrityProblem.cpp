int celebrity(vector<vector<int> >& M, int n) {
    stack<int> st;
    for (int i = 0; i < n; i++) st.push(i);
    while (st.size() >= 2) {
        int a = st.top();
        st.pop();
        int b = st.top();
        st.pop();
        if (M[a][b] == 1)
            st.push(b);
        else
            st.push(a);
    }
    int celeb = st.top();
    st.pop();
    for (int i = 0; i < n; i++) {
        if (i != celeb) {
            if (M[i][celeb] == 0 || M[celeb][i] == 1) return -1;
        }
    }
    return celeb;
}