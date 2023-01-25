//* Approach 1
TreeNode* build(TreeNode* root, int val) {
    if (root == NULL)
        root = new TreeNode(val);
    else if (val <= root->val)
        root->left = build(root->left, val);
    else if (val > root->val)
        root->right = build(root->right, val);
    return root;
}
TreeNode* bstFromPreorder(vector<int>& preorder) {
    TreeNode* root = NULL;
    for (int i = 0; i < preorder.size(); i++) {
        root = build(root, preorder[i]);
    }
    return root;
}

//* Approach 2
TreeNode* helper(vector<int>& preorder, int& preInd, int maxVal) {
    if (preInd == preorder.size() || preorder[preInd] > maxVal) return NULL;
    TreeNode* root = new TreeNode(preorder[preInd++]);
    root->left = helper(preorder, preInd, root->val);
    root->right = helper(preorder, preInd, maxVal);
    return root;
}

TreeNode* bstFromPreorder(vector<int>& preorder) {
    int preInd = 0;
    return helper(preorder, preInd, INT_MAX);
}