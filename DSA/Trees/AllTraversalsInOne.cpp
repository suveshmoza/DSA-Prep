vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root) {
    vector<vector<int>> res;
    if (!root) return res;
    vector<int> in, pre, post;
    stack<pair<BinaryTreeNode<int> *, int>> st;
    st.push({root, 1});

    while (!st.empty()) {
        auto it = st.top();
        st.pop();
        if (it.second == 1) {
            pre.push_back(it.first->data);
            it.second++;
            st.push(it);
            if (it.first->left) st.push({it.first->left, 1});
        } else if (it.second == 2) {
            in.push_back(it.first->data);
            it.second++;
            st.push(it);
            if (it.first->right) st.push({it.first->right, 1});
        } else {
            post.push_back(it.first->data);
        }
    }
    res = {in, pre, post};
    return res;
}