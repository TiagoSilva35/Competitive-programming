#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;
const int MAX_N = 31;
const int MAX_K = 601;

int memo[MAX_N][MAX_K];

int rec(int N, int M, int K, int sum) {
    if (N == 0) {
        return sum >= K;
    }

    if (memo[N][sum] != -1) {
        return memo[N][sum];
    }

    int result = 0;
    for (int i = 1; i <= M; i++) {
        result += rec(N - 1, M, K, sum + i);
        result %= MOD;
    }

    memo[N][sum] = result;
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int N, M, K;
        cin >> N >> M >> K;

        memset(memo, -1, sizeof(memo));

        int result = rec(N, M, K, 0);
        cout << result << endl;
    }

    return 0;
}
