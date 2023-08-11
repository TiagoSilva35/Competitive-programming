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
            if (DFS(check,adj,parent,i,v))
                return true;
    }
    return false;
}
bool visit_all(vector<bool>&check,vector<vector<int>> &adj,vi &parent,int p){
    if (!check[1]){
        if (DFS(check,adj,parent,1,p)) return true;
    }
    return false;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vv adj(n + 10);
    vector<bool> check(n + 10, false);
    vi parent(n+1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    parent[1] = -1;
    if(visit_all(check, adj, parent,-1)){
        int a = ev;
        while (a != sv){
            s.push(a);
            a = parent[a];
        }
        if ((int)s.size() + 2 == n+1){
            cout << sv;
            while(!s.empty()){
                cout << " " << s.top();
                s.pop();
            }
            cout << " " << sv << endl;
        }
        else
            cout << "NO\n";
    }
    else
        cout << "NO" << "\n";
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