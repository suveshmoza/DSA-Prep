vector<vector<int>> verticalTraversal(TreeNode* root) {
    vector<vector<int>> res;
    queue<pair<int,TreeNode*>> q;
    map<int,vector<int>> m;
    q.push({0,root});
    while(!q.empty()){
        int n=q.size();
        vector<pair<int,int>>a;
        while(n--){
        pair<int,TreeNode*> curr=q.front();
        q.pop();
        a.push_back({curr.second->val,curr.first});
        if(curr.second->left)
            q.push({curr.first-1,curr.second->left});
        if(curr.second->right)
            q.push({curr.first+1,curr.second->right});
    }
        sort(a.begin(),a.end());
        for(int i=0;i<a.size();i++) m[a[i].second].push_back(a[i].first);
    }
    for(auto it:m)
        res.push_back(it.second);
    return res;
}   