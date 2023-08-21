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

ll n,x;
vll w;
ll ans = 0;

void solve(){
	cin >> n >> x;
	w.resize(n);
	ll sum = 0;
	forn(i,n){cin >> w[i];sum+=w[i];}
	sort(all(w));
	ll l = 0, r = n-1;
	ll flag = 0;
	while(flag < sum && r >= l){
		//cout << flag << "/" << sum << endl;
		if (w[l] + w[r] <=x){
			//cout << "h " << w[l]  << " " << w[r] << endl; 
			ans++;
			l++;
			r--;
			flag = flag + w[l] + w[r];
		}
		else{
			//cout << "h2 " << l  << w[r] << endl;
			ans++;
			r--;
			flag += w[r];
		}
	}
	cout << ans << endl;
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
