//* DFS
void dfs(vector<int> adj[], int u, vector<bool> &vis, vector<int> &res) {
    vis[u] = true;
    for (auto v : adj[u]) {
        if (!vis[v]) {
            dfs(adj, v, vis, res);
        }
    }
    res.push_back(u);
    return;
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e) {
    vector<int> adj[v];
    for (int i = 0; i < e; i++) {
        adj[edges[i][0]].push_back(edges[i][1]);
    }
    vector<bool> vis(v, false);
    vector<int> res;
    for (int i = 0; i < v; i++) {
        if (!vis[i]) {
            dfs(adj, i, vis, res);
        }
    }
    reverse(res.begin(), res.end());
    return res;
}

//* BFS using Kahn Algo
vector<int> topoSort(int V, vector<int> adj[]) {
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
    vector<int> res;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        res.push_back(node);
        for (auto v : adj[node]) {
            indegree[v]--;
            if (indegree[v] == 0) {
                q.push(v);
            }
        }
    }
    return res;
}