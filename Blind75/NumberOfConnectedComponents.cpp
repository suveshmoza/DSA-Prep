void dfsRec(vector<vector<int>> adj, int V, int s, bool visited[]){
    visited[s] = true;
    for(int j = 0; j < V; j++){
        if(adj[s][j] == 1 and visited[j] == false){
            dfsRec(adj, V, j, visited);
        }
    }
}

int numProvinces(vector<vector<int>> adj, int V) {
    bool visited[V] = {0};
    int res = 0;
    for(int i = 0; i < V; i++){
        for(int j = 0; j < V; j++){
            if(adj[i][j] == 1 and visited[i] == false){
                dfsRec(adj, V, j, visited);        
                res++;
            }
        }
    }
    return res;
}