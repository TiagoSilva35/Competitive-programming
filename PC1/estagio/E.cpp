#include <bits/stdc++.h>

using namespace std;

class EdmondsKarp {
 private:
  int V;
  vector<vector<int>> res;
  vector<vector<int>> adj;

  int bfs(int s, int t, vector<int>& parent) {
    fill(parent.begin(), parent.end(), -1);
    parent[s] = -2;
    queue<pair<int, int>> q;
    q.push(make_pair(s, INT_MAX));

    while (!q.empty()) {
      int cur = q.front().first;
      int flow = q.front().second;
      q.pop();

      for (int next : adj[cur]) {
        if (parent[next] == -1 && res[cur][next]) {
          parent[next] = cur;
          int new_flow = min(flow, res[cur][next]);
          if (next == t) return new_flow;
          q.push(make_pair(next, new_flow));
        }
      }
    }
    return 0;
  }

 public:
  EdmondsKarp(int V) {
    this->V = V;
    res.assign(V, vector<int>(V, 0));
    adj.assign(V, vector<int>());
  }

  void addEdge(int u, int v, int w) {
    res[u][v] = w;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  int maxFlow(int s, int t) {
    int flow = 0;
    vector<int> parent(V);
    int new_flow;

    while ((new_flow = bfs(s, t, parent))) {
      flow += new_flow;
      int cur = t;
      while (cur != s) {
        int prev = parent[cur];
        res[prev][cur] -= new_flow;
        res[cur][prev] += new_flow;
        cur = prev;
      }
    }
    return flow;
  }
};

int main (void){
    int n,m;
    cin >> n >> m;
    EdmondsKarp karp(n+1);
    for (int i = 0; i < m; i++)
    {
        int u,v;
        cin >> u >> v;
        karp.addEdge(u,v,1);
        karp.addEdge(v,u,1);

    }
    cout << karp.maxFlow(1,n) <<endl;
}