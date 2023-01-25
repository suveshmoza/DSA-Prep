void inorder(Node* root, int& k, int& res) {
    if (!root) return;
    inorder(root->right, k, res);
    k--;
    if (k == 0) {
        res = root->data;
        return;
    }
    inorder(root->left, k, res);
}

int kthLargest(Node* root, int K) {
    int res = 0;
    inorder(root, K, res);
    return res;
}