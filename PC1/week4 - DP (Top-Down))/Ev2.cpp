#include <bits/stdc++.h> 
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vector<int> > vv;
typedef vector<vector<ll> > vvll;
typedef vector<vector<pii> > vvpii;
typedef vector<pll> vpll;
typedef vector<pii> vpii;
ll MOD = 998244353;
double eps = 1e-12;
#define forn(i,e) for(ll i = 0; i < e; i++)
#define forsn(i,s,e) for(ll i = s; i < e; i++)
#define rforn(i,s) for(ll i = s; i >= 0; i--)
#define rforsn(i,s,e) for(ll i = s; i >= e; i--)
#define ln "\n"
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
#define lli long long int
using namespace std;

#include <iostream>
#include <vector>
using namespace std;


#include <iostream>
#include <vector>
using namespace std;

#include <iostream>
#include <vector>
using namespace std;
#include <iostream>
#include <vector>
using namespace std;

#include <iostream>
#include <vector>
using namespace std;

long long max_val(int idx, vector<int>& values, vector<int>& weights, int W, int n, vector<vector<long long>>& memo) {
    if (idx == n || W == 0) {
        return 0;
    }
    if (memo[idx][W] != -1) {
        return memo[idx][W];
    }
    if (weights[idx] > W) {
        memo[idx][W] = max_val(idx + 1, values, weights, W, n, memo);
    }
    else {
        memo[idx][W] = max(max_val(idx + 1, values, weights, W, n, memo),
                           max_val(idx + 1, values, weights, W - weights[idx], n, memo) + values[idx]);
    }
    return memo[idx][W];
}

void solve() {
    int n;
    cin >> n;
    vector<int> values(n);
    vector<int> weights(n);
    vector<vector<long long>> memo(n, vector<long long>(31, -1));
    for (int i = 0; i < n; i++) {
        cin >> values[i] >> weights[i];
    }
    int g;
    cin >> g;
    vector<int> max_weights(g);
    for (int i = 0; i < g; i++) {
        cin >> max_weights[i];
    }
    long long result = 0;
    for (int i = 0; i < g; i++) {
        result += max_val(0, values, weights, max_weights[i], n, memo);
    }
    cout << result << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}




