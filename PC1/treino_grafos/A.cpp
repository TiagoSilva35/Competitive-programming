#include <bits/stdc++.h>

using namespace std;

struct Position {
    int row;
    int col;
};

const int MAX_N = 2001;

int n, q;
char grid[MAX_N][MAX_N];
int visited[MAX_N][MAX_N];
const int di[] = {1, 0, -1, 0};
const int dj[] = {0, -1, 0, 1};
int t = 0;

bool valid(int i, int j, char c) {
    return i >= 0 && j >= 0 && i < n && j < n && grid[i][j] == c;
}

bool dfs(int row, int col, char c) {
    visited[row][col] = t;
    for (int k = 0; k < 4; k++) {
        int ni = row + di[k];
        int nj = col + dj[k];
        if (valid(ni, nj, c) && visited[ni][nj] == -1) {
            dfs(ni, nj, c);
        }
    }
    return false;
}

void solve() {
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    memset(visited, -1, sizeof(visited));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (visited[i][j] == -1){
                dfs(i,j,grid[i][j]);
                t++;
            }
        }
            
    }
    while (q--) {
        int start_i, start_j, target_i, target_j;
        cin >> start_i >> start_j >> target_i >> target_j;
        if (visited[start_i][start_j] == visited[target_i][target_j])cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}


