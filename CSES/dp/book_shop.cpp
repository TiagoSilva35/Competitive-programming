#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1000000007;

int countArrays(vector<int>& x, int n, int m, int prev, int idx) {
    if (idx == n) {
        return 1;
    }
    int count = 0;
    if (x[idx] == 0 || x[idx] == prev + 1 || x[idx] == prev - 1) {
        for (int val = 1; val <= m; val++) {
            if (x[idx] == 0 || x[idx] == val) {
                count = (count + countArrays(x, n, m, val, idx + 1)) % MOD;
            }
        }
    }

    return count;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    int result = countArrays(x, n, m, 0, 0);
    cout << result << endl;

    return 0;
}
