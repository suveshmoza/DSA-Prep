TreeNode* solve(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root == NULL || root == p || root == q) return root;

    TreeNode* left = solve(root->left, p, q);
    TreeNode* right = solve(root->right, p, q);

    if (left == NULL)
        return right;
    else if (right == NULL)
        return left;
    return root;
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    return solve(root, p, q);
}