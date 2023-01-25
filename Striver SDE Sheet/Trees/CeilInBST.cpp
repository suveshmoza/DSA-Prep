void predecessor(TreeNode<int>* root, int X, int& ans) {
    while (root) {
        if (root->val <= X) {
            ans = root->val;
            root = root->right;
        } else if (root->val > X) {
            root = root->left;
        }
    }
}

int floorInBST(TreeNode<int>* root, int X) {
    int ans;
    predecessor(root, X, ans);
    return ans;
}