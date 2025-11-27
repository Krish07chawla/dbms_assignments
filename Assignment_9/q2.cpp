#include <bits/stdc++.h>
using namespace std;

void dfs(int u, const vector<vector<int>> &adj, vector<int> &visited, vector<int> &order) {
    visited[u] = 1;
    order.push_back(u);

    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs(v, adj, visited, order);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n);
    int directed;
    cin >> directed;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        if (!directed) {
            adj[v].push_back(u);
        }
    }

    int s;
    cin >> s;

    vector<int> visited(n, 0), order;
    dfs(s, adj, visited, order);

    for (int i = 0; i < order.size(); i++) {
        if (i) cout << " ";
        cout << order[i];
    }

    cout << "\n";
    return 0;
}
