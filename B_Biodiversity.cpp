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

bool compare(pair<string, int> a, pair<string, int>b){
    return a.second > b.second;
}

void solve() {
    // Problem solving code goes here
    int n;cin >> n;
    map<string, int>m;
    for(int i = 0; i < n; ++i){
        string a;cin >> a;
        m[a]++;
    }
    vector<pair<string,int>> v(m.begin(), m.end());
    sort(v.begin(), v.end(), compare);
    pair<string, int> mx = v[0];
    cout << (mx.second > n/2 ? mx.first : "NONE");
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // Code execution begins here
    solve();
    return 0;
}