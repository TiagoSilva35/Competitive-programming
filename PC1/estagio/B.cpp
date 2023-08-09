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
 

struct Edge {
	int v;
	

	int flow; 

	int C; 

	int rev; 

};

class Graph {
	int V; 
	int* level;
	vector<Edge>* adj;

public:
	Graph(int V)
	{
		adj = new vector<Edge>[V];
		this->V = V;
		level = new int[V];
	}

	void addEdge(int u, int v, int C)
	{

		Edge a{ v, 0, C, (int)adj[v].size() };


		Edge b{ u, 0, 0, (int)adj[u].size() };

		adj[u].push_back(a);
		adj[v].push_back(b); 
	}

	bool BFS(int s, int t);
	int sendFlow(int s, int flow, int t, int ptr[]);
	int DinicMaxflow(int s, int t);
};


bool Graph::BFS(int s, int t)
{
	for (int i = 0; i < V; i++)
		level[i] = -1;

	level[s] = 0; 


	list<int> q;
	q.push_back(s);

	vector<Edge>::iterator i;
	while (!q.empty()) {
		int u = q.front();
		q.pop_front();
		for (i = adj[u].begin(); i != adj[u].end(); i++) {
			Edge& e = *i;
			if (level[e.v] < 0 && e.flow < e.C) {

				level[e.v] = level[u] + 1;

				q.push_back(e.v);
			}
		}
	}

	return level[t] < 0 ? false : true;
}


int Graph::sendFlow(int u, int flow, int t, int start[])
{

	if (u == t)
		return flow;

	for (; start[u] < (int)adj[u].size(); start[u]++) {

		Edge& e = adj[u][start[u]];

		if (level[e.v] == level[u] + 1 && e.flow < e.C) {

			int curr_flow = min(flow, e.C - e.flow);

			int temp_flow
				= sendFlow(e.v, curr_flow, t, start);


			if (temp_flow > 0) {

				e.flow += temp_flow;

				adj[e.v][e.rev].flow -= temp_flow;
				return temp_flow;
			}
		}
	}

	return 0;
}

int Graph::DinicMaxflow(int s, int t)
{
	if (s == t)
		return -1;

	int total = 0;

	while (BFS(s, t) == true) {
		int* start = new int[V + 1]{ 0 };

		while (int flow = sendFlow(s, INT_MAX, t, start)) {

			total += flow;
		}
	
		delete[] start;
	}

	return total;
}

void solve(){
    int n,m;
    cin >> m >> n;
	Graph g(n+1);
    for (int i = 0; i < m; i++)
    {
        int u,v;
        cin >> u >> v;u--;v--;
        g.addEdge(u, v, 1);
        g.addEdge(v, u, 1);
    }

	cout << g.DinicMaxflow(0, n-1) << endl;
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