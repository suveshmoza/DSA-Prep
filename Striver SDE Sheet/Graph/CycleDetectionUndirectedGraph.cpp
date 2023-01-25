//* DFS
bool cycle(vector<int> adj[], vector<bool>& vis, int u, int prev) {
    vis[u] = true;
    for (auto v : adj[u]) {
        if (!vis[v]) {
            if (cycle(adj, vis, v, u)) {
                return true;
            }
        } else {
            if (v != prev) {
                return true;
            }
        }
    }
    return false;
}

bool isCycle(int V, vector<int> adj[]) {
    vector<bool> vis(V, false);
    for (int i = 0; i < V; i++) {
        if (!vis[i]) {
            if (cycle(adj, vis, i, -1)) {
                return true;
            }
        }
    }
    return false;
}

//* BFS
bool cycle(vector<int> adj[], vector<bool>& vis, int u) {
    queue<pair<int, int>> q;
    q.push({u, -1});
    vis[u] = true;
    while (!q.empty()) {
        int v = q.front().first;
        int prev = q.front().second;
        q.pop();
        for (auto x : adj[v]) {
            if (!vis[x]) {
                vis[x] = true;
                q.push({x, v});
            } else if (x != prev) {
                return true;
            }
        }
    }
    return false;
}

bool isCycle(int V, vector<int> adj[]) {
    vector<bool> vis(V, false);
    for (int i = 0; i < V; i++) {
        if (!vis[i]) {
            if (cycle(adj, vis, i)) {
                return true;
            }
        }
    }
    return false;
}