#include <bits/stdc++.h>
using namespace std;
int main (){
    int V,E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;  
    vector < tuple <int,int,int> > edges;
    cout << "Enter edges (u v weight): " << endl;
    for (int i = 0; i < E; i++){
        int u,v,w;
        cin >> u >> v >> w;
        edges.push_back({u,v,w});
    }
    int source;
    cout << "Enter source vertex: ";
    cin >> source;
    vector <int> dist(V,INT_MAX);
    dist[source] = 0;
    for (int i = 1; i <= V - 1; i++){
        for (auto edge : edges){
            int u = get<0>(edge);
            int v = get<1>(edge);
            int weight = get<2>(edge);
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v]){
                dist[v] = dist[u] + weight;
            }
        }
    }
    cout << "Shortest distances from source vertex " << source << ":" << endl;
    for (int i = 0; i < V; i++){
        if (dist[i] == INT_MAX){
            cout << "INT ";
        } else {
            cout << dist[i] << " ";
        }
    }
    return 0;
}