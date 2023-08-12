#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

#define INF numeric_limits<int>::max()

typedef pair<int, int> pii;

vector<int> dijkstra(vector<vector<pii>>& graph, int source, int target) {
    int n = graph.size();
    vector<int> dist(n, INF);  // Stores the shortest distances from the source vertex
    vector<bool> visited(n, false);  // Marks visited vertices

    dist[source] = 0;  // Distance from source to itself is 0

    // Create a priority queue (min-heap) to store vertices based on their distances
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push(make_pair(0, source));

    while (!pq.empty()) {
        int u = pq.top().second;  // Extract the vertex with minimum distance
        pq.pop();

        // If the vertex has already been visited, skip it
        if (visited[u]) {
            continue;
        }

        visited[u] = true;

        // If the target vertex is reached, terminate the loop
        if (u == target) {
            break;
        }

        // Explore all neighboring vertices of the current vertex
        for (auto& neighbor : graph[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;

            // Relax the edge (u, v) if a shorter path is found
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

    vector<vector<pii>> graph(numVertices);

    // Read the graph input
    for (int i = 0; i < numEdges; i++) {
        int u, v, weight;
        cin >> u >> v >> weight;
        graph[u].push_back(make_pair(v, weight));
        graph[v].push_back(make_pair(u, weight));  // Remove this line for a directed graph
    }

    int source, target;
    cin >> source >> target;

    // Run Dijkstra's algorithm
    vector<int> shortestDistances = dijkstra(graph, source, target);

    // Output the shortest distance from the source to the target vertex
    cout << "Shortest distance from " << source << " to " << target << ": ";
    if (shortestDistances[target] != INF) {
        cout << shortestDistances[target] << endl;
    } else {
        cout << "No path found." << endl;
    }

    return 0;
}
