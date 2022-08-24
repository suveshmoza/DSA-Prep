void inorder(TreeNode* root, TreeNode*& first, TreeNode*& second, TreeNode*& prev) {
    if (root == NULL) return;
    inorder(root->left, first, second, prev);
    if (prev && prev->val > root->val) {
        if (!first) first = prev;
        second = root;
    }
    prev = root;
    inorder(root->right, first, second, prev);
}

void recoverTree(TreeNode* root) {
    TreeNode *first = NULL, *second = NULL, *prev = NULL;
    inorder(root, first, second, prev);
    if (first && second) swap(first->val, second->val);
}