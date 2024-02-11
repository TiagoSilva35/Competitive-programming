#include <bits/stdc++.h> 
#include <queue>
#include <utility>

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

int sp;
int total = 0;

int dijkstra(vector<vector<pii>>& graph, int source, int target) {
	vector<int> dist(100001, INF);
	vector<bool> visited(100001, false);
	int n = graph.size();
	dist[source] = 0;
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
			if (dist[v] >= dist[u] + weight) {
				dist[v] = dist[u] + weight;
				pq.push(make_pair(dist[v], v));
			}
		}
	}
	return dist[target];
}
void solve(){
	int n, m; cin >> n >> m;
	vector<vector<pii>> adj(n);
	map<pii,int> am;
	forn(i, m){
		bool flag = false;
		int a, b, c;cin >> a >> b >> c;
		pii k = make_pair(b, c);
		for(auto p: adj[a]){
			if (p.first == b && p.second >= c){
				flag = true;
			}
		}
		if (!flag){
			adj[a].pb(k);
			am[k]++;
		}
	}
	sp = dijkstra(adj, 0, n - 1);
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
