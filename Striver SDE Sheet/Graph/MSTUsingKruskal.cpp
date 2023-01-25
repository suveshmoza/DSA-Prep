bool comp(vector<int> a, vector<int> b) {
    return a[2] < b[2];
}

int findParent(int node, vector<int> &parent) {
    if (node == parent[node]) {
        return node;
    }
    return parent[node] = findParent(parent[node], parent);
}

void unionn(int u, int v, vector<int> &rank, vector<int> &parent) {
    u = findParent(u, parent);
    v = findParent(v, parent);
    if (rank[u] < rank[v]) {
        parent[u] = v;
    } else if (rank[u] > rank[v]) {
        parent[v] = u;
    } else {
        parent[v] = u;
        rank[u]++;
    }
}

int kruskalMST(int n, int m, vector<vector<int>> &graph) {
    sort(graph.begin(), graph.end(), comp);
    int cost = 0;
    vector<int> parent(n + 1), rank(n + 1, 0);
    for (int i = 1; i <= n; i++) parent[i] = i;
    for (int i = 0; i < m; i++) {
        if (findParent(graph[i][0], parent) != findParent(graph[i][1], parent)) {
            cost += graph[i][2];
            unionn(findParent(graph[i][0], parent), findParent(graph[i][1], parent), rank, parent);
        }
    }
    return cost;
}