bool isBSTUtil(TreeNode* root, TreeNode*& prev) {
    if (root) {
        if (!isBSTUtil(root->left, prev))
            return false;
        if (prev != NULL && root->val <= prev->val)
            return false;
        prev = root;
        return isBSTUtil(root->right, prev);
    }
    return true;
}

bool isValidBST(TreeNode* root) {
    TreeNode* prev = NULL;
    return isBSTUtil(root, prev);
}