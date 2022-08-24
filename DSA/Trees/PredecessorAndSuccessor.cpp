void predecessor(BinaryTreeNode<int>* root, int& pred, int key) {
    while (root != NULL) {
        if (root->data < key) {
            pred = root->data;
            root = root->right;
        } else if (root->data >= key) {
            root = root->left;
        }
    }
}

void successor(BinaryTreeNode<int>* root, int& succ, int key) {
    while (root != NULL) {
        if (root->data > key) {
            succ = root->data;
            root = root->left;
        } else if (root->data <= key) {
            root = root->right;
        }
    }
}
pair<int, int> predecessorSuccessor(BinaryTreeNode<int>* root, int key) {
    int pred = -1;
    int succ = -1;

    predecessor(root, pred, key);
    successor(root, succ, key);

    pair<int, int> ans = {pred, succ};
    return ans;
}