
#include <bits/stdc++.h>
using namespace std;

// Dijkstra's Algorithm
// Time Complexity: O((V + E) log V)

vector<int> dijkstra(int V,
    vector<vector<pair<int, int>>>& adj,
    int source) {

    vector<int> dist(V, INT_MAX);
    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>
    > pq;

    dist[source] = 0;
    pq.push({0, source});

    while (!pq.empty()) {
        int d = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        // Ignore outdated entries
        if (d > dist[node]) continue;

        for (auto edge : adj[node]) {
            int neighbor = edge.first;
            int weight = edge.second;

            if (dist[node] + weight < dist[neighbor]) {
                dist[neighbor] = dist[node] + weight;
                pq.push({dist[neighbor], neighbor});
            }
        }
    }

    return dist;
}

int main() {
    int V = 5;
    vector<vector<pair<int, int>>> adj(V);

    // Undirected weighted graph
    auto addEdge = [&](int u, int v, int w) {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    };

    addEdge(0, 1, 2);
    addEdge(0, 2, 4);
    addEdge(1, 2, 1);
    addEdge(1, 3, 7);
    addEdge(2, 4, 3);
    addEdge(3, 4, 1);

    int source = 0;
    vector<int> dist = dijkstra(V, adj, source);

    cout << "Shortest distances from vertex "
         << source << ":\n";

    for (int i = 0; i < V; i++) {
        cout << "Vertex " << i << ": ";

        if (dist[i] == INT_MAX)
            cout << "Unreachable\n";
        else
            cout << dist[i] << '\n';
    }

    return 0;
}
