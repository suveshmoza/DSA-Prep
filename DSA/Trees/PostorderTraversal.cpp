void postorder(TreeNode* root,vector<int>&v){
    if(root==NULL) return;
    postorder(root->left,v);
    postorder(root->right,v);
    v.push_back(root->val);
}
  
vector<int> postorderTraversal(TreeNode* root) {
    vector<int>v;
    postorder(root,v);
    return v;
}