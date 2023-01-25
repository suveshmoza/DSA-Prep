bool isMirror(TreeNode* a,TreeNode* b){
    if(a==NULL&&b==NULL) return true;
    if(a==NULL||b==NULL) return false;
    if(a->val!=b->val) return false;
    return isMirror(a->left,b->right)&&isMirror(a->right,b->left);
}

bool isSymmetric(TreeNode* root) {
    return isMirror(root,root);
}