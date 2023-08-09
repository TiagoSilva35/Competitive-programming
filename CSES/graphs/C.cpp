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
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
 
#define INF INT_MAX
vv adj(200001);
vi dist(200001);
vector<bool> check(200001,0);
vi parent(200001);
queue <int> q;


auto BFS(int s, int e){
    check[s] = true;
    q.push(s);
    dist[s] = 0;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for (auto i : adj[u])
        {
            if(check[i] == false){
                check[i] = true;
                q.push(i);
                dist[i] = dist[u] + 1;
                parent[i] = u;
            }
        }      
    }
    return dist[e];
}



void solve(){
    int n,m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int ANS = BFS(1,n);
    if (ANS != 0){
        cout << ANS + 1 << ln;
        stack <int> s;
        int a = n;
        while(a != 1){
            s.push(a);
            a = parent[a];
        }
        cout << 1;
        while(!s.empty()){
            cout << " " << s.top();
            s.pop();
        }
        cout << ln;
    }
    else
        cout << "IMPOSSIBLE" << ln;
     
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