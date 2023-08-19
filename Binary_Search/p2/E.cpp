#include <bits/stdc++.h> 
#include <cmath>
#include <cstddef>
#include <iomanip>

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

ld c;

auto good(ld x)->bool{
	return (pow(x,2.0)) + sqrt(x) >= c;
}

void solve(){
	cin >> c;
	ld l = 0.0,r = 1.0;
	while(!good(r))r*=2;
	for(size_t i = 0 ; i < 100 ; i++){
		ld m = l + (r-l)/2;
		if (good(m))
			r = m;
		else
			l = m;
	}
	cout << setprecision(16) << r << endl;
		
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
