#include <bits/stdc++.h>

using namespace std;

#define lli long long int

void DFS(vector<bool>&check,vector<vector<lli>> &adj,int v,stack <int> &s){
    check[v] = true;
    for (auto i : adj[v])
    {
        if(check[i] == false)
            DFS(check,adj,i,s);
    }
    s.push(v);
}   

int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<lli>> adj(n+1);
    for (int i = 0; i < m; i++){
        int x,y;
        cin >> x >> y;
        adj[x].push_back(y);
    }
    vector<bool> check(n+1, false);
    stack <int> s;
    DFS(check,adj,1,s);
    cout << s.top();
    s.pop();
    while (!s.empty())
    {
        cout << " " << s.top();
        s.pop();
    }

    cout << endl;
    
}
#include <bits/stdc++.h>

using namespace std;

#define lli long long int

void DFS(vector<bool>&check,vector<vector<lli>> &adj,int v,stack <int> &s){
    check[v] = true;
    for (auto i : adj[v])
    {
        if(check[i] == false)
            DFS(check,adj,i,s);
    }
    s.push(v);
}   

int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<lli>> adj(n+1);
    for (int i = 0; i < m; i++){
        int x,y;
        cin >> x >> y;
        adj[x].push_back(y);
    }
    vector<bool> check(n+1, false);
    stack <int> s;
    DFS(check,adj,1,s);
    cout << s.top();
    s.pop();
    while (!s.empty())
    {
        cout << " " << s.top();
        s.pop();
    }

    cout << endl;
    
}
