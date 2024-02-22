#include <bits/stdc++.h> 
        
using namespace std;
        
typedef long long ll;

#define forn(i,e) for(ll i = 0; i < e; i++)
#define INF INT_MAX
#define all(x) (x).begin(), (x).end()

const int mxN = 1e5;
vector<vector<int>> adj(mxN + 1);
int p[mxN + 1];
int anc[mxN + 1];
bool visited[mxN + 1];
int n, m, a, b;
vector<int> ans;
        
void dfs(int v){
    anc[v] = 1;
    visited[v] = true;
    for (auto u: adj[v]){
        p[u] = v;
        if (anc[u]){
            ans.push_back(u);
            int sv = u;
            int cv = p[u];
            while (cv != sv){
                ans.push_back(cv);
                cv = p[cv];
            }
            ans.push_back(sv);
            reverse(all(ans));
            cout << ans.size() << endl;
            for (auto &i: ans){
                cout << i << " ";
            }   
            exit(0);
        }
        if (!visited[u]){
            anc[u] = 1;
            dfs(u);
        }
    }
    anc[v] = 0;
}


void solve(){
    cin >> n >> m;
    for (int i = 0; i < m; ++i){
        cin >> a >> b;
        adj[a].push_back(b);
    }
    p[1] = -1;
    for (int i = 1; i <= n; ++i){
        if (!visited[i])
            dfs(i);
    }
    if (!ans.size()){
        cout << "IMPOSSIBLE" << endl;
        return;
    }
}
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	ll t = 1;
//	cin >> t;
        for(int it=1;it<=t;it++) {
            //cout << "Case #" << it+1 << ": ";
            solve();
        }
        return 0;
    }

