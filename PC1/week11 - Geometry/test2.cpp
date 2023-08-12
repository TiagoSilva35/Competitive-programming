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

int dijkstra(vector <vector<pair<int,pair<int,int>>>> graph, int source, int target,int n,int tp) {
    vector<int> dist(n+10, INF);  
    vector<bool> visited(n+10, false); 

    dist[source] = tp;

    priority_queue<pii, vector<pii>, greater<pii>> pq;

    pq.push(make_pair(0, source));

    while (!pq.empty()) {
        int u = pq.top().second;  
        pq.pop();
        if (visited[u]) {
            continue;
        }
        visited[u] = true;
        for (auto& neighbor : graph[u]) {
            int v = neighbor.first;
            int weight = neighbor.second.second;
            if (neighbor.second.first >= dist[u]){
                if (dist[v] > weight) {
                    dist[v] = weight;
                    pq.push(make_pair(dist[v], v));
                }
            }
        }
    }

    return dist[target];
}


void solve(){
    int N,M,P,C,tp;
    cin >> N >> M >> P >> C >> tp;
    vector <vector<pair<int,pair<int,int>>>> adj(N+10);
    for (int i = 1; i <= M; i++)
    {
        int u,v,ti,tf;
        cin >> u >> v >> ti >> tf;
        adj[u].push_back(make_pair(v,make_pair(ti,tf)));

    }
    int ANS = dijkstra(adj,P,C,N,tp);
    if (ANS == INT_MAX)
        cout << "Impossivel" << ln;
    else
        cout << ANS << ln;
    adj.clear();

    
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll t = 1;
    cin >> t;
    for(int it=1;it<=t;it++) {
     //cout << "Case #" << it+1 << ": ";
        solve();
    }
    return 0;
}