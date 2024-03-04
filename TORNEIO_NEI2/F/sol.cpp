#include <bits/stdc++.h> 
 
using namespace std;
typedef long long ll;
 
vector<vector<ll>> dist;
vector<vector<ll>> dist2;

vector<vector<char>> grid;
queue<pair<ll, ll>> q;
ll N;
string out;
#define pii pair<int, int>
ll msf = 0;
bool possible = false;
bool advPath = false;
 
const int di[] = {1, 0, -1, 0};
const int dj[] = {0, -1, 0, 1};
 
 
bool valid(ll i, ll j){
    return i >= 0 && j >= 0 && i < N && j < N && grid[i][j] != '#';
}
 

void bfs2(){
    ll curDist = 0;
    while(!q.empty()){
        pair<ll, ll> cur = q.front(); q.pop();   
        curDist = dist2[cur.first][cur.second];
 
        for(int k = 0; k < 4; k++){
            pair<ll, ll> next = {cur.first + di[k], cur.second + dj[k]};
 
            if((valid(next.first, next.second) && (curDist + 1 < dist2[next.first][next.second]))){
                dist2[next.first][next.second] = curDist + 1;
                if (dist2[next.first][next.second] < dist[next.first][next.second]){
                    q.push(next);
                    msf = dist[next.first][next.second];
                }
            }

        }

    }
}

void bfs(){
    ll curDist = 0;
    while(!q.empty()){
        pair<ll, ll> cur = q.front(); q.pop();   
        curDist = dist[cur.first][cur.second];
 
        for(int k = 0; k < 4; k++){
            pair<ll, ll> next = {cur.first + di[k], cur.second + dj[k]};
 
            if((valid(next.first, next.second) && (curDist + 1 < dist[next.first][next.second]))){
                dist[next.first][next.second] = curDist + 1;
                q.push(next);
            }
        }

    }
}


void solve(){
    cin >> N;
    pii garg, start, end;
    grid.resize(N, vector<char>(N));
    dist.resize(N, vector<ll>(N, INT_MAX));
    dist2.resize(N, vector<ll>(N, INT_MAX));

    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            cin >> grid[i][j];
            if (grid[i][j] == 'G'){
                q.push({i, j});
                garg = {i, j};
            }
            else if (grid[i][j] == 'S'){
                start = {i, j};
            }
            else if (grid[i][j] == 'E'){
                end = {i, j};
            }
        }
    }
    dist[garg.first][garg.second] = 0;
    bfs();
    advPath = true;
    q.push(start);
    
    dist2[start.first][start.second] = 0;

    bfs2();
    msf = min(msf, min(dist[end.first][end.second], dist[start.first][start.second]));
    cout << (msf == INT_MAX ? 0 : msf) << endl;

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
