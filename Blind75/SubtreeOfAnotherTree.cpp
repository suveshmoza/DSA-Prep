bool check(TreeNode* root,TreeNode* sub){
    if(!root&&!sub) return true;
    if(!root||!sub) return false;
    return root->val==sub->val&&check(root->left,sub->left)&&check(root->right,sub->right);
}

bool isSubtree(TreeNode* root, TreeNode* subRoot) {
    if(!root&&!subRoot) return true;
    if(!root&&subRoot||root&&!subRoot) return check;
    if(check(root,subRoot)){
        return true;
    }
    return isSubtree(root->left,subRoot)||isSubtree(root->right,subRoot);
}