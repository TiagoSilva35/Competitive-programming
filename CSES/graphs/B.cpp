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
#define lli long long int
vector<vector<int>> adj(200001);
vector<bool> on_stack(200001);
vector<int> dfs(200001, 0);
vector<int> low(200001, -1);
lli t = 1;
lli c = 0;
stack<int> S;
vi temp;
vv all_scs;

void Tarjan(int v){
    low[v] = dfs[v] = t++;
    S.push(v);
    on_stack[v] = true;
    for(auto nbr:adj[v]){
        if(dfs[nbr] == 0){
            Tarjan(nbr);
            low[v] = min(low[v],low[nbr]);
        }
        else if(on_stack[nbr] == true){
            low[v] = min(low[v],dfs[nbr]);
        }
    }
    if (low[v] == dfs[v]){
        int nbr;
        do {
            nbr = S.top();
            S.pop();
            on_stack[nbr] = false;
            temp.pb(nbr);
        } while (nbr != v);
        all_scs.pb(temp);
        temp.clear();
        c++;
    }
}

void solve(){
    lli m,n;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i = 1; i <= n; i++)
    {
        if (low[i] == -1){
            Tarjan(i);
        }
    }

    cout << (int)all_scs.size()-1 << endl;
    for(int i = 1; i < (int)all_scs.size(); i++)
        cout << all_scs[i-1][0] << " " << all_scs[i][0] << ln;
    
    

    
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