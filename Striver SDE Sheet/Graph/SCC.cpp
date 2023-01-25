//* Sort nodes wrt finishing time
//* Transpose the original graph
//* Make dfs call wrt to nodes sorted above

void dfs1(vector<int> adj[], int u, vector<bool> &visited, stack<int> &st) {
    visited[u] = true;
    for (auto v : adj[u]) {
        if (!visited[v]) {
            dfs1(adj, v, visited, st);
        }
    }
    st.push(u);
}

void dfs2(vector<int> revAdj[], vector<bool> &visited, vector<int> &temp, int u) {
    visited[u] = true;
    temp.push_back(u);
    for (auto v : revAdj[u]) {
        if (!visited[v]) {
            dfs2(revAdj, visited, temp, v);
        }
    }
}

vector<vector<int>> stronglyConnectedComponents(int n, vector<vector<int>> &edges) {
    vector<int> adj[n], revAdj[n];
    for (int i = 0; i < edges.size(); i++) {
        adj[edges[i][0]].push_back(edges[i][1]);
        revAdj[edges[i][1]].push_back(edges[i][0]);
    }

    stack<int> st;
    vector<bool> visited(n, false);
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs1(adj, i, visited, st);
        }
    }
    fill(visited.begin(), visited.end(), false);
    vector<vector<int>> res;
    while (!st.empty()) {
        int top = st.top();
        st.pop();
        if (!visited[top]) {
            vector<int> temp;
            dfs2(revAdj, visited, temp, top);
            res.push_back(temp);
        }
    }
    return res;
}