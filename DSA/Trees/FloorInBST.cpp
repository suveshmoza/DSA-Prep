void successor(BinaryTreeNode<int> *root, int X, int &ans) {
    while (root) {
        if (root->data >= X) {
            ans = root->data;
            root = root->left;
        } else if (root->data < X) {
            root = root->right;
        }
    }
}

int findCeil(BinaryTreeNode<int> *node, int x) {
    int ans = -1;
    successor(node, x, ans);
    return ans;
}