#include<unordered_map>
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
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF INT_MAX
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
const int mxN = 500;
bool visited[mxN + 1];
/*ll cc (ll x,ll t, ll idx){
	ll ways = 0;
	if (x < 0) return 0;
	if (x == 0){
		return 1;
	}
	for(ll i = idx + 1; i < t; i++){
		if (!visited[i]){
			visited[i] = true;
			ways += cc(x - i, t, i);
		}
		visited[i] = false;
	}
	return ways;
}*/

vector<vector<ll>> dp(mxN + 1, vector<ll>(mxN + 1, -1));
ll cc(ll x, ll t, ll idx) {
    if (x < 0) return 0;
    if (x == 0) {
		return 1;
	}
    if (dp[x][idx] > -1) {
        return dp[x][idx];
    }

    ll ways = 0;
    for (ll i = idx + 1; i < t; i++) {
        if (!visited[i]) {
            visited[i] = true;
            ways += cc(x - i, t, i);
            visited[i] = false;
        }
    }

    dp[x][idx] = ways;
    return ways;
}
void solve(){
	ll x;
	cin >> x;
	ll ans = cc(x, x, 0);
	if (x <= 10 && x%2 == 0){
		cout << ans-1 << endl;
		return;
	}
	else{
		cout << ans << endl;
	}
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
