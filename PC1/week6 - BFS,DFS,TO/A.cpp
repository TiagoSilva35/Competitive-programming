#include <bits/stdc++.h>

using namespace std;

vector <vector<int>> adj(1001);
queue <int> q;
vector<int>dist(1001);

auto BFS(vector <bool>check,int s, int e){
    check[s] = true;
    q.push(s);
    dist[s] = 0;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for (auto i : adj[u])
        {
            if(check[i] == false){
                check[i] = true;
                q.push(i);
                dist[i] = dist[u] + 1;
            }
        }
        
    }
    return dist[e];
}

int main(){
    int n,m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x,y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    int s,e;
    cin >> s >> e;
    vector<bool>check(n+10,0);
    int dist = BFS(check,s,e);
    if (dist > 0)
        cout << dist << endl;
    else
        cout << -1 << endl;

}