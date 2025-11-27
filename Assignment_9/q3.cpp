#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

// Structure to represent an edge in the graph
struct Edge {
    int u, v; // Endpoints of the edge
    int weight;
};

// Custom comparator for sorting edges by weight (used for Kruskal's)
bool compareEdges(const Edge& a, const Edge& b) {
    return a.weight < b.weight;
}

// --- Disjoint Set Union (DSU) Implementation ---

// Parent array for DSU. parent[i] stores the parent of node i.
vector<int> parent;

// Find operation with Path Compression
int findSet(int i) {
    if (parent[i] == i)
        return i;
    return parent[i] = findSet(parent[i]); // Path compression
}

// Union operation by Rank (or just simple union)
void unionSets(int i, int j) {
    int root_i = findSet(i);
    int root_j = findSet(j);
    if (root_i != root_j) {
        // Simple union: make one root the parent of the other
        parent[root_i] = root_j;
    }
}

// --- Kruskal's Algorithm ---

void kruskalMST(int numNodes, vector<Edge>& edges) {
    // 1. Initialize DSU structure
    parent.resize(numNodes);
    iota(parent.begin(), parent.end(), 0); // Fill parent[i] = i (each node is its own parent)

    // 2. Sort all edges by weight
    sort(edges.begin(), edges.end(), compareEdges);

    vector<Edge> mstEdges;
    int mstWeight = 0;
    int edgesCount = 0;

    cout << "Edges selected for MST (Kruskal's):\n";

    // 3. Iterate through all sorted edges
    for (const auto& edge : edges) {
        // Check if adding this edge creates a cycle (i.e., if u and v are already in the same set)
        if (findSet(edge.u) != findSet(edge.v)) {
            // No cycle, add the edge to MST
            mstEdges.push_back(edge);
            mstWeight += edge.weight;
            unionSets(edge.u, edge.v); // Merge the two sets
            edgesCount++;
            
            cout << "Edge: " << edge.u << " - " << edge.v << " (Weight: " << edge.weight << ")\n";

            // Optimization: MST is complete when it has (numNodes - 1) edges
            if (edgesCount == numNodes - 1) {
                break;
            }
        }
    }

    cout << "\nTotal MST Weight: " << mstWeight << "\n";
}

int main() {
    // Graph with 6 nodes (0 to 5)
    int numNodes = 6; 
    vector<Edge> edges = {
        {0, 1, 4}, {0, 2, 4}, {1, 2, 2},
        {2, 3, 3}, {2, 5, 2}, {2, 4, 4},
        {3, 4, 3}, {5, 4, 3}
    };

    kruskalMST(numNodes, edges);

    return 0;
}