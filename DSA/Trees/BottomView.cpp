vector <int> bottomView(Node *root) {
    vector<int>res;
    if(!root) return res;
    map<int,int>mp;
    queue<pair<Node*,int>>q;
    q.push({root,0});
    int height=0;
    while(!q.empty()){
        Node* temp=q.front().first;
        int height=q.front().second;
        q.pop();
        mp[height]=temp->data;
        if(temp->left) q.push({temp->left,height-1});
        if(temp->right) q.push({temp->right,height+1}); 
    }
    for(auto it:mp){
        res.push_back(it.second);
    }
    return res;
}