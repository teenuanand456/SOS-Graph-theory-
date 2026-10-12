
#include <bits/stdc++.h>
using namespace std;

bool isBipartite(vector<vector<int>>& adj, int V) {
    vector<int> color(V, -1);
    queue<int> q;

    // Handle disconnected graphs too
    for (int i = 0; i < V; i++) {
        if (color[i] != -1) continue;

        color[i] = 0;
        q.push(i);

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int neighbor : adj[node]) {
                if (color[neighbor] == -1) {
                    color[neighbor] = 1 - color[node];
                    q.push(neighbor);
                }
                else if (color[neighbor] == color[node]) {
                    return false;
                }
            }
        }
    }

    return true;
}

int main() {
    int V = 5;
    vector<vector<int>> adj(V);

    // Undirected graph
    adj[0] = {1, 2};
    adj[1] = {0, 3};
    adj[2] = {0, 4};
    adj[3] = {1};
    adj[4] = {2};

    if (isBipartite(adj, V))
        cout << "The graph is bipartite\n";
    else
        cout << "The graph is not bipartite\n";

    return 0;
}
