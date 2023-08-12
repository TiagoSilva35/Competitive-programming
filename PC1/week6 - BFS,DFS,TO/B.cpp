#include <bits/stdc++.h>

using namespace std;

bool BFS(vector <int>color, int v, vector<vector<int>>adj){
    queue <int> q;
    color[v] = 1;
    q.push(v);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for (auto i : adj[u])
        {
            if(color[i] == -1){
                color[i] = color[u]-1;
                q.push(i);
            }
            else if(color[i] == color[u])
                return false;
        }
    }
    return true;
}

int main(){
    int n,m;
    while(cin >> n >> m){
        vector <vector<int>> adj(301);
        for (int i = 0; i < m; i++)
        {
            int x,y;
            cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        bool bip = 0;
        
        vector<int>color(n+10,-1);
        for (int i = 1; i <= n; i++)
        {
            bip = BFS(color,i,adj);
            //cout << bip << endl;
            if (bip == false)
                break; 
        }
        
        if (bip == false)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
}