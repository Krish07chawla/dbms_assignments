#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <limits>
#include <algorithm>

using namespace std;
typedef pair<int, int> pii;

// --- Dijkstra's Algorithm ---

void dijkstra(const vector<vector<pii>>& adj, int startNode) {
    int numNodes = adj.size();
    
    // 1. Min Heap to store {distance, vertex}
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    
    // 2. Distance vector, initialized to infinity
    const int INF = numeric_limits<int>::max();
    vector<int> dist(numNodes, INF);

    dist[startNode] = 0; 
    pq.push({0, startNode}); // Push {distance, vertex}

    cout << "Running Dijkstra's from node " << startNode << "...\n\n";

    // Loop until the priority queue is empty
    while (!pq.empty()) {
        // Extract the vertex 'u' with the minimum distance
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

       
        if (d > dist[u]) {
            continue;
        }

       
        for (const auto& edge : adj[u]) {
            int weight = edge.first;
            int v = edge.second; 
           
            if (dist[u] + weight < dist[v]) {
                
                dist[v] = dist[u] + weight;
              
                pq.push({dist[v], v});
            }
        }
    }
    cout << "Shortest Path Distances from Node " << startNode << ":\n";
    for (int i = 0; i < numNodes; ++i) {
        cout << "To Node " << i << ": ";
        if (dist[i] == INF) {
            cout << "Unreachable\n";
        } else {
            cout << dist[i] << "\n";
        }
    }
}

int main() {
    
    int numNodes = 5;
    vector<vector<pii>> adj(numNodes); 
    auto addEdge = [&](int u, int v, int w) {
        adj[u].push_back({w, v});
    };

    addEdge(0, 1, 10);
    addEdge(0, 4, 3);
    addEdge(1, 2, 2);
    addEdge(1, 4, 4);
    addEdge(2, 3, 9);
    addEdge(3, 2, 7); 
    addEdge(4, 1, 1);
    addEdge(4, 2, 8);
    addEdge(4, 3, 2);
    dijkstra(adj, 0); 

    return 0;
}