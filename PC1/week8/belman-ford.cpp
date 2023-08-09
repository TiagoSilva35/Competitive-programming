#include <iostream>
#include <vector>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

struct Edge {
    int destination;
    int weight;
};

vector<int> bellmanFord(vector<vector<Edge>>& adjList, int numVertices, int source, int target) {
    vector<int> distance(numVertices, INF);
    distance[source] = 0;

    for (int i = 1; i <= numVertices - 1; i++) {
        for (int u = 0; u < numVertices; u++) {
            for (const auto& edge : adjList[u]) {
                int v = edge.destination;
                int w = edge.weight;
                if (distance[u] != INF && distance[v] > distance[u] + w) {
                    distance[v] = distance[u] + w;
                }
            }
        }
    }

    // Check for negative cycles
    for (int u = 0; u < numVertices; u++) {
        for (const auto& edge : adjList[u]) {
            int v = edge.destination;
            int w = edge.weight;
            if (distance[u] != INF && distance[v] > distance[u] + w) {
                // Negative cycle found
                return vector<int>(); // Return an empty vector to indicate a negative cycle
            }
        }
    }

    return distance;
}

int main() {
    int numVertices, numEdges, source, target;
    cin >> numVertices >> numEdges >> source >> target;

    vector<vector<Edge>> adjList(numVertices);
    for (int i = 0; i < numEdges; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adjList[u].push_back({v, w});
    }

    vector<int> distance = bellmanFord(adjList, numVertices, source, target);

    if (distance.empty()) {
        cout << "Negative cycle detected." << endl;
    } else if (distance[target] == INF) {
        cout << "No path from source to target." << endl;
    } else {
        cout << "Shortest distance from source to target: " << distance[target] << endl;
    }

    return 0;
}
