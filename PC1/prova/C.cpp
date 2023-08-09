#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

typedef pair<int, pair<int, int>> pii;

int dijkstra(const vector<vector<char>>& grid, int n, int m) {
    vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    vector<pair<int, int>> starting_positions;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'a') {
                starting_positions.push_back({i, j});
            }
        }
    }

    for (const auto& pos : starting_positions) {
        int row = pos.first;
        int col = pos.second;
        dist[row][col] = 0;
        pq.push({0, {row, col}});
    }

    while (!pq.empty()) {
        int row = pq.top().second.first;
        int col = pq.top().second.second;
        int distance = pq.top().first;
        pq.pop();

        if (grid[row][col] == '#') {
            return distance;
        }

        vector<pair<int, int>> neighbors = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (const auto& neighbor : neighbors) {
            int new_row = row + neighbor.first;
            int new_col = col + neighbor.second;

            if (new_row >= 0 && new_row < n && new_col >= 0 && new_col < m) {
                int new_distance = (grid[new_row][new_col] == '#') ? 1 : abs(grid[new_row][new_col] - grid[row][col]);

                if (distance + new_distance < dist[new_row][new_col]) {
                    dist[new_row][new_col] = distance + new_distance;
                    pq.push({dist[new_row][new_col], {new_row, new_col}});
                }
            }
        }
    }

    return -1;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<char>> grid(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    int result = dijkstra(grid, n, m);
    cout << result << endl;

    return 0;
}


