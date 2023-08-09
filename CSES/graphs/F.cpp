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
#define INF 2e18

vector<ll> dijkstra(vector<vector<pll>>& graph, ll source) {
    int n = graph.size();
    vector<ll> dist(n, INF);  
    vector<bool> visited(n, false); 

    dist[source] = 0;

    priority_queue<pll, vector<pll>, greater<pll>> pq;
    pq.push(make_pair(0, source));

    while (!pq.empty()) {
        int u = pq.top().second;  
        pq.pop();
        if (visited[u]) {
            continue;
        }
        visited[u] = true;
        for (auto& neighbor : graph[u]) {
            ll v = neighbor.first;
            ll weight = neighbor.second;

            if (dist[v] > dist[u] + weight) {
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
            }
        }
    }

    return dist;
}
 

void solve(){
    ll n,m;
    cin >> n >> m;
    vector<vector<pll>> graph(n);
    vector<ll>ANS(n);
    for (int i = 0; i < m; i++)
    {
        ll a,b,c;
        cin >> a >> b >> c;a--;b--;
        graph[a].push_back(make_pair(b,c));

    }
    ANS = dijkstra(graph,0);
    cout << ANS[0];
    for (int i = 1; i < n; i++){
        cout << " " << ANS[i];
    }
    cout << ln;    
    
    
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