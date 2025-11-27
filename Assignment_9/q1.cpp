#include <bits/stdc++.h>
using namespace std;

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
    queue<int> q;

    visited[s] = 1;
    q.push(s);

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        order.push_back(u);

        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = 1;
                q.push(v);
            }
        }
    }

    for (int i = 0; i < order.size(); i++) {
        if (i) cout << " ";
        cout << order[i];
    }

    cout << "\n";
    return 0;
}
