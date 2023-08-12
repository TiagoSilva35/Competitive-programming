#include <bits/stdc++.h>

using namespace std;

vector<int> parent(5001);
vector<int> setSize(5001);
map<string,int> my_map;

void makeSet(int v) {
    parent[v] = v;
    setSize[v] = 1;
}

int findSet(int v) {
    if (v != parent[v])
        parent[v] = findSet(parent[v]);
    return parent[v];
}

void unionSets(int u, int v) {
    int root1 = findSet(u);
    int root2 = findSet(v);
    if (root1 != root2) {
        if (setSize[root1] < setSize[root2]) {
            parent[root1] = root2;
            setSize[root2] += setSize[root1];
        } else {
            parent[root2] = root1;
            setSize[root1] += setSize[root2];
        }
    }
}

bool check(int u, int v) {
    return findSet(u) == findSet(v);
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        string name;
        cin >> name;
        my_map[name] = i+1;
    }

    for (int i = 1; i <= n; i++) {
        makeSet(i);
    }
    for (int i = 0; i < m; i++) {
        string u, v;
        cin >> u >> v;
        unionSets(my_map[u], my_map[v]);
    }
    int largestSetSize = 0;
    for (int i = 1; i <= n; i++) {
        int root = findSet(i);
        largestSetSize = max(largestSetSize, setSize[root]);
    }
    cout << largestSetSize << endl;
}
