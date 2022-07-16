int i=0,ans=-1;
int kthSmallest(TreeNode* root, int k) {
    if(root==NULL||i>=k) return ans;
    kthSmallest(root->left,k);
    i++;
    if(i==k){
        ans=root->val;
        return ans;
    }
    kthSmallest(root->right,k);
    return ans;
}