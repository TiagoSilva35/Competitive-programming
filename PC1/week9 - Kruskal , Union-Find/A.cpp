#include <bits/stdc++.h>

using namespace std;

vector<int> parent(5001);

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

bool check(int u, int v) {
    return findSet(u) == findSet(v);
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
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int u, v;
        cin >> u >> v;
        if (check(u, v)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}
           
