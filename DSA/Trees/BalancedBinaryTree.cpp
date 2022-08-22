//* Brute

int height(TreeNode* root) {
    return root == NULL ? -1 : max(height(root->left), height(root->right)) + 1;
}

bool isBalanced(TreeNode* root) {
    if (root == NULL) return true;
    int left = height(root->left);
    int right = height(root->right);

    return (abs(left - right) <= 1) && isBalanced(root->left) && isBalanced(root->right);
}

//* Optimal

int check(TreeNode* root) {
    if (!root) return 0;

    int lh = check(root->left);
    if (lh == -1) return -1;
    int rh = check(root->right);
    if (rh == -1) return -1;
    if (abs(lh - rh) > 1) {
        return -1;
    }
    return 1 + max(lh, rh);
}

bool isBalanced(TreeNode* root) {
    return check(root) != -1;
}