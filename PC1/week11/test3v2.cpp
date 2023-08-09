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
 
int rec(int N, vi& v, vv& all_combs, vi& comb, int target, int& counter, vv& memo)
{
    if (target == 0 && N == 0)
    {
        vi temp(comb);
        all_combs.push_back(temp);
        counter++;
        counter %= 1000000007;
        return 1;
    }
    if (N == 0 || target < 0)
        return 0;

    if (memo[N][target] != -1)
        return memo[N][target];

    int result = 0;
    for (int i = 0; i < (int)v.size(); i++)
    {
        comb.push_back(v[i]);
        result += rec(N - 1, v, all_combs, comb, target - v[i], counter, memo);
        comb.pop_back();
        result %= 1000000007;
    }

    memo[N][target] = result;
    return result;
}



void solve(){
    // N DADOS COM M FACES E TARGET = K
    int N, M, K;
    cin >> N >> M >> K;
    vi u(M);
    for (int i = 0; i < M; i++)
    {
        u[i] = i + 1;
    }
    vv all_combs;
    vi comb;
    int counter = 0;
    vv memo(N + 1, vi(K + 1, -1));
    rec(N, u, all_combs, comb, K, counter, memo);
    cout << counter << ln;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    for (int it = 1; it <= t; it++) {
        // cout << "Case #" << it << ": ";
        solve();
    }
    return 0;
}
