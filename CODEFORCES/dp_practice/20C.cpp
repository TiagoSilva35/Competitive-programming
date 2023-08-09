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

vector<int>parent(100001);

void dijkstra(vector<vector<pii>>& graph, int source, int target) {
    int n = graph.size();
    vector<int> dist(n+1, INF);  
    vector<bool> visited(n+1, false); 
    dist[source] = 0;
    parent[source] = -1;

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push(make_pair(0, source));

    while (!pq.empty()) {
        int u = pq.top().second;  
        pq.pop();
        if (visited[u]) {
            continue;
        }
        visited[u] = true;
        if (u == target) {
            break;
        }
        for (auto& neighbor : graph[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;
            parent[v] = u;
            if (dist[v] > dist[u] + weight) {
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
            }
        }
    }

    return;
}


void solve(){
     int n,m;
    cin >> n >> m;
    cout << 1;
    vector<vector<pii>> graph(n+1);
    for (int i = 0; i < m; i++)
    {   
        int u,v,w;
        cin >> u >> v >> w;
        graph[u].pb(mp(v,w));
        graph[v].pb(mp(u,w));
    }

    dijkstra(graph,1,n);
    stack<int>s;
    int p = n;
    while(p != -1){
        s.push(p);
        p = parent[p];
        cout << p << endl; 
    }
    cout << s.top();
    s.pop();
    while(!s.empty()){
        cout << " " << s.top();s.pop();
    }

}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll t = 1;
    //cin >> t;
    for(int it=1;it<=t;it++) {
        solve();
    }
    return 0;
}