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

bool connected(vector<vector<int>>& adj,int v){
    for (auto i : adj[v]){
        if (i == 1)
            return true;
    }
    return false;
}

void DFS(int n, vector<bool>& check, vector<vector<int>>& adj, vi& temp, int v) {
    if ((int)temp.size() == n) {
        if (connected(adj,v)) {  
            temp.push_back(1);  
        }
        return;
    }
    for (auto i : adj[v]) {
        if (!check[i]) {
            check[i] = true;
            temp.push_back(i);
            DFS(n, check, adj, temp, i);
            if ((int)temp.size() == n + 1) {
                return;
            }
            check[i] = false; 
            temp.pop_back();
        }
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    vv adj(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    for (int i = 1; i <= n; i++) {
        sort(adj[i].begin(), adj[i].end());
    }
    vector<bool> check(n + 1);
    vi temp;
    check[1] = true;
    temp.pb(1);
    DFS(n, check, adj, temp, 1);
    if ((int)temp.size() != n + 1) {
        cout << "NO" << endl;
    }
    else {
        cout << temp[0];
        for (int i = 1; i < n + 1; i++) {
            cout << " " << temp[i];
        }
        cout << ln;
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