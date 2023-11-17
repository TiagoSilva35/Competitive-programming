
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
vector <vector<ll>>memo(1001,vector<ll>(1001,-1));

ll change(ll idx,ll N, vector <ll> val){
	if (N == 0){
		memo[idx][N] = 1;
		return 1;
	}
	if (N < 0 || idx < 0){
		return 0;
	}
	if(memo[idx][N] > -1){
		return memo[idx][N];
	}
	if(val[idx] > N){
		memo[idx][N] = change(idx-1,N,val);
	}
	else
		memo[idx][N] = change(idx,N-val[idx],val) + change(idx-1,N,val);
	return memo[idx][N];
}
void solve(){
	ll n;
	cin >> n;
	ll sum = n*(n+1)/2;
	vll v(n);
	iota(all(v), 1);
	if (sum & 1){
		cout << 0 << endl;
		return;
	
	}
	cout << change(n, sum/2, v) << endl;
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
