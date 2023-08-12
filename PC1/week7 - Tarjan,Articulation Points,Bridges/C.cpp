#include <bits/stdc++.h> 
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vector<int> > vv;
typedef vector<vector<ll> > vvll;
typedef vector<vector<pii> > vvpii;
typedef vector<pll> vpll;
typedef vector<pii> vpii;
ll MOD = 998244353;
double eps = 1e-12;
#define forn(i,e) for(ll i = 0; i < e; i++)
#define forsn(i,s,e) for(ll i = s; i < e; i++)
#define rforn(i,s) for(ll i = s; i >= 0; i--)
#define rforsn(i,s,e) for(ll i = s; i >= e; i--)
#define ln "\n"
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
const int MAX_N = 1e5 + 1;
const ll LINF = 1e18;

int n, m, dfsCounter;
int dfs_num[MAX_N], dfs_low[MAX_N], visited[MAX_N];
vector<int> adj[MAX_N];
vpii bridges;

bool compare (pii a, pii b){
    if (a.first != b.first)
        return a.first < b.first;
    else{
        return a.second < b.second;
    }
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
            if (dfs_low[v] > dfs_num[u]){
                if (u < v)
                    bridges.push_back({u,v});
                else
                    bridges.push_back({v,u});
            }
                
        }
    }
}

void solve(){
    int n,m;
    while(cin >> n >> m){
        forn(i,m){int a,b; cin >> a >> b; adj[a].push_back(b); adj[b].push_back(a);}
        for (int i = 0; i < n; i++)
            if (!visited[i])
                dfs(i);
        sort(all(bridges),compare);
        if (bridges.size() == 0)
            cout << "No road" << ln;
        else{
            for (auto bridge:bridges){
                cout << bridge.first << " " << bridge.second << ln;
            }
        }
        bridges.clear();
    }
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll t = 1;
    //cin >> t;
    for(int it=1;it<=t;it++) {
     //cout << "Case #" << it+1 << ": ";
        solve();
    }
    return 0;
}