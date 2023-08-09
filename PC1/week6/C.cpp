#include <bits/stdc++.h>

using namespace std;

vector <vector<int>> adj(1001);
queue <int> q;
vector<int>dist(1001);

auto BFS(vector <bool>check,int s){
    check[s] = true;
    q.push(s);
    int c = 1;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for (auto i : adj[u])
        {
            if(check[i] == false){
                check[i] = true;
                q.push(i);
                c++;
            }
        }
        
    }
    return c;
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

    vector<bool>check(n+10,0);
    int c = BFS(check,1);
    if (c < n)
        cout << "No" << endl;
    else
        cout << "Yes" << endl;

}