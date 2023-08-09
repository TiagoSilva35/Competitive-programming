#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;

#define INF INT_MAX

typedef pair<int, int> pii;

vector<int> dijkstra(vector<vector<pii>>& graph, int source, int target) {
    int n = graph.size();
    vector<int> dist(n, INF);  
    vector<bool> visited(n, false); 

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

            if (dist[v] > dist[u] + weight) {
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
            }
        }
    }

    return dist;
}

int main() {
    int numVertices, numEdges;
    cin >> numVertices >> numEdges;

    vector<vector<pii>> graph(numVertices + 1);

    for (int i = 1; i <= numEdges; i++) {
        int u, v, weight;
        cin >> u >> v >> weight;
        graph[u].push_back(make_pair(v, weight));  
    }

    int source, target;
    cin >> source >> target;

    vector<int> shortestDistances = dijkstra(graph, source, target);

    if (shortestDistances[target] != INF) {
        cout << shortestDistances[target] << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}
