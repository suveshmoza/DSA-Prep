vector<int> parent(10000, 0), rank(10000, 0);

int findParent(int node) {
    if (node == parent[node]) {
        return node;
    }
    return parent[node] = findParent(parent[node]);
}

void union(int u, int v) {
    u = findParent(u);
    v = findParent(v);
    if (rank[u] < rank[v]) {
        parent[u] = v;
    } else if (rank[u] > rank[v]) {
        parent[v] = u;
    } else {
        parent[v] = u;
        rank[u]++;
    }
}