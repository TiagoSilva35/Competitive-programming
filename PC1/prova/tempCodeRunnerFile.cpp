#include <iostream>
#include <vector>
#include <queue>
#include <limits>
using namespace std;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;
#define MAX 1005
#define INF 0x3f3f3f3f

int n, m;
char grid[MAX][MAX];
int dist[MAX][MAX];
bool visited[MAX][MAX];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
priority_queue<piii, vector<piii>, greater<piii>> pq;

bool isValid(int x, int y) {
    return (x >= 0 && x < n && y >= 0 && y < m);
}

void dijkstra(pii start) {
    dist[start.first][start.second] = 0;
    pq.push(make_pair(0, start));
    while (!pq.empty()) {
        pii v = pq.top().second;
        pq.pop();
        if (visited[v.first][v.second]) continue;
        visited[v.first][v.second] = true;
        for (int i = 0; i < 4; i++) {
            int x = v.first + dx[i];
            int y = v.second + dy[i];
            if (isValid(x, y) && !visited[x][y]) {
                int w;
                if (grid[x][y] == '#') w = 1;
                else w = abs(grid[x][y] - grid[v.first][v.second]);
                if (dist[v.first][v.second] + w < dist[x][y]) {
                    dist[x][y] = dist[v.first][v.second] + w;
                    pq.push(make_pair(dist[x][y], make_pair(x, y)));
                }
            }
        }
    }
}

int main() {
    cin >> n >> m;
    pii start;
    vector<pii> ends;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'a') start = make_pair(i, j);
            if (grid[i][j] == '#') ends.push_back(make_pair(i, j));
            dist[i][j] = INF;
        }
    }
    dijkstra(start);
    int ans = INF;
    for (pii end : ends) ans = min(ans, dist[end.first][end.second]);
    cout << ans << "\n";
    return 0;
}
