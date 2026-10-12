
#include <bits/stdc++.h>
using namespace std;

// Disjoint Set Union (DSU)
class DSU {
    vector<int> parent, sz;

public:
    DSU(int n) {
        parent.resize(n);
        sz.assign(n, 1);
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x) {
        if (parent[x] == x)
            return x;

        return parent[x] = find(parent[x]);
    }

    bool unite(int a, int b) {
        a = find(a);
        b = find(b);

        if (a == b)
            return false;

        if (sz[a] < sz[b])
            swap(a, b);

        parent[b] = a;
        sz[a] += sz[b];

        return true;
    }
};

// Edge: {weight, {u, v}}
int kruskal(int V, vector<tuple<int, int, int>>& edges) {
    sort(edges.begin(), edges.end());

    DSU dsu(V);
    int totalWeight = 0;
    int edgesUsed = 0;

    cout << "Edges in the Minimum Spanning Tree:\n";

    for (auto [weight, u, v] : edges) {
        if (dsu.unite(u, v)) {
            cout << u << " - " << v
                 << " (weight: " << weight << ")\n";

            totalWeight += weight;
            edgesUsed++;
        }

        if (edgesUsed == V - 1)
            break;
    }

    if (edgesUsed != V - 1) {
        cout << "Graph is disconnected; no spanning tree exists.\n";
        return -1;
    }

    cout << "Total MST weight: " << totalWeight << '\n';
    return totalWeight;
}

int main() {
    int V = 5;

    vector<tuple<int, int, int>> edges = {
        {2, 0, 1},
        {4, 0, 2},
        {1, 1, 2},
        {7, 1, 3},
        {3, 2, 4},
        {1, 3, 4},
        {5, 1, 4}
    };

    kruskal(V, edges);

    return 0;
}
