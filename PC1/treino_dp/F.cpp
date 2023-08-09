#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 100, MAXM = 300;
int n, m;
vector<pair<int, int>> pasta[MAXN + 1];
ll dp[MAXN + 1][MAXM + 1];

ll solve(int i, int t) {
    if(i > n || t <= 0) return 0;

    if(dp[i][t] != -1) return dp[i][t];

    ll res = 0;
    res = max(res, solve(i + 1, t));

    for(auto p : pasta[i]) {
        if(p.first <= t)
            res = max(res, p.second + solve(i + 1, t - p.first));
    }

    dp[i][t] = res;
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            int id, time, taste;
            cin >> id >> time >> taste;
            pasta[id].push_back({time, taste});
        }
    }

    memset(dp, -1, sizeof dp);

    cout << solve(1, m) << '\n';

    return 0;
}
