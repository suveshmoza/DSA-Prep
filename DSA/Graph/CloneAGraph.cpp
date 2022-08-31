Node* dfs(Node* curr, unordered_map<Node*, Node*>& mp) {
    vector<Node*> neigh;
    Node* copy = new Node(curr->val);
    mp[curr] = copy;
    for (auto v : curr->neighbors) {
        if (mp.find(v) != mp.end()) {
            neigh.push_back(mp[v]);
        } else {
            neigh.push_back(dfs(v, mp));
        }
    }
    copy->neighbors = neigh;
    return copy;
}

Node* cloneGraph(Node* node) {
    if (node == NULL) return NULL;
    unordered_map<Node*, Node*> mp;
    return dfs(node, mp);
}