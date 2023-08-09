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
 
bool BFS(vector <int>&color, int v, vector<vector<int>>&adj){
    queue <int> q;
    color[v] = 2;
    q.push(v);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for (auto i : adj[u])
        {
            if(color[i] == -1){
                color[i] = color[u]%2+1;
                q.push(i);
            }
            else if(color[i] == color[u])
                return false;
        }
    }
    return true;
}

void solve(){
    int n,m;
    cin >> n >> m;
    vv adj(n+1);
    for (int i = 0; i < m; i++)
    {
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vi color(n+1,-1);
    bool ANS = BFS(color,1,adj);
    for (int i = 1; i <= n ; i++){
        if (color[i] == -1){
            ANS = BFS(color,i,adj);
        }
    }
    if (ANS){
        cout << color[1];
        for (int i = 2; i <=n ; i++) cout << " " << color[i];
        cout << ln;
    }
    else cout << "IMPOSSIBLE" << ln;
    
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