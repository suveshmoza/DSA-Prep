int height(TreeNode* root){
    return root==NULL?0:1+max(height(root->left),height(root->right));
}

int maxDepth(TreeNode* root) {
    if(!root) return 0;
    
    int leftHeight=height(root->left);
    int rightHeight=height(root->right);
    return leftHeight<rightHeight?rightHeight+1:leftHeight+1;
}


bool isSameTree(TreeNode* p, TreeNode* q) {
    if(p==NULL&&q==NULL) return true;
    if(p==NULL||q==NULL) return false;
    if(p->val!=q->val) return false;
    return isSameTree(p->left,q->left)&&isSameTree(p->right,q->right);
}