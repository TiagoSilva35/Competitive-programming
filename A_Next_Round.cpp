#include <iostream>
#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstring>
#include <functional>
#include <iomanip>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <vector>
using namespace std;
#define INF INT_MAX
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

void solve() {
    int n,k;cin >> n >> k;
    vector<int> vi(n);
    for (int i = 0; i < n; ++i){
        cin >> vi[i];
    }
    int mx = vi[k-1];
    int ans = 0;
    for (int i = 0; i < n; ++i){
        if (vi[i] >= mx && vi[i]) ans++;
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}