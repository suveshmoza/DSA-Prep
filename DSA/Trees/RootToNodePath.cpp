bool buildPath(TreeNode* root,vector<int>&res,int target){
    if(!root) return false;
    res.push_back(root->val);
    if(root->val==target) return true;
    if(buildPath(root->left,res,target)||buildPath(root->right,res,target)) return true;
    res.pop_back();
    return false;   
}
 
vector<int> Solution::solve(TreeNode* A, int B) {
    vector<int>res;
    buildPath(A,res,B);
    return res;
}