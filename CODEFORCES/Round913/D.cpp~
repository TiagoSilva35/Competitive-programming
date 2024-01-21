
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

bool good(vpll segs, ll n, ll k){
	ll l = 0;
	ll rr = 0;
   	for (auto e: segs){
    	l = max(l - k, e.first);
        rr = min(rr + k, e.second);
        if (l > rr)
        	return false;
	}
    return true;
}
void solve(){
	ll n; cin >> n;
	vpll segs(n);
	forn(i,n){cin >> segs[i].first >> segs[i].second;}
	ll lb = -1;ll rb = 1;
	while(!good(segs, n, rb)){
		rb*=2;
	}
	while(rb > lb + 1){
		ll mb = lb + (rb-lb)/2;
		if (good(segs, n ,mb)){
			rb = mb;
		}
		else{
			lb = mb;
		}
	}
	cout << lb + 1 << endl;

}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll t = 1;
    cin >> t;
    for(int it=1;it<=t;it++) {
        //cout << "Case #" << it+1 << ": ";
        solve();
    }
    return 0;
}
