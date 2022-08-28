//* DFS
bool checkCycle(int u, vector<int> adj[], vector<bool>& vis, vector<bool>& dfsVis) {
    vis[u] = true;
    dfsVis[u] = true;
    for (auto v : adj[u]) {
        if (!vis[v]) {
            if (checkCycle(v, adj, vis, dfsVis)) return true;
        } else if (dfsVis[v]) {
            return true;
        }
    }
    dfsVis[u] = false;
    return false;
}

bool isCyclic(int V, vector<int> adj[]) {
    vector<bool> vis(V, false), dfsVis(V, false);
    for (int i = 0; i < V; i++) {
        if (!vis[i]) {
            if (checkCycle(i, adj, vis, dfsVis)) {
                return true;
            }
        }
    }
    return false;
}

//* BFS using Kahn
bool isCyclic(int V, vector<int> adj[]) {
    vector<int> indegree(V, 0);
    queue<int> q;

    for (int i = 0; i < V; i++) {
        for (auto v : adj[i]) {
            indegree[v]++;
        }
    }

    for (int i = 0; i < V; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }
    int count = 0;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        count++;
        for (auto v : adj[node]) {
            indegree[v]--;
            if (indegree[v] == 0) {
                q.push(v);
            }
        }
    }
    if (count == V) return false;
    return true;
}