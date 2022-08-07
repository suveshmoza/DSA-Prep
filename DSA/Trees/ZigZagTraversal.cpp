vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>>res;
    if(!root) return res;
    queue<TreeNode*>q;
    q.push(root);
    int revCount=1;
    while(!q.empty()){
        int  n=q.size();
        vector<int>level;
        for(int i=0;i<n;i++){
            auto temp=q.front();
            q.pop();
            level.push_back(temp->val);
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
        if(revCount%2==0){
                reverse(level.begin(),level.end());
            }
        revCount++;
        res.push_back(level);
    }
    return res;
}