#include <bits/stdc++.h>
using namespace std;

int ANS = 0;

void rec(vector<vector<int>>& G, vector<bool>& visited, int idx,int count) {
    visited[idx] = true;
    count++;

    for (auto nbr : G[idx]) {
        if (!visited[nbr]) {
            rec(G, visited, nbr,count);
        }
    }
    visited[idx] = false;
    ANS = max(count,ANS);
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> G(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    vector<bool> visited(n, false);
    for (int i = 0; i < n; i++) {
        if(!visited[i])
            rec(G, visited, i,0);
    }

    cout << ANS << endl;

    return 0;
}
