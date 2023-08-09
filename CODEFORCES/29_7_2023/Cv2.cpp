#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int pos = 0, neg = 0;
    for (int i = 0; i < n; i++) {
        pos += a[i] > 0;
        neg += a[i] < 0;
    }

    int id = 0;
    if (neg + 5 <= 12 and pos > 0) while (a[id] <= 0) id++;
    else if (pos + 5 <= 12 and neg > 0) while (a[id] >= 0) id++;
    else for (int i = 0; i < n; i++) if (abs(a[i]) > abs(a[id])) id = i;

    vector<pair<int,int>> ops;
    if (min(pos, neg) + 5 <= 12) ops = vector<pair<int,int>>(5, {id, id});

    for (int i = 0; i < n; i++) if (a[i] * a[id] < 0) ops.emplace_back(i, id);

    if (a[id] >= 0) for (int i = 1; i < n; i++) ops.emplace_back(i, i-1);
    else for (int i = n-2; i >= 0; i--) ops.emplace_back(i, i+1);

    cout << ops.size() << "\n";
    for (auto pp: ops) cout << pp.first+1 << " " << pp.second+1 << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
}
