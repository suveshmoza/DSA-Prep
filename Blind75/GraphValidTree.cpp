bool isCyclic(int v, vector<bool> &visited, int parent, vector<int> *adj){
visited[v] = true;
for (auto it : adj[v]){
    if (!visited[it]){
        if (isCyclic(it, visited, v, adj))
        {
            return true;
        }
    }
    else if (it != parent){
        return true;
    }
}
    return false;
}

bool checkgraph(vector<vector<int>> edges, int n, int m){
    vector<bool> visited(n, false);
    vector<int> adj[n];
    for (int i = 0; i < m; i++){
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }

    if (isCyclic(0, visited, -1, adj)){
        return false;
    }

    for (int u = 0; u < n; u++){
        if (!visited[u]){
            return false;
        }
    }
    return true;
}