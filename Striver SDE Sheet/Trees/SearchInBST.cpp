//* Time complexity of a Balanced Binary Searched Tree is logN, 
//* because as it traverses the tree, it either goes left or right 
//* eliminating half of the whole Tree.
//* For an unbalanced Binary search tree, the time complexity is O(n)

 TreeNode* searchBST(TreeNode* root, int val) {
    if(root== NULL) return NULL;
    if(root->val == val) return root;
    if(root->val > val) return searchBST(root->left, val);
    return searchBST(root->right, val);
}