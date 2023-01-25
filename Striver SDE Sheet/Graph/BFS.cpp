vector<int> bfsOfGraph(int V, vector<int> adj[]) {
    vector<int>res;
    vector<bool>visited(V,false);
    queue<int>q;
    q.push(0);
    visited[0]=true;
    while(!q.empty()){
        auto front=q.front();
        q.pop();
        res.push_back(front);
        for(auto v:adj[front]){
            if(!visited[v]){
                q.push(v);
            }
            visited[v]=true;
        }
    }
    return res;
}