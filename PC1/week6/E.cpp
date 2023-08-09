#include <bits/stdc++.h>

using namespace std;

vector<vector<int>>adj(1501);

void deg(vector <int> &d){
    for (auto nbr_list:adj){
        for(auto nbr : nbr_list){
            d[nbr]++;
        }
    }
}

void TS(vector <int> &d,int n){
    queue<int> q2;
    queue <int> q;
    for(int i = 1; i < n ; i++){
        if(d[i] == 0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int u = q.front();
        q.pop();
        q2.push(u);
        for(auto nbr : adj[u]){
            d[nbr]--;
            if(d[nbr] == 0)
                q.push(nbr);
        }
    }
    cout << q2.front();
    q2.pop();
    for(int i = 1; i < n ; i++){
        cout << " " << q2.front();
        q2.pop();
    }
    cout << endl;
}

int main(){
    int n,m;
    cin >> n >> m;
    vector<int>degree(n+1,0);
    for (int i = 0; i < m; i++)
    {
        int x,y;
        cin >> x >> y;
        adj[x].push_back(y);
    }
    deg(degree);
    TS(degree,n);
    
}