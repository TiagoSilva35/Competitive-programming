#include <bits/stdc++.h>

using namespace std;

#define lli long long int

vector<vector<int>> adj(5001);
vector<bool> check(10001);
vector<int> dfs(10001, 0);
vector<int> low(10001, -1);
vector<int> parent(10001, -1);
int t = 1;
int c = 0;

void AP(int v){
    int child = 0;
    low[v] = dfs[v] = t++;
    for (auto nbr : adj[v]){
        if (dfs[nbr] == 0){
            child++;
            parent[nbr] = v;
            AP(nbr);
            low[v] = min(low[v], low[nbr]);
            if ((parent[v] == -1) && (child > 1) && !check[v]){
                c++;
                check[v] = true;
            }
            else if ((parent[v] != -1) && (low[nbr] >= dfs[v]) && !check[v]){
                c++;
                check[v] = true;
            }
        }
        else if (parent[v] != nbr){
            low[v] = min(low[v], dfs[nbr]);
        }
    }
    if (parent[v] == -1 && child == 1){
        check[v] = true;
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= n; i++){
        if (dfs[i] == 0){
            AP(i);
        }
    }

    cout << c << endl;

    return 0;
}
