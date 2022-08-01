vector<int> leftView(Node *root){
    vector<int>res;
    if(!root) return res;
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        int size=q.size();
        for(int i=0;i<size;i++){
            auto temp=q.front();
            q.pop();
            if(i==0) res.push_back(temp->data);
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
    }
    return res;
}