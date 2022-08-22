int widthOfBinaryTree(TreeNode* root) {
    if (!root) {
        return 0;
    }
    queue<pair<TreeNode*, int>> q;
    q.push({root, 0});
    int ans = 0;
    while (!q.empty()) {
        int n = q.size(), x = 0, start = q.front().second;
        ans = max(ans, q.back().second - q.front().second + 1);
        for (int i = 0; i < n; i++) {
            auto node = q.front();
            q.pop();
            int index = node.second - start;
            if (node.first->left) {
                q.push({node.first->left, 1ll * 2 * index + 1});
            }
            if (node.first->right) {
                q.push({node.first->right, 1ll * 2 * index + 2});
            }
        }
    }
    return ans;
}