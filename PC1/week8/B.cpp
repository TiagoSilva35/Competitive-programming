#include <iostream>
#include <vector>
#include <climits>

using namespace std;

#define INF INT_MAX-1002

typedef pair<int, int> pii;

bool flag = false;

vector<int> BF(vector<vector<pii>>& graph, int source) {
    int n = (int)graph.size();
    vector<int> dist(n+1, INF);
    dist[source] = 0;

    for (int i = 1; i <= n-1; i++) {
        for (int u = 1; u <= n-1; u++) {
            for (auto nbr : graph[u]) {
                int v = nbr.first;
                int weight = nbr.second;
                if (dist[v] > dist[u] + weight) {
                    dist[v] = dist[u] + weight;
                }
            }
        }
    }

    for (int u = 1; u <= n-1; u++) {
        for (auto nbr : graph[u]) {
            int v = nbr.first;
            int weight = nbr.second;
            if (dist[v] > dist[u] + weight) {
                flag = true;
            }
        }
    }

    return dist;
}

int main() {
    int numVertices, numEdges , source , target;
    cin >> numVertices >> numEdges;

    vector<vector<pii>> graph(numVertices + 1);

    for (int i = 0; i < numEdges; i++) {
        int u, v, weight;
        cin >> u >> v >> weight;
        graph[u].push_back(make_pair(v, weight));  
    }
    cin >> source >> target;

    vector<int> fd = BF(graph,source);

    if(flag)
        cout << -1 << endl;
    else
        cout << fd[target] << endl;
}