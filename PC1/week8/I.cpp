#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
#include <algorithm>

using namespace std;

#define INF INT_MAX

vector<int> dijkstra(vector<vector<int>>& graph, int source) {
    int n = graph.size();
    vector<int> dist(n+1, INF);  

    dist[source] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, source});

    while (!pq.empty()) {
        int u = pq.top().second;  
        int d = pq.top().first;
        pq.pop();

        if (d > dist[u]) {
            continue;
        }

        for (auto neighbor : graph[u]) {
            int v = neighbor;

            if (dist[v] > dist[u] + 1) {
                dist[v] = dist[u] + 1;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}

int main() {
    int n;
    while(cin >> n){
        int ANS = INT_MAX;
        vector<vector<int>> graph(n+1);
        for (int i = 1; i <= n; i++) {
            int times;
            cin >> times;
            for (int j = 1; j <= times; j++) {
                int v;
                cin >> v;
                graph[i].push_back(v); 
            } 
        }
        
        int maior = 0;
        vector<int> shortestDistances = dijkstra(graph, 1);
        for (int i = 1; i <= n; i++) {
            if (shortestDistances[i] < INF) {
                int temp = maior;
                maior = max(maior, static_cast<int>(graph[i].size()));

                if (temp != maior && maior > static_cast<int>(graph[1].size())) {
                    ANS = min(ANS, shortestDistances[i]);
                }
            }
        }

        
        if (maior > static_cast<int>(graph[1].size())) {
            if (ANS != INT_MAX)
                cout << ANS << endl;    
            else
                cout << "King of popularity!" << endl;
        } else {
            cout << "King of popularity!" << endl;
        }
    }

    return 0;
}
