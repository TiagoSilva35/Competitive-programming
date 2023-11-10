#include <bits/stdc++.h>
#include <cctype>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vector<int>> vvii;
typedef vector<pll> vpll;
typedef vector<pii> vpii;
ll MOD = 1000000007;
double eps = 1e-12;
#define forn(i,e) for(ll i = 0; i < e; i++)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF INT_MAX
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

ll dijkstra(vector<vector<pii>> &graph, int source, int target) {
    int n = graph.size();
    ll ans = 0;
    vi dist(n, 0);
    vector<bool> visited(n, false);
    dist[source] = 1;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push(make_pair(0, source));
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        if (u == target) {
            ans += dist[u];
            ans %= MOD;
        }
        if (visited[u]) continue;
        visited[u] = true;
        for (auto &neighbor : graph[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;
            if (dist[v] == 0 || dist[v] == dist[u] + weight) {
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
            }
        }
    }
    return ans;
}

void solve(){
    int N, M;
	cin >> N >> M;
	vector<vector<pii>> graph(N + 1,vector<pii>());
	forn(i,M){
		int a, b;
		cin >> a >> b;a--;b--;
		graph[a].push_back(make_pair(b,0));
	}
	cout << dijkstra(graph, 0, N-1) <<endl;
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
