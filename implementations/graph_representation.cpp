#include <iostream>
#include <vector>
#include <list>
using namespace std;
class Graph {
int V;
vector<vector<pair<int, int>>> adj;
public:
Graph(int vertices) {
V = vertices;
adj.resize(V);
}
void addEdge(int u, int v, int weight = 1) {
adj[u].push_back({v, weight});
adj[v].push_back({u, weight});
}
void printGraph() {
for (int i = 0; i < V; i++) {
cout << "Vertex " << i << "-> ";
for (auto edge : adj[i]) {
cout << "(" << edge.first
<< ", weight = "
<< edge.second << ") ";
}
cout << endl;
}
}
};