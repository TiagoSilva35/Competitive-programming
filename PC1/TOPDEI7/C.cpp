#include <bits/stdc++.h>

using namespace std;

#define lli long long int

lli rec(vector<vector<char>>& grid, int r, int c, int x, int y, vector<vector<lli>>& memo) {
    if (x <= 0 || y <= 0 || x > r || y > c) {
        return 0;
    }
    if (memo[x][y] != 0) {
        return memo[x][y];
    }
    if (grid[x][y] == 'A') {
        return 0;
    }

    lli ans = 0;
    if (grid[x][y] == 'T') {
        ans = 1;
        ans += rec(grid, r, c, x + 1, y, memo);
        ans += rec(grid, r, c, x - 1, y, memo);
        ans += rec(grid, r, c, x, y + 1, memo);
        ans += rec(grid, r, c, x, y - 1, memo);
    } else {
        ans = max(ans, rec(grid, r, c, x + 1, y, memo));
        ans = max(ans, rec(grid, r, c, x - 1, y, memo));
        ans = max(ans, rec(grid, r, c, x, y + 1, memo));
        ans = max(ans, rec(grid, r, c, x, y - 1, memo));
    }

    memo[x][y] = ans;
    return ans;
}

int main() {
    lli r, c;
    cin >> r >> c;
    vector<vector<char>> grid(r+10, vector<char>(c+10));
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            cin >> grid[i][j];
        }
    }
    vector<vector<lli>> memo(1000, vector<lli>(1000, 0));
    lli ans = 0;
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            ans = max(ans, rec(grid, r, c, i, j, memo));
        }
    }
    cout << ans << endl;
    return 0;
}

