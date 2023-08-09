#include <bits/stdc++.h>

using namespace std;

vector<int> parent(5001);
vector <vector <int>> ANS;

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


int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        makeSet(i);
    }
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        unionSets(u, v);
    } 
}