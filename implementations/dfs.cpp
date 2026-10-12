
#include <bits/stdc++.h>
using namespace std;

// Recursive DFS
void recursive_dfs(int node, vector<vector<int>>& adj,
                   vector<bool>& visited) {
    visited[node] = true;
    cout << node << " ";

    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            recursive_dfs(neighbor, adj, visited);
        }
    }
}

// Iterative (Non-recursive) DFS
void iterative_dfs(int start, vector<vector<int>>& adj) {
    int n = adj.size();
    vector<bool> visited(n, false);
    stack<int> st;

    st.push(start);

    while (!st.empty()) {
        int node = st.top();
        st.pop();

        if (visited[node]) continue;

        visited[node] = true;
        cout << node << " ";

        // Reverse order preserves recursive DFS order
        for (int i = (int)adj[node].size() - 1; i >= 0; i--) {
            int neighbor = adj[node][i];
            if (!visited[neighbor]) {
                st.push(neighbor);
            }
        }
    }
}

int main() {
    int V = 5;
    vector<vector<int>> adj(V);

    adj[0] = {1, 2};
    adj[1] = {0, 3};
    adj[2] = {0, 4};
    adj[3] = {1};
    adj[4] = {2};

    vector<bool> visited(V, false);

    cout << "Recursive DFS: ";
    recursive_dfs(0, adj, visited);

    cout << "\nIterative DFS: ";
    iterative_dfs(0, adj);

    cout << '\n';
    return 0;
}
