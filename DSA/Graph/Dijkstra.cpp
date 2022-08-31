vector<int> dijkstra(int V, vector<vector<int>> adj[], int S) {
    vector<int> dist(V, INT_MAX), visited(V, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, S});
    dist[S] = 0;
    while (!pq.empty()) {
        auto p = pq.top();
        pq.pop();
        int a = p.second;
        for (auto u : adj[a]) {
            int b = u[0], w = u[1];
            if (dist[a] + w < dist[b]) {
                dist[b] = dist[a] + w;
                pq.push({dist[b], b});
            }
        }
    }
    return dist;
}