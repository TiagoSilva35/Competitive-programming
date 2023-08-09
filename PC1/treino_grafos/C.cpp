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
#define INF LLONG_MAX
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
typedef pair<int, int> pii;

ll dijkstra(vector<vector<pll>>& graph, int source,int n) {
    vector<ll> dist(n+1, INF);  
    dist[source] = 0;

    priority_queue<pll, vector<pll>, greater<pll>> pq;
    pq.push(make_pair(0, source));

    while (!pq.empty()) {
        int u = pq.top().second;  
        pq.pop();
        for (auto& neighbor : graph[u]) {
            ll v = neighbor.first;
            ll weight = neighbor.second;

            if (dist[v] > dist[u] + weight) {
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
            }
        }
    }

    return dist[n];
}


void solve(){
    int n;
    cin >> n;
    vector <ll> w(n);
    forsn(i,1,n){cin >> w[i];}
    vector <vector<pll>> adj(n+1);
    forsn(i,1,n){
        int v;
        cin >> v;
        adj[i].pb({v,w[i]});
    }
    forsn(i,1,n){
        int u;
        cin >> u;
        adj[i].pb({u,w[i]});
    }
    cout << dijkstra(adj,1,n) << endl;

}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll t;
    cin >> t;
    for(int it=1;it<=t;it++) {
     //cout << "Case #" << it+1 << ": ";
        solve();
    }
    return 0;
}