pair<int, pair<int, int>> solve(TreeNode* root, int mini, int maxi, int sum, int& ans) {
    if (!root) {
        pair<int, pair<int, int>> curr;
        curr.first = 0;
        curr.second.first = INT_MAX;
        curr.second.second = INT_MIN;
        return curr;
    }
    auto l = solve(root->left, mini, maxi, sum, ans);
    auto r = solve(root->right, mini, maxi, sum, ans);
    pair<int, pair<int, int>> curr;
    if (root->val > l.second.second && root->val < r.second.first) {
        curr.first = l.first + r.first + root->val;
        curr.second.first = min(r.second.first, min(root->val, l.second.first));
        curr.second.second = max(l.second.second, max(root->val, r.second.second));
        ans = max(ans, curr.first);
        return curr;
    }
    curr.first = 0;
    curr.second.first = INT_MIN;
    curr.second.second = INT_MAX;
    return curr;
}
int maxSumBST(TreeNode* root) {
    int ans = 0;
    solve(root, INT_MIN, INT_MAX, 0, ans);
    return ans;
}