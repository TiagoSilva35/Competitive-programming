#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;

vi temp;
bool flag = false;
stack<int> s;
int sv,ev;

bool DFS(vector<bool>&check,vector<vector<int>> &adj,vi &parent,int v,int p){
    check[v] = true;
    parent[v] = p;
    for (auto i : adj[v])
    {
        if (i == p)continue;
        if(check[i]){
            sv = i;
            ev = v;
            return true;
        }
        if (!check[i])
            if (DFS(check,adj,parent,i))
                return true;
    }
    return false;
}

bool visit_all(int n,vector<bool>&check,vector<vector<int>> &adj,vi &parent){
    for(int i = 1; i <= n ; i++){
        if (!check[i]){
            if (DFS(check,adj,parent,i,-1)) return true;
        }
        
    }
    return false;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vvi adj(n + 1);
    vector<bool> check(n + 1, false);
    vi parent(n+1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }
    parent[1] = -1;
    if(visit_all(n,check, adj, parent,-1)){
        int a = ev;
        while (a != sv){
            s.push(a);
            a = parent[a];
        }
        cout << s.size() + 2 << endl;
        cout << sv;
        while(!s.empty()){
            cout << " " << s.top();
            s.pop();
        }
        cout << " " << sv << endl;
    }
    else
        cout << "IMPOSSIBLE" << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    // cin >> t;
    for (int it = 1; it <= t; it++) {
        // cout << "Case #" << it+1 << ": ";
        solve();
    }
    return 0;
}
