#include <bits/stdc++.h>

using namespace std;

struct Edge {
    int destination, capacity;
};

bool bfs(vector<vector<Edge>>& graph, vector<int>& parent, int source, int sink) {
    int numVertices = graph.size();

    vector<bool> visited(numVertices, false);
    queue<int> q;
    q.push(source);
    visited[source] = true;
    parent[source] = -1;

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        for (auto edge : graph[current]) {
            int next = edge.destination;
            int capacity = edge.capacity;

            if (!visited[next] && capacity > 0) {
                q.push(next);
                parent[next] = current;
                visited[next] = true;
            }
        }
    }

    return visited[sink];
}

int findMaxFlow(vector<vector<Edge>>& graph, int source, int sink) {
    int numVertices = graph.size();

    vector<vector<int>> residualGraph(numVertices, vector<int>(numVertices, 0));
    for (int u = 0; u < numVertices; u++) {
        for (auto edge : graph[u]) {
            int v = edge.destination;
            residualGraph[u][v] = edge.capacity;
        }
    }

    vector<int> parent(numVertices);

    int maxFlow = 0;

    while (bfs(graph, parent, source, sink)) {
        int pathFlow = INT_MAX;
        int u = sink;

        while (u != source) {
            int v = parent[u];
            pathFlow = min(pathFlow, residualGraph[v][u]);
            u = v;
        }

        u = sink;
        while (u != source) {
            int v = parent[u];
            residualGraph[v][u] -= pathFlow;
            residualGraph[u][v] += pathFlow;
            u = v;
        }
        maxFlow += pathFlow;
    }

    return maxFlow;
}

int main() {
    int numVertices = 0;
    int source = 0;
    int sink = 0; 

    vector<vector<Edge>> graph(numVertices);

    int maxFlow = findMaxFlow(graph, source, sink);
    cout << maxFlow << endl;

    return 0;
}
