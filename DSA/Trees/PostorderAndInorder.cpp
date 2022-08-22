int search(vector<int> inorder, int start, int end, int x) {
    int res;
    for (int i = 0; i < inorder.size(); i++) {
        if (inorder[i] == x) {
            res = i;
            break;
        }
    }
    return res;
}

TreeNode* helper(vector<int> inorder, vector<int> postorder, int start, int end, int& postIndex) {
    if (start > end) return NULL;
    TreeNode* root = new TreeNode(postorder[postIndex--]);
    if (start == end) return root;
    int newIndex = search(inorder, start, end, root->val);
    root->right = helper(inorder, postorder, newIndex + 1, end, postIndex);
    root->left = helper(inorder, postorder, start, newIndex - 1, postIndex);
    return root;
}

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    int postIndex = postorder.size() - 1;
    return helper(inorder, postorder, 0, inorder.size() - 1, postIndex);
}