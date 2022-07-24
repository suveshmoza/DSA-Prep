//! 🤕

Node* helper(Node* node,unordered_map<Node*,Node*>&mp){
    if(node==NULL) return node;
    if(mp[node]) return mp[node];
    Node* temp=new Node(node->val);
    mp[node]=temp;
    for(auto nbr:node->neighbors){
        temp->neighbors.push_back(helper(nbr,mp));
    }
    return temp;
}

Node* cloneGraph(Node* node) {
    unordered_map<Node*,Node*>mp;
    return helper(node,mp);
}