class BSTIterator {
    stack<TreeNode*> st;

   public:
    BSTIterator(TreeNode* root) {
        while (root) {
            st.push(root);
            root = root->left;
        }
    }

    int next() {
        auto node = st.top();
        auto temp = node->right;
        st.pop();
        while (temp) {
            st.push(temp);
            temp = temp->left;
        }
        return node->val;
    }

    bool hasNext() {
        return !st.empty();
    }
};