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
ll MOD = 1000000007;
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
#define INF INT_MAX
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
#define lli long long int

vector<vector<lli>>adj(100001);
vector <bool> check(100001);
vector<lli> pathsCount;
int target;

void dfs(int v) {
    if (v == target) {
        pathsCount[v] = 1;
        return;
    }

    check[v] = true;
    for (int u : adj[v]) {
        if (!check[u]) {
            dfs(u);
        }
        pathsCount[v] += pathsCount[u];
        pathsCount[v] %= MOD;
    }
}

void solve() {
    int n,m;
    cin >> n >> m;
    adj.resize(n + 1);
    check.assign(n + 1, false);
    pathsCount.assign(n + 1, 0);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    target = n;
    dfs(1);

    cout << pathsCount[1] << endl;
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