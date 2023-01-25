vector<int> rightSideView(TreeNode* root) {
    vector<int>res;
    if(!root) return res;
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty()){
        int  n=q.size();
        while(n--){
            auto temp=q.front();
            q.pop();
            if(n==0) res.push_back(temp->val);
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }       
    }
    return res;
}