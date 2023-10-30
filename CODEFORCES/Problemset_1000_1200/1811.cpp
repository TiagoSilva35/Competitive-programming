
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

void solve(){
	ll n;
	cin >> n;
	vll v(n-1);
	vll ans;
	forn(i, n-1){
		cin >> v[i];
	}
	bool flag = true;
	forn(i,n-2){
		if (v[i] < v[i + 1]){
			if (flag){
				ans.pb(v[i] == 0 ? 0 : v[i] - 1);
				ans.pb(v[i]);
				flag = false;	
			}
			else{
				ans.pb(v[i]);
			}
		}
		else if (v[i] == v[i + 1]){
			if(flag){
				ans.pb(v[i]);
				ans.pb(v[i] > 0 ? v[i] - 1 : 0);
				i++;
		
			}
			else{
				ans.pb(v[i]);
			}
		}
		else{
			ans.pb(v[i]);
		}
	}

	if (flag && (ll)ans.size() < n){
		ans.pb(v[n-2] == 0 ? 0 : v[n-2] - 1);
		ans.pb(v[n-2]);
	}
	else{
		ans.pb(v[n-2]);
	}



	if ((ll)ans.size() > 0){
		cout << ans[0];
		for(int i = 1; i < n; i++){
			cout << " " << ans[i];
		}
		cout << endl;
	}

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
