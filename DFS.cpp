#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 2;
bool vis[N];
vector<int> adj[N];

void dfs(int node) {
    vis[node] = true;
    cout << node << " ";
    for (auto it : adj[node]) {
        if (!vis[it]) {
            dfs(it);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);   // directed edge u -> v
    }

    dfs(1);

    return 0;
}
