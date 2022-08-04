void dfs(vector<int>adj[],vector<int>&res,vector<bool>&visited,int u){
    visited[u]=true;
    res.push_back(u);
    for(auto v:adj[u]){
        if(!visited[v]){
            dfs(adj,res,visited,v);
        }
    }
}

vector<int> dfsOfGraph(int V, vector<int> adj[]) {
    vector<int>res;
    vector<bool>visited(V,false);
    dfs(adj,res,visited,0);
    return res;
}