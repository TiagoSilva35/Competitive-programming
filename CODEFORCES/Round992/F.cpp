
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

ll n, k;
const int mxN = 2e5 + 2;
bool visited[mxN];
ll total = 0;
ll cum_coutn[mxN];
ll parent[mxN];

void dfs (int v, vector<vector<ll>> adj){
    visited[v] = true;
    for (auto i : adj[v]){
        if (!visited[i]){
            if (cum_coutn[parent[i]] == 1){
                cum_coutn[parent[i]]+=2;
            }
            else cum_coutn[i]++;
            dfs(i, adj);
        }
    }
}


void solve(){
    cin >> n >> k;
    vector<vector<ll>> adj(n + 10);
    for (int i = 0; i < n - 1; i++){
        int a; cin >> a;
        parent[i+2] = a;
        adj[a].push_back(i+2);
        adj[i+2].push_back(a);
    }
    memset(visited, false, sizeof(visited));
    dfs(1, adj);
    ll ans = 0;
    if (k == (ll)adj[1].size() - 1){
        for (int i = 1; i <= n; ++i){
            ans += cum_coutn[i];
        }
        cout << ans << endl;
        return;
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
