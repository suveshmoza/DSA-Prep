string serialize(TreeNode* root) {
    if(!root) return "NULL";
    return to_string(root->val)+","+serialize(root->left)+","+serialize(root->right);
}
    
TreeNode*helper(queue<string>&q){
    if(q.empty()) return NULL;
    auto temp=q.front();
    q.pop();
    if(temp=="NULL") return NULL;
    int v=stoi(temp);
    TreeNode *root=new TreeNode(v);
    root->left=helper(q);
    root->right=helper(q);
    return root;
}  

TreeNode* deserialize(string data) {
    queue<string>q;
    string temp;
    for(int i=0;i<data.length();i++){
        if(data[i]==','){
            q.push(temp);
            temp="";
        }else temp+=data[i];
    }
    return helper(q);
}