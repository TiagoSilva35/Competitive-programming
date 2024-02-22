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
#define INF 2e18
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
 
vv memo(7,vi(1000001,-1));
 
int rec(int n, int cur_sum, int idx, vi &v) {
    if (memo[idx][cur_sum] != -1)
        return memo[idx][cur_sum];
 
    if (cur_sum == n)
        return 1;
    if (idx == 6 || cur_sum > n)
        return 0;
 
    int ways = 0;
    for (int i = 0; i < 6; i++) {
        ways += rec(n, cur_sum + v[i], i, v);
        ways %= MOD;
    }
 
    memo[idx][cur_sum] = ways;
    return ways;
}
 
void solve(){
    int n;
    cin >> n;
    vi v = {1,2,3,4,5,6};
    cout << rec(n,0,0,v) << endl;
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll t = 1;
    //cin >> t;
    for(int it=1;it<=t;it++) {
     //cout << "Case #" << it+1 << ": ";
        solve();
    }
    return 0;
}