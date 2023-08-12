#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> Edge; 
typedef pair<int, Edge> WeightedEdge;  

vector<int> parent; 

void makeSet(int v) {
    parent[v] = v;
}

int findSet(int v) {
    if (v != parent[v])
        parent[v] = findSet(parent[v]);
    return parent[v];
}

void unionSets(int u, int v) {
    int root1 = findSet(u);
    int root2 = findSet(v);
    parent[root2] = root1;
}

vector<Edge> kruskalMST(vector<WeightedEdge>& edges, int numVertices) {
    vector<Edge> minimumSpanningTree;
    
    sort(edges.begin(), edges.end());
    
    parent.resize(numVertices);
    for (int v = 0; v < numVertices; ++v) {
        makeSet(v);
    }
    
    for (auto& weightedEdge : edges) {
        int u = weightedEdge.second.first;
        int v = weightedEdge.second.second;
        
        if (findSet(u) != findSet(v)) {
            minimumSpanningTree.push_back({u, v});
            unionSets(u, v);
        }
    }
    
    return minimumSpanningTree;
}

int main() {    
    vector<Edge> minimumSpanningTree = kruskalMST(edges, numVertices);
    
    cout << "Minimum Spanning Tree:" << endl;
    for (auto& edge : minimumSpanningTree) {
        cout << edge.first << " - " << edge.second << endl;
    }
    
    return 0;
}
