#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int N, M;
        cin >> N >> M;

        vector<int> obj(N);
        for (int i = 0; i < N; ++i) {
            cin >> obj[i];
        }

        vector<vector<int>> adj(M);
        for (int i = 0; i < M; ++i) {
            int O;
            cin >> O;
            adj[i].resize(O);
            for (int j = 0; j < O; ++j) {
                cin >> adj[i][j];
            }
        }

        vector<vector<int>> dp(N + 1, vector<int>(M + 1, INF));
        dp[0][0] = 0;

        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= M; ++j) {
                dp[i][j] = dp[i][j - 1]; // Option 1: Don't visit this location
                for (int item : adj[j - 1]) {
                    if (item == obj[i - 1]) {
                        dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + 1); // Option 2: Visit this location
                        break;
                    }
                }
            }
        }

        int ans = INF;
        for (int j = 1; j <= M; ++j) {
            ans = min(ans, dp[N][j]);
        }

        cout << (ans < INF ? ans : -1) << endl;
    }
}


