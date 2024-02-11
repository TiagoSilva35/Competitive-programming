#include <bits/stdc++.h> 
 
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define INF INT_MAX
 

const int di[] = {1, 0, -1, 0};
const int dj[] = {0, -1, 0, 1};


int n;
int m;
vector<string> matrix;

map<pair<int, int>, char> AED;
map<pair<int, int>, pair<pair<int,int>, char>> parent;

bool valid(ll i, ll j){
  return i >= 0 && j >= 0 && i < n && j < m && (matrix[i][j] == '.' || matrix[i][j] == 'B');
}

vector<char> path;
int dijkstra(pair<int, int> target, pair<int, int> start) {
    vector<vector<int>> dist(n+1, vector<int>(m+1, INF));
    vector<vector<bool>> visited(n+1, vector<bool>(m+1, false));
    dist[start.first][start.second] = 0;
    
    priority_queue<pair<int,pii>, vector<pair<int, pii>>, greater<pair<int, pii>>> pq;
    pq.push({0, {start.first, start.second}});
    while (!pq.empty()) {
      int curX = pq.top().second.first;
        int curY = pq.top().second.second;
        pq.pop();
        if (visited[curX][curY]) {
            continue;
        }
        visited[curX][curY] = true;
        if (curX == target.first && curY == target.second) {
            break;
        }
        vector<pair<int, int>> neigh = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        for (auto neighbour: neigh) {
            int newR = curX + neighbour.first;
            int newC = curY + neighbour.second;
            if (valid(newR, newC) && dist[newR][newC] > dist[curX][curY] + 1) {
                dist[newR][newC] = dist[curX][curY] + 1;
                pq.push({dist[newR][newC],{newR, newC}});
                path.push_back(AED[neighbour]);
                parent[{newR, newC}] = {{curX, curY}, AED[neighbour]};
            }
        }
    }
    return dist[target.first][target.second];
}

void solve(){
    AED[{0, 1}] = 'R';
    AED[{0, -1}] = 'L';
    AED[{1, 0}] = 'D';
    AED[{-1, 0}] = 'U';
    
    cin >> n >> m;
    string row;
    pair<int, int> start, end;

    for(int i = 0; i < n; ++i){
        cin >> row;
        matrix.push_back(row);
        
        for(int j = 0; j < m; ++j){
            if (row[j] == 'A'){
                start = {i, j};
            }
            if (row[j] == 'B'){
                end = {i, j};
            }
        }
    }
    int shortest = dijkstra(end, start);
    if(shortest == INF){
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl << shortest << endl;
    
    pair<int, int> cur = end;
    string path = "";
    while(cur != start){
        path += parent[cur].second;
        cur = parent[cur].first;
    }
    reverse(path.begin(), path.end());
    cout << path << endl;

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

