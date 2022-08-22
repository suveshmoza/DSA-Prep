int search(vector<int>& inorder, int start, int end, int x) {
    int res;
    for (int i = start; i <= end; i++) {
        if (inorder[i] == x) {
            res = i;
            break;
        }
    }
    return res;
}

TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int start, int end, int& preIndex) {
    if (start > end) return NULL;
    TreeNode* root = new TreeNode(preorder[preIndex++]);
    if (start == end) return root;
    int newIndex = search(inorder, start, end, root->val);
    root->left = helper(preorder, inorder, start, newIndex - 1, preIndex);
    root->right = helper(preorder, inorder, newIndex + 1, end, preIndex);
    return root;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    int preIndex = 0;
    return helper(preorder, inorder, 0, inorder.size() - 1, preIndex);
}