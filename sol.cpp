#include <iostream>
#include <vector>
#include <string>

using namespace std;
typedef long long ll;

void solve() {
    string s;
    cin >> s;

    if (s.back() < s[0]) {
        cout << 0 << endl;
        return;
    }

    int n = s.length();
    vector<ll> caminhos(n, 0);
    caminhos[n - 1] = 1;

    for (int i = n - 2; i >= 0; --i) {
        char current_char = s[i];
        for (int j = i + 1; j < n; ++j) {
            if (s[j] >= current_char) {
                caminhos[i] += caminhos[j];
            }
        }
        
        // Check for early termination
        if (current_char > s[n - 1]) {
            caminhos[i] = 0;  // Set the count to 0 and continue
        }
    }

    cout << caminhos[0] << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    cin >> t;

    for (int it = 1; it <= t; it++) {
        solve();
    }

    return 0;
}
