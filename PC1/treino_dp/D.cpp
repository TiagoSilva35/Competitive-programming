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
ll MOD = 1000000007;
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
#define INF INT_MAX
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

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

void solve() {
    int N;
    cin >> N;

    memo.resize(N + 1, vector<int>(N * (N + 1) / 2 + 1, -1));

    int sum = N * (N + 1) / 2;
    if (sum % 2 == 1) {
        cout << 0 << endl;
    } else {
        int ways = countWays(N - 1, sum / 2);
        cout << ways << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t = 1;
    for (int it = 1; it <= t; it++) {
        // cout << "Case #" << it + 1 << ": ";
        solve();
    }
    return 0;
}