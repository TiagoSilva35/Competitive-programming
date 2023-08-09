#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int MAX_N = 14;
int dp[MAX_N][MAX_N];

int maxHappiness(vector<vector<int>>& happiness, int n, int curFriend, int visited) {
    if (curFriend == n) {
        return 0;
    }

    if (dp[curFriend][visited] != -1) {
        return dp[curFriend][visited];
    }

    int maxHap = 0;
    for (int i = 0; i < n; ++i) {
        if (!(visited & (1 << i))) {
            maxHap = max(maxHap, happiness[curFriend][i] + maxHappiness(happiness, n, curFriend + 1, visited | (1 << i)));
        }
    }

    return dp[curFriend][visited] = maxHap;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        vector<vector<int>> happiness(N, vector<int>(N));
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                cin >> happiness[i][j];
            }
        }

        memset(dp, -1, sizeof(dp));
        int ans = maxHappiness(happiness, N, 0, 0);
        cout << ans << endl;
    }

    return 0;
}
