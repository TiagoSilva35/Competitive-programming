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

vector<vector<int>> memo(1000001, vector<int>(1000001, -1));

ll rec(ll n, ll sum, ll idx) {
    if (sum == n) {
        return 1;
    }
    if (sum > n) {
        return 0;
    }
    if (memo[idx][sum] != -1) {
        return memo[idx][sum];
    }
    int ans = 0;
    for (int i = 1; i <= 6; i++) {
        ans += rec(n, sum + i, i+1);
        ans %= MOD;
        memo[idx][sum] = ans;
    }
    return ans;
}

void solve(){
    ll N;
    cin >> N;
    cout << rec(N,0,1) << endl;
    
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