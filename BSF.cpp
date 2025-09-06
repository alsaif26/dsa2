#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+2;
bool vis[N];
vector<int> adj[N];

void bfs(int start) {
    queue<int> q;
    q.push(start);
    vis[start] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";
        for (auto it : adj[node]) {
            if (!vis[it]) {
                vis[it] = true;
                q.push(it);
            }
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
        adj[v].push_back(u);   // যদি undirected করতে চাও
    }

    bfs(1); // BFS শুরু হবে 1 নাম্বার node থেকে

    return 0;
}
