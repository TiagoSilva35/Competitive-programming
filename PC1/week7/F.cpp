#include <bits/stdc++.h>

using namespace std;

#define lli long long int

const int MAX_N = 1e5 + 1;

int dfsCounter;
int dfs_num[MAX_N], dfs_low[MAX_N], visited[MAX_N];
vector<int> adj[MAX_N];
vector <pair<int,int>>  aps;

bool compare (pair<int,int>a, pair<int,int>b){
    return a.second > b.second;
}

void dfs(int u, int p = -1) {
    dfs_num[u] = dfs_low[u] = dfsCounter++;
    visited[u] = 1;
    int num_child = 0;
    for (int v : adj[u]) {
        if (v == p) continue; 
        if (visited[v]) dfs_low[u] = min(dfs_low[u], dfs_num[v]); 
        else { 
            dfs(v, u);
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);  
            num_child++;

            if (dfs_low[v] >= dfs_num[u] && p != -1)
                aps.push_back({u,(int)adj[u].size()});
        }
    }
    if (p == -1 && num_child > 1) 
        aps.push_back({u,(int)adj[u].size()});
}

int main(){
    int n;
    while(cin >> n){
        for (int i = 1; i <= n; i++){
            adj[i].clear();
            int counter;
            cin >> counter;
            for (int j = 0; j < counter; j++)
            {
                int k;
                cin >> k;
                adj[i].push_back(k);

            }
            
            
        }
        memset(dfs_low, -1, sizeof dfs_low);
        memset(dfs_num, -1, sizeof dfs_num);
        memset(visited, 0, sizeof visited);
        aps.clear();
        for (int i = 1; i <= n; i++){
            if (!visited[i]){
                dfs(i);
            }
        }
        sort(aps.begin(),aps.end(),compare);
        if ((int)aps.size() == 0)
            cout << "Strong network" << endl;
        else
            cout << aps[0].second << endl;
        dfsCounter = 0;
    }
    return 0;
}
