#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1000000007;

vector<vector<int>> memo;

int countWays(int N, int sum) {
    if (sum < 0) return 0;
    if (N == 0) return (sum == 0) ? 1 : 0;
    if (memo[N][sum] != -1) return memo[N][sum];

    int ways = countWays(N - 1, sum - N) % MOD;
    ways = (ways + countWays(N - 1, sum)) % MOD; 

    memo[N][sum] = ways;
    return ways;
}

int main() {
    int N;
    cin >> N;

    // Initialize memoization table with -1
    memo.resize(N + 1, vector<int>(N * (N + 1) / 2 + 1, -1));

    int sum = N * (N + 1) / 2;
    if (sum % 2 == 1) {
        cout << 0 << endl; // Cannot distribute equally
    } else {
        int ways = countWays(N - 1, sum / 2);
        cout << ways << endl;
    }

    return 0;
}

